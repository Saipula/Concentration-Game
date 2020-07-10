// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include "settings.h"
#include "class.h"
#include <ctime>
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

Game game;
int last = 0, last2 = 0;
float TimeInGame = 0;
bool pause = 0;

stat easy, medium, hard;

// ---------------------------------------------------------------------------
//Конструктор формы
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
	TImage *images[36], *im[36]; //Создание 2х массивов для заполнения массивов в классах

	for (int i = 0; i < 36; i++) {
		images[i] = new TImage(this);
		images[i]->Parent = this;
		images[i]->Width = 64;
		images[i]->Height = 64;
		images[i]->Left = i / 6 * 70 + 200;
		images[i]->Top = i % 6 * 70 + 100;
		images[i]->Tag = i + 1;
		images[i]->OnClick = KnopochkaClick;     //Присваивание события
		images[i]->Stretch = true;               //Авторозтягивание картинки
		images[i]->Visible = false;

		game.images[i] = images[i];              //Загрузка основного массива

		im[i] = new TImage(this);
		im[i]->Parent = this;
		im[i]->Stretch = true;
		im[i]->Visible = false;
		game.im[i] = im[i];                      //Загрузка невидимого массива
	}

	//Фон формы
	image->Align = alClient;
	image->Stretch = true;
}

//Настройки-------------------------------------------------------------------
void __fastcall TForm1::SettingsClick(TObject *Sender) {
	Form2->RadioGroup1->ItemIndex = game.sloshnost;
	Form2->RadioGroup2->ItemIndex = game.ImageNum;

	Timer2->Enabled = false;

	if (Form2->ShowModal() == mrOk) { // Изменение сложности
		int tmp = Form2->RadioGroup1->ItemIndex;
		if (game.sloshnost != tmp || game.ImageNum != Form2->RadioGroup2->ItemIndex) {
			game.sloshnost = tmp;

			if (game.ImageNum != Form2->RadioGroup2->ItemIndex) {
				game.ImageNum = Form2->RadioGroup2->ItemIndex;
				back(Sender);
			}

			game.newlvl();
			game.score = 0;
			Label1->Caption = "Difficulty: " + IntToStr(game.sloshnost + 1);
			Label3->Caption = "Score: " + IntToStr(game.score);

			NextClick(Sender);
		}
	}
	else
		Timer2->Enabled = true;

}

//Рестрарт--------------------------------------------------------------------
void __fastcall TForm1::RestartClick(TObject *Sender) {

	if (!game.Vin)
		if (game.sloshnost == 0) easy.add(TimeInGame, game.score, 0);
		else if (game.sloshnost == 1) medium.add(TimeInGame, game.score, 0);
		else if (game.sloshnost == 2) hard.add(TimeInGame, game.score, 0);

	game.restart(); // Перезапустить этот лвл
	game.ShowAll(1);
	Timer1->Enabled = false;
	Timer2->Enabled = false;
	Timer1->Enabled = true;
	TimeInGame = 0;
	game.score = 0;
	Label2->Caption = "Time in game: " + FloatToStr(TimeInGame);
	Label3->Caption = "Score: " + IntToStr(game.score);
	pause = 1;

	game.Vin = false;

	//Отключаются элементы MainMenu
	Restart->Enabled = false;
	Settings->Enabled = false;
	Pause->Enabled = false;

	//Если сложность тяжёлая, таймер подольше)
	if (game.sloshnost == 2)
		Timer1->Interval = 8000;
	else
		Timer1->Interval = 5000;
}

//Проверка двух последних нажатий---------------------------------------------
void __fastcall TForm1::KnopochkaClick(TObject *Sender)
{
	if (!pause) {
		TImage *im = static_cast<TImage*>(Sender);
		if (last == 0) {                //Нажатие по первой картинке
			last = im->Tag;

			if (game.compare(last)) {   //Если картинка открыта, то ничего небудет
				last = 0;
				return;
			}

			game.ShowImg1(last);
		}
		else if (last != 0) {            //Нажатие по второй картинке
			last2 = im->Tag;

			if (game.compare(last2)) {   //Если картинка открыта, то ничего небудет
				last2 = 0;
				return;
			}

			game.ShowImg1(last2);
			stoptime->Enabled = true;   //Включает таймер, для сравнения картинок
			pause = true;
		}
	}
}

//Следующий лвл---------------------------------------------------------------
void __fastcall TForm1::NextClick(TObject *Sender) {
	if (!game.Vin)
		if (game.sloshnost == 0) easy.add(TimeInGame, game.score, 0);
		else if (game.sloshnost == 1) medium.add(TimeInGame, game.score, 0);
		else if (game.sloshnost == 2) hard.add(TimeInGame, game.score, 0);

	game.newlvl();     //Следующий лвл
	game.ShowAll(1);   //Полазывает все картинки
	Timer1->Enabled = false;
	Timer2->Enabled = false;
	Timer1->Enabled = true;
	TimeInGame = 0;
	game.score = 0;
	Label2->Caption = "Time in game: " + FloatToStr(TimeInGame);
	Label3->Caption = "Score: " + IntToStr(game.score);
	pause = 1;         //Включение паузы

	game.Vin = false;

	//Отключаются элементы MainMenu
	Restart->Enabled = false;
	Settings->Enabled = false;
	Pause->Enabled = false;

	//Если сложность тяжёлая, таймер подольше)
	if (game.sloshnost == 2)
		Timer1->Interval = 8000;
	else
		Timer1->Interval = 5000;
}

//Показывает картинки перед игрой---------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender) {
	game.ShowAll(0);  //Закрывает все картинки
	Timer1->Enabled = false;
	pause = 0;        //Отключение паузы
	Timer2->Enabled = true;


	//Включаются элементы MainMenu
	Restart->Enabled = true;
	Settings->Enabled = true;
	Pause->Enabled = true;
}

//Кнопочка Старт--------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender) {
	Button1->Visible = false;
	Label1->Visible = true;
	Label2->Visible = true;
	Label3->Visible = true;
	Restart->Visible = true;
	Next->Visible = true;
	Settings->Visible = true;
	Stats->Visible = true;
	Pause->Visible = true;

	Label1->Caption = "Difficulty: " + IntToStr(game.sloshnost + 1);
	game.ImageNum = 0;


	game.kartinki[0] = kartinki;
	game.kartinki[1] = kartinki2;
	game.kartinki[2] = kartinki3;

	back(Sender);
	NextClick(Sender);
}

//Счётчик времени в игре------------------------------------------------------
void __fastcall TForm1::Timer2Timer(TObject *Sender) {
	TimeInGame += Timer2->Interval / 1000;
	Label2->Caption = "Time in game: " + FloatToStr(TimeInGame);
}

//Кнопочка пауза--------------------------------------------------------------
void __fastcall TForm1::PauseClick(TObject *Sender) {
	pause = !pause;
	Timer2->Enabled = !pause;
}

//Кнопочка статистика---------------------------------------------------------
void __fastcall TForm1::StatsClick(TObject *Sender)
{
	easyN2->Caption = "Games: " + IntToStr(easy.games);
	easyN3->Caption = "Vins: " + IntToStr(easy.vins);
	easyN4->Caption = "Score: " + IntToStr(easy.ShowInf(2));
	easyN5->Caption = "Time: " + IntToStr(easy.ShowInf(1));

	mediumN2->Caption = "Games: " + IntToStr(medium.games);
	mediumN3->Caption = "Vins: " + IntToStr(medium.vins);
	mediumN4->Caption = "Score: " + IntToStr(medium.ShowInf(2));
	mediumN5->Caption = "Time: " + IntToStr(medium.ShowInf(1));

	hardN2->Caption = "Games: " + IntToStr(hard.games);
	hardN3->Caption = "Vins: " + IntToStr(hard.vins);
	hardN4->Caption = "Score: " + IntToStr(hard.ShowInf(2));
	hardN5->Caption = "Time: " + IntToStr(hard.ShowInf(1));

}

//Таймер для отображения 2х откритых картинок---------------------------------
void __fastcall TForm1::stoptimeTimer(TObject *Sender)
{
	game.vibor(last, last2);
	last = 0;
	last2 = 0;
	stoptime->Enabled = false;

	Label3->Caption = "Score: " + IntToStr(game.score);
	if (game.Vin) {
		pause = true;
		Timer2->Enabled = !pause;


		ShowMessage("You Vin\nTime: " + FloatToStr(TimeInGame) +
			"\nScore: " + IntToStr(game.score));

		if (game.sloshnost == 0) easy.add(TimeInGame, game.score, 1);
		else if (game.sloshnost == 1) medium.add(TimeInGame, game.score, 1);
		else if (game.sloshnost == 2) hard.add(TimeInGame, game.score, 1);

		TimeInGame = 0;
		game.score = 0;

		Label2->Caption = "Time in game: " + FloatToStr(TimeInGame);
		NextClick(Sender);
	}
	else{
		pause = false;
	}

	Label3->Caption = "Score: " + IntToStr(game.score);
}

//Смена фона формы------------------------------------------------------------
void __fastcall TForm1::back(TObject *Sender){

	if (game.ImageNum == -1) {
		image->Picture->LoadFromFile("Фоны\\start.jpg");
	}
	else if (game.ImageNum == 0) {
		image->Picture->LoadFromFile("Фоны\\flovers.jpg");
		Label1->Left = 672;
		Label1->Top = 8;
		Label1->Font->Color = clBlack;
		Label2->Left = 320;
		Label2->Top = 8;
		Label2->Font->Color = clBlack;
		Label3->Left = 320;
		Label3->Top = 40;
		Label3->Font->Color = clBlack;

		game.Start->x = 200;
		game.Start->y = 100;
	}
	else if (game.ImageNum == 1) {
		image->Picture->LoadFromFile("Фоны\\Eat.jpg");
		Label1->Left = 28;
		Label1->Top = 8;
		Label1->Font->Color = clLime;
		Label2->Left = 300;
		Label2->Top = 8;
		Label2->Font->Color = clLime;
		Label3->Left = 300;
		Label3->Top = 40;
		Label3->Font->Color = clLime;

		game.Start->x = 28;
		game.Start->y = 100;
	}
	else if (game.ImageNum == 2) {
		image->Picture->LoadFromFile("Фоны\\sport2.jpg");
		Label1->Left = 672;
		Label1->Top = 8;
		Label1->Font->Color = clLime;
		Label2->Left = 320;
		Label2->Top = 8;
		Label2->Font->Color = clLime;
		Label3->Left = 320;
		Label3->Top = 40;
		Label3->Font->Color = clLime;

		game.Start->x = 200;
		game.Start->y = 100;
	}
}

//---------------------------------------------------------------------------


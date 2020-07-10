// ---------------------------------------------------------------------------

#ifndef classH
#define classH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <vector>
// ---------------------------------------------------------------------------

class Game {
	int easy, medium, hard;  //Количество элементов в уровне сложности

	bool TestPixels(TCanvas *canv1, TCanvas *canv2, int size);
	void SetPos();

public:
	//Конструктор
	Game() {
		easy = 8;
		medium = 16;
		hard = 36;
		score = 0;
		Vin = 0;
		ImageNum = -1;
		sloshnost = 0;
		Start = new TPoint(200, 100);
	}

	TPoint *Start;

	//Было использовано 2 массива (1 сверху с серыми квадратами или откритыми, а
	//второй нижний, невидимый, с котором и сравнивается верхий или второй откритый
	//элемент массива)
	TImage *images[36]; // Массив с серыми квадратами
	TImage *im[36]; // Массив с картинками
	int sloshnost, score, ImageNum;  //Сложность, очки, и № набора картинок
	TImageList *kartinki[3];  //Наборы картинок
	bool Vin;


	//Прототипы функций
	void restart();
	void visible();
	void vibor(int a1, int a2);
	void newlvl();
	void ShowImg1(int a1);
	void ShowAll(int num);
	bool compare(int a1);

    //Звгрузка картинок в зависимости от номера набора
	void loadim() {
        srand(time(NULL));
		for (int i = 0; i < hard; i++) {
			im[i]->Picture->Bitmap->TransparentMode=tmAuto;
			kartinki[ImageNum]->GetBitmap(i / 2 + 1, im[i]->Picture->Bitmap);
			kartinki[ImageNum]->GetBitmap(0, images[i]->Picture->Bitmap);
		}
	}
	bool chek();
};


//Класс для статистики
class stat{
public:
	int games, vins;
	std::vector<int> scors;
	std::vector<int> time;

	stat(){          //Конструктор
		games = 0; vins = 0;
	}

	//Записывание игры
	void add(int Time, int Score, bool vin){
		games++;
		if (vin) vins++;
		time.push_back(Time);
		scors.push_back(Score);
	}

	//Вывод среднего значения очков/времени
	int ShowInf(int num){
		if (games == 0) return 0;
		int tmp = 0;
		if (num == 1) {
			for (int i = 0; i < games; i++) {
				tmp += time[i];
			}
			return tmp/games;
		}
		else if(num == 2){
			for (int i = 0; i < games; i++) {
				tmp += scors[i];
			}
			return tmp/games;
		}
	}
};


#endif

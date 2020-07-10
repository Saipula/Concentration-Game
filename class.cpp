// ---------------------------------------------------------------------------

#pragma hdrstop

#include "class.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

//Проверяет открыта ли картинка при нажатии на неё
bool Game::compare(int a1){
	if (!TestPixels(im[a1-1]->Canvas, images[a1-1]->Canvas, images[0]->Width))
		return false;
	return true;
}

// Преверят, не победил ли ты (Если все картинки откриты, возвращает true))
bool Game::chek() {
	if (sloshnost == 0) {
		for (int i = 0; i < easy; i++) {
			if (!TestPixels(im[i]->Canvas, images[i]->Canvas, images[i]->Width))
				return false;
		}
	}
	else if (sloshnost == 1) {
		for (int i = 0; i < medium; i++) {
			if (!TestPixels(im[i]->Canvas, images[i]->Canvas, images[i]->Width))
				return false;
		}
	}
	else if (sloshnost == 2) {
		for (int i = 0; i < hard; i++) {
			if (!TestPixels(im[i]->Canvas, images[i]->Canvas, images[i]->Width))
				return false;
		}
	}
	return true;
}

// Проверка двух центральный рядов картинки на соответствие
bool Game::TestPixels(TCanvas *canv1, TCanvas *canv2, int size) {
	for (int i = 0; i < size; i++) {
		if (canv1->Pixels[i][size / 2] != canv2->Pixels[i][size / 2])
			return false;
	}
	return true;
}

// Переигривание
void Game::restart() {
	SetPos();
	visible();
}

// Видимость в зависимости от уровня сложности
void Game::visible() {
	for (int i = 0; i < 36; i++) {
		if (sloshnost == 0) {
			if (i < easy) {
				images[i]->Visible = false;
				images[i]->Visible = true;
			}
			else
				images[i]->Visible = false;
		}
		else if (sloshnost == 1) {
			if (i < medium) {
				images[i]->Visible = false;
				images[i]->Visible = true;
			}
			else
				images[i]->Visible = false;
		}
		else if (sloshnost == 2) {
			images[i]->Visible = false;
			images[i]->Visible = true;
		}
	}
}

// Проверка 2х последних картинок
void Game::vibor(int a1, int a2) {
	if (a1 != a2) {
		if (TestPixels(im[a1 - 1]->Canvas, im[a2 - 1]->Canvas,
			images[a1 - 1]->Width)) {
			score += 5;

			if (chek()) {
				Vin = 1;
			}
		}
		else {
			kartinki[ImageNum]->GetBitmap(0, images[a1 - 1]->Picture->Bitmap);
			kartinki[ImageNum]->GetBitmap(0, images[a2 - 1]->Picture->Bitmap);
			visible();
			score -= 2;
		}
	}
}

// Отображает 1 картинку
void Game::ShowImg1(int a1) {
	images[a1 - 1]->Picture->Bitmap = im[a1 - 1]->Picture->Bitmap;
	visible();
}

// Новая игра
void Game::newlvl() {
	loadim();
	restart();

	if (sloshnost == 0) {
		for (int i = 0; i < easy; i++) {
			std::swap(im[i]->Picture, im[rand() % easy]->Picture);
		}
	}
	else if (sloshnost == 1) {
		for (int i = 0; i < medium; i++) {
			std::swap(im[i]->Picture, im[rand() % medium]->Picture);
		}
	}
	else {
		for (int i = 0; i < hard; i++) {
			std::swap(im[i]->Picture, im[rand() % hard]->Picture);
		}
	}
}

// Изменение позиции картинок в зависимости от сложности
void Game::SetPos() {
	if (sloshnost == 0) {
		for (int i = 0; i < easy; i++) {
			images[i]->Width = 64 + 6;
			images[i]->Height = 64 + 6;
			images[i]->Left = i / 2 * (images[i]->Width + 6) + Start->x + 70;
			images[i]->Top = i % 2 * (images[i]->Width + 6) + Start->y + 70;
		}
	}
	else if (sloshnost == 1) {
		for (int i = 0; i < medium; i++) {
			images[i]->Width = 64 + 6;
			images[i]->Height = 64 + 6;
			images[i]->Left = i / 4 * (images[i]->Width + 6) + Start->x + 70;
			images[i]->Top = i % 4 * (images[i]->Width + 6) + Start->y + 70;
		}
	}
	else if (sloshnost == 2) {
		for (int i = 0; i < hard; i++) {
			images[i]->Width = 64;
			images[i]->Height = 64;
			images[i]->Left = i / 6 * 70 + Start->x;
			images[i]->Top = i % 6 * 70 + Start->y;
		}
	}
}

// Отображение всех картинок открирыми/закритыми
void Game::ShowAll(int num) {
	if (num == 1)
		for (int i = 0; i < hard; i++)
			images[i]->Picture->Bitmap = im[i]->Picture->Bitmap;
	else
		for (int i = 0; i < hard; i++)
			kartinki[ImageNum]->GetBitmap(0, images[i]->Picture->Bitmap);

	visible();
}


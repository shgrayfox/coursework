#pragma once
#include <iostream>
#include <string>
using namespace std;
class OZ : public COUNTRY {
	static OZ* self;
	static int refcount;
protected:
	OZ() { printf("Singleton::Singleton \n"); }
	~OZ() { printf("Singleton::~Singleton \n"); }
public:
	ofstream file;
	static OZ* Instance() {
		if (!self)
			self = new OZ();
		refcount++;
		return self;
	}
	void out() {
		file.open("OZ.txt");
		file << "Название страны: " << cntryname << endl;
		file << "Количество государств: " << num_states << endl;
		for (int i = 0; i < num_states; ++i) {
			file << i + 1 << "\tНазвание:\t" << statename[i] << endl;
			file << "\tФлаг:\t\t" << flag[i] << endl;
			file << "\tСтолица:\t" << capital[i] << endl;
			file << "\tГлава государства: " << statehead[i] << endl;
		}
		file << "Упоминания в книгах и фильмах: " << mention << endl;
		file << "Климат: " << climate << endl;
		if (magic == 1)
			file << "Магия: используется" << endl;
		else file << "Магия: не используется" << endl;
		file << "Расы: " << races << endl;
		file << "Мифические существа: " << creatures << endl << endl << endl;
		file.close();
	};
	void create() {
		cntryname = "Страна Оз";
		num_states = 5;
		statename[0] = "Зеленая страна"; statename[1] = "Фиолетовая страна"; statename[2] = "Голубая страна"; statename[3] = "Желтая страна"; statename[4] = "Розовая страна";
		capital[0] = "Изумрудный город"; capital[1] = "Фиолетовый город"; capital[2] = "Голубой город"; capital[3] = "Желтый город"; capital[4] = "Розовый город";
		statehead[0] = "Волшебник Оз"; statehead[1] = "Бастинда"; statehead[2] = "Гингема"; statehead[3] = "Виллина"; statehead[4] = "Стелла";
		mention = "серии книг Лаймена Ф. Бауна: Удивительный волшебник из страны Оз, А.М. Волкова: Волшебник Изумрудного города";
		climate = "равнинный, горный, теплый, вечное лето";
		magic = 1;
		races = "волшебницы, люди, мигуны, жевуны, болтуны, прыгуны, гномы";
		creatures = "волшебницы, летучие обезьяны, мигуны, жевуны, болтуны, прыгуны, гномы";
	};
	void FreeInst() { refcount--; if (!refcount) { delete this; self = NULL; } }
};
OZ* OZ::self = NULL;
int OZ::refcount = 0;
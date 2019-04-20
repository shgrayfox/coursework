#pragma once
#include <iostream>
#include <string>
using namespace std;
class OZ : public COUNTRY {
	static OZ* self;
	static int refcount;
protected:
	OZ() {}
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
		file << "Название страны: \t\t" << cntryname << endl << endl;
		file << "Количество государств: \t\t" << num_states << endl;
		file << "#: " << "\tНазвание:" << "\tСтолица:" << "\tГлава государства:" << endl;
		for (int i = 0; i < num_states; ++i)
			file << i + 1 << "\t" << statename[i] << "\t" << capital[i] << "\t" << statehead[i] << endl;
		file << "Упоминания в книгах и фильмах: \t" << mention << endl;
		file << "Климат: \t\t\t" << climate << endl;
		if (magic == 1)
			file << "Магия:\t\t\t\tиспользуется" << magic << endl;
		else file << "Магия:\t\t\t\tне используется" << magic << endl;
		file << "Расы: \t\t\t\t" << races << endl;
		file << "Мифические существа: \t\t" << creatures << endl << endl << endl;
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
		races = "волшебницы, люди, летучие обезьяны, мигуны, жевуны, болтуны, прыгуны, гномы";
		creatures = "ведьмы, люди, летучие обезьяны, мигуны, жевуны, болтуны, прыгуны, гномы";
	};
	void FreeInst() { refcount--; if (!refcount) { delete this; self = NULL; } }
};
OZ* OZ::self = NULL;
int OZ::refcount = 0;
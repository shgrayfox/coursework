#pragma once
#include <iostream>
#include <string>
using namespace std;
class Vesteros : public COUNTRY {
	static Vesteros* self;
	static int refcount;
protected:
	Vesteros() { printf("Singleton::Singleton \n"); }
	~Vesteros() { printf("Singleton::~Singleton \n"); }
public:
	ofstream file;
	static Vesteros* Instance() {
		if (!self)
			self = new Vesteros();
		refcount++;
		return self;
	}
	void out() {
		file.open("Vest.txt");
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
		cntryname = "Вестерос";
		num_states = 8;
		statename[0] = "Север"; statename[1] = "Штормовые земли"; statename[2] = "Западные земли"; statename[3] = "Речные земли"; statename[4] = "Долина Аррен"; statename[5] = "Железные острова"; statename[6] = "Простор"; statename[7] = "Дорн";
		flag[0] = "лютоволк"; flag[1] = "олень"; flag[2] = "лев"; flag[3] = "рыба"; flag[4] = "орел"; flag[5] = "кракен"; flag[6] = "солнце"; flag[7] = "солнце и копье";
		capital[0] = "Винтерфелл"; capital[1] = "Штормовой предел"; capital[2] = "Кастерли"; capital[3] = "Риверран"; capital[4] = "Орлиное гнездо"; capital[5] = "Пайк"; capital[6] = "Хайгарден"; capital[7] = "Солнечное копье";
		statehead[0] = "Старки"; statehead[1] = "Баратеоны"; statehead[2] = "Ланнистеры"; statehead[3] = "Талли"; statehead[4] = "Аррены"; statehead[5] = "Грейджои"; statehead[6] = "Тиреллы"; statehead[7] = "Мартеллы";
		mention = "серия книг Дж.Мартина Мир Льда и Пламени, сериал Игра Престолов";
		climate = "непредсказуемая смена времен года, суровые зимы";
		magic = 1;
		races = "люди, андалы, ройнары, дорнийцы, железнорожденные, дети леса, великаны, иные, упыри";
		creatures = "дети леса, великаны, иные, упыри, драконы, единороги, сумеречный кот, лютоволк, мантикора, виверна";
	};
	void FreeInst() { refcount--; if (!refcount) { delete this; self = NULL; } }
};
Vesteros* Vesteros::self = NULL;
int Vesteros::refcount = 0;
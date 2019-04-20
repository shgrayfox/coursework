#pragma once
#include <iostream>
#include <string>
using namespace std;
class Vesteros : public COUNTRY {
	static Vesteros* self;
	static int refcount;
protected:
	Vesteros() {}
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
		file << "Название страны: \t\t" << cntryname << endl << endl;
		file << "Количество государств: \t\t" << num_states << endl;
		file << "#: " << "\tНазвание:" << "\tФлаг:" << "\tСтолица:" << "\tГлава государства:" << endl;
		for (int i = 0; i < num_states; ++i)
			file << i + 1 << " " << statename[i] << "\t" << flag[i] << "\t" << capital[i] << "\t" << statehead[i] << endl;
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
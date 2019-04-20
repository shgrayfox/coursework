#pragma once
#include <iostream>
#include <string>
using namespace std;
class MiddleEarth : public COUNTRY {
	static MiddleEarth* self;
	static int refcount;
protected:
	ofstream file;
	MiddleEarth() {}
	~MiddleEarth() { printf("Singleton::~Singleton \n"); }
public:
	static MiddleEarth* Instance() {
		if (!self)
			self = new MiddleEarth();
		refcount++;
		return self;
	}
	void create() {
		cntryname = "Средиземье";
		num_states = 9;
		statename[0] = "Мордор"; statename[1] = "Нуменор"; statename[2] = "Шир"; statename[3] = "Эребор"; statename[4] = "Арнор"; statename[5] = "Ангмар"; statename[6] = "Рохан"; statename[7] = "Гондор"; statename[8] = "Мория";
		flag[0] = "око Саурона"; flag[1] = "-"; flag[2] = "-"; flag[3] = "одинокая гора"; flag[4] = "звезда"; flag[5] = "корона и меч"; flag[6] = "конь"; flag[7] = "Белое дерево"; flag[8] = "-";
		capital[0] = "Барад-Дур"; capital[1] = "Андуниэ"; capital[2] = "Мичел Делвинг"; capital[3] = "Эребор"; capital[4] = "Аннуминас"; capital[5] = "Карн Дум"; capital[6] = "Эдорас"; capital[7] = "Минас-Тирит"; capital[8] = "Кхазад-дум";
		statehead[0] = "Саурон"; statehead[1] = "Амандин Элрос"; statehead[2] = "мэр Мичел Делвинга"; statehead[3] = "гномы"; statehead[4] = "Элендил"; statehead[5] = "Король-Чародей"; statehead[6] = "короли Марки"; statehead[7] = "люди"; statehead[8] = "династия Дарин";
		mention = "книги Дж.Р.Р.Толкина";
		climate = "плодородная земля, благоприятный, горный, также есть степи";
		magic = 1;
		races = "люди, орки, эльфы, гномы, хоббиты, волшебники, синдары, фалантримы";
		creatures = "орки, эльфы, гномы, хоббиты, волшебники синдары, фалантримы";
	};
	void out() {
		file.open("MidEr.txt");
		file << "Название страны: \t\t" << cntryname << endl << endl;
		file << "Количество государств: \t\t" << num_states << endl;
		file << "#: " << "Название:" << "\tФлаг:" << "\tСтолица:" << "\tГлава государства:" << endl;
		for (int i = 0; i < num_states; ++i)
			file << i + 1 << " " << statename[i] << "\t" << flag[i] << "\t\t" << capital[i] << "\t\t" << statehead[i] << endl;
		file << "Упоминания в книгах и фильмах: \t" << mention << endl;
		file << "Климат: \t\t\t" << climate << endl;
		if (magic == 1)
			file << "Магия:\t\t\t\tиспользуется" << endl;
		else file << "Магия:\t\t\t\tне используется" << endl;
		file << "Расы: \t\t\t\t" << races << endl;
		file << "Мифические существа: \t\t" << creatures << endl << endl << endl;
		file.close();
	};
	void FreeInst() { refcount--; if (!refcount) { delete this; self = NULL; } }
};
MiddleEarth* MiddleEarth::self = NULL;
int MiddleEarth::refcount = 0;
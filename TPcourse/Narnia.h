#pragma once
#include <iostream>
#include <string>
using namespace std;
class Narnia : public COUNTRY {
	static Narnia* self;
	static int refcount;
protected:
	ofstream file;
	Narnia() {}
	~Narnia() { printf("Singleton::~Singleton \n"); }
public:
	static Narnia* Instance() {
		if (!self)
			self = new Narnia();
		refcount++;
		return self;
	}
	void out() {
		file.open("Narnia.txt");
		file << "Название страны: \t\t" << cntryname << endl << endl;
		file << "Количество государств: \t\t" << num_states << endl;
		file << "#: " << "\tНазвание:" << "\tФлаг:" << "\tСтолица:" << "\tГлава государства:" << endl;
		for (int i = 0; i < num_states; ++i)
			file << i + 1 << "\t" << statename[i] << "\t" << flag[i] << "\t" << capital[i] << "\t" << statehead[i] << endl;
		file << "Упоминания в книгах и фильмах: \t" << mention << endl;
		file << "Климат: \t\t\t" << climate << endl;
		if (magic == 1)
			file << "Магия:\t\t\t\tиспользуется" << magic << endl;
		else file << "Магия:\t\t\t\tне используется" << magic << endl;
		file << "Расы: \t\t\t\t" << races << endl;
		file << "Мифические существа: \t\t" << creatures << endl << endl << endl;
	};
	void create() {
		cntryname = "Нарния";
		num_states = 2;
		statename[0] = "Нарния";
		statename[1] = "Нарния";
		flag[0] = "-";
		capital[0] = "-";
		statehead[0] = "Каспиан";
		mention = "серия книг Нарния";
		climate = "Климат";
		magic = 1;
		races = "люди";
		creatures = "говорящие животные, фавны, гномы";
		file.close();
	};
	void FreeInst() { refcount--; if (!refcount) { delete this; self = NULL; } }
};
Narnia* Narnia::self = NULL;
int Narnia::refcount = 0;
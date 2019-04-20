#pragma once
#include <iostream>
#include <string>
using namespace std;
class Atlant : public COUNTRY {
	static Atlant* self;
	static int refcount;
protected:
	ofstream file;
	Atlant() {}
	~Atlant() { printf("Singleton::~Singleton \n"); }
public:
	static Atlant* Instance() {
		if (!self)
			self = new Atlant();
		refcount++;
		return self;
	}
	void create() {
		cntryname = "Атлантида";
		num_states = 1;
		statename[0] = "-";
		flag[0] = "-";
		capital[0] = "-";
		statehead[0] = "-";
		mention = "Мифы";
		climate = "влажный";
		magic = 1;
		races = "люди";
		creatures = "-";
	};
	void out() {
		file.open("Atlant.txt");
		file << "Название страны: \t" << cntryname << endl << endl;
		file << "Количество государств: \t" << num_states << endl;
		file << "#: " << "\tНазвание:" << "\tФлаг:" << "\tСтолица:" << "\tГлава государства:"  << endl;
		for (int i = 0; i < num_states; ++i)
			file << i + 1 << "\t" << statename[i] << "\t" << flag[i] << "\t" << capital[i] << "\t" << statehead[i] << endl;
		file << "Упоминания в книгах и фильмах: " << mention << endl;
		file << "Климат: \t\t" << climate << endl;
		if (magic == 1)
			file << "Магия:\t\t\t\tиспользуется" << magic << endl;
		else file << "Магия:\t\t\t\tне используется" << magic << endl;
		file << "Расы: \t\t\t" << races << endl;
		file << "Мифические существа: \t\t" << creatures << endl << endl << endl;
		file.close();
	};
	void FreeInst() { refcount--; if (!refcount) { delete this; self = NULL; } }
};
Atlant* Atlant::self = NULL;
int Atlant::refcount = 0;
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
		statename[0] = "Атлантида";
		flag[0] = "черный кракен";
		capital[0] = "Атлантида";
		statehead[0] = "Атлант, Рама";
		mention = "Мифы Древней Греции, роман Двадцать тысяч лье под водой, Д.Колосов Атланты и др.";
		climate = "влажный";
		magic = 0;
		races = "атланты";
		creatures = "атланты";
	};
	void out() {
		file.open("Atlant.txt");
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
	void FreeInst() { refcount--; if (!refcount) { delete this; self = NULL; } }
};
Atlant* Atlant::self = NULL;
int Atlant::refcount = 0;
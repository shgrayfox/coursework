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
		statename[0] = "Мордор"; statename[1] = "Мордор"; statename[2] = "Мордор"; statename[3] = "Мордор"; statename[4] = "Мордор"; statename[5] = "Мордор"; statename[6] = "Мордор"; statename[7] = "Мордор"; statename[8] = "Мордор";
		flag[0] = "-"; flag[1] = "-"; flag[2] = "-"; flag[3] = "-"; flag[4] = "-"; flag[5] = "-"; flag[6] = "-"; flag[7] = "-"; flag[8] = "-";
		capital[0] = "Мордор"; capital[1] = "Мордор"; capital[2] = "Мордор"; capital[3] = "Мордор"; capital[4] = "Мордор"; capital[5] = "Мордор"; capital[6] = "Мордор"; capital[7] = "Мордор"; capital[8] = "Мордор";
		statehead[0] = "Саурон"; statehead[1] = "Саурон"; statehead[2] = "Саурон"; statehead[3] = "Саурон"; statehead[4] = "Саурон"; statehead[5] = "Саурон"; statehead[6] = "Саурон"; statehead[7] = "Саурон"; statehead[8] = "Саурон";
		mention = "-";
		climate = "-";
		magic = 1;
		races = "орки, эльфы, гномы, хоббиты, волшебники";
		creatures = "орки, эльфы, гномы, хоббиты, волшебники";
	};
	void out() {
		file.open("MidEr.txt");
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
		file.close();
	};
	void FreeInst() { refcount--; if (!refcount) { delete this; self = NULL; } }
};
MiddleEarth* MiddleEarth::self = NULL;
int MiddleEarth::refcount = 0;
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
		cntryname = "Страна Оз";
		num_states = 1;
		statename[0] = "Страна Оз";
		flag[0] = "-";
		capital[0] = "Изумрудный город";
		statehead[0] = "-";
		mention = "серия книг Волшебник страны Оз";
		climate = "теплый";
		magic = 1;
		races = "ведьмы, люди, летучие обезьяны";
		creatures = "ведьмы, люди, летучие обезьяны";
		file.close();
	};
	void FreeInst() { refcount--; if (!refcount) { delete this; self = NULL; } }
};
OZ* OZ::self = NULL;
int OZ::refcount = 0;
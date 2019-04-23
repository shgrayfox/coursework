#pragma once
#include <iostream>
#include <string>
using namespace std;
class Narnia : public COUNTRY {
	static Narnia* self;
	static int refcount;
protected:
	ofstream file;
	Narnia() { printf("Singleton::Singleton \n"); }
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
		cntryname = "Нарния";
		num_states = 4;
		statename[0] = "Нарния"; statename[1] = "Орландия"; statename[2] = "Тархистан"; statename[3] = "Тельмаринское королевство";
		flag[0] = "Алый лев"; flag[1] = "крест"; flag[2] = "-"; flag[3] = "хищная птица";
		capital[0] = "Кэр-Параваль"; capital[1] = "Анвард"; capital[2] = "Ташбаан"; capital[3] = "Тельмар";
		statehead[0] = "Сьюзен, Люси, Эдмунд, Питер"; statehead[1] = "Лун, Кор";	statehead[2] = "Тисрок, Рабадаш"; statehead[3] = "Каспиан";
		mention = "серия книг Клайва С. Льюиса: Хроники Нарнии";
		climate = "равнинный, горный, благоприятный";
		magic = 1;
		races = "люди, говорящие животные, фавны, гномы, колдуньи, великаны, дриады, пегасы, сатиры, наяды";
		creatures = "говорящие животные, фавны, гномы, колдуньи, великаны, дриады, пегасы, сатиры, наяды";
		
	};
	void FreeInst() { refcount--; if (!refcount) { delete this; self = NULL; } }
};
Narnia* Narnia::self = NULL;
int Narnia::refcount = 0;
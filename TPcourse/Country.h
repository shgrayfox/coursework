#pragma once
#include <iostream>
#include <string>
using namespace std;

class COUNTRY {
protected:
	virtual ~COUNTRY() {} //гарантируем удаление только через FreeInst()
	string cntryname = "-";
	int num_states = 10;
	string statename[10] = { "-", "-", "-", "-", "-", "-", "-", "-", "-", "-" };
	string flag[10] = { "-", "-", "-", "-", "-", "-", "-", "-", "-", "-" };
	string capital[10] = { "-", "-", "-", "-", "-", "-", "-", "-", "-", "-" };
	string statehead[10] = { "-", "-", "-", "-", "-", "-", "-", "-", "-", "-" };
	string mention = "-";
	string climate = "-";
	bool magic = 0;
	string races = "-";
	string creatures = "-";
public:
	virtual void out() {
		cout << "Название страны: \t\t" << cntryname << endl << endl;
		cout << "Количество государств: \t\t" << num_states << endl;
		for (int i = 0; i < num_states; ++i)
			cout << i + 1 << "\tНазвание: " << statename[i] << " \tФлаг: " << flag[i] << " \tСтолица: " << capital[i] << " \tГлава государства: " << statehead[i] << endl;
		cout << "Упоминания в книгах и фильмах: \t" << mention << endl;
		cout << "Климат: \t\t\t" << climate << endl;
		cout << "Магия: \t\t\t\t" << magic << endl;
		cout << "Расы: \t\t\t\t" << races << endl;
		cout << "Мифические существа: \t\t" << creatures << endl << endl << endl;
	};
	virtual void create() {};
	virtual void FreeInst() { delete this; }
};

class CTRY {
	COUNTRY *cntr[5];
	int ind;
public:
	CTRY() { cntr[0] = NULL; cntr[1] = NULL; cntr[2] = NULL; cntr[3] = NULL; cntr[4] = NULL; ind = 0; }
	~CTRY() { 
		for (int i = 0; i<ind; i++) 
			cntr[i]->FreeInst(); 
	}
	void Add(COUNTRY *p) { if (ind<5) cntr[ind++] = p; }
	void Do() {
		for (int i = 0; i < ind; i++) { cntr[i]->create(); cntr[i]->out();};
	}
};

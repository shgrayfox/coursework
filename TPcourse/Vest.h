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
		file << "�������� ������: \t\t" << cntryname << endl << endl;
		file << "���������� ����������: \t\t" << num_states << endl;
		file << "#: " << "\t��������:" << "\t����:" << "\t�������:" << "\t����� �����������:" << endl;
		for (int i = 0; i < num_states; ++i)
			file << i + 1 << "\t" << statename[i] << "\t" << flag[i] << "\t" << capital[i] << "\t" << statehead[i] << endl;
		file << "���������� � ������ � �������: \t" << mention << endl;
		file << "������: \t\t\t" << climate << endl;
		if (magic == 1)
			file << "�����:\t\t\t\t������������" << magic << endl;
		else file << "�����:\t\t\t\t�� ������������" << magic << endl;
		file << "����: \t\t\t\t" << races << endl;
		file << "���������� ��������: \t\t" << creatures << endl << endl << endl;
	};
	void create() {
		cntryname = "��������";
		num_states = 1;
		statename[0] = "-";
		flag[0] = "-";
		capital[0] = "-";
		statehead[0] = "-";
		mention = "-";
		climate = "-";
		magic = 0;
		races = "-";
		creatures = "-";
		file.close();
	};
	void FreeInst() { refcount--; if (!refcount) { delete this; self = NULL; } }
};
Vesteros* Vesteros::self = NULL;
int Vesteros::refcount = 0;
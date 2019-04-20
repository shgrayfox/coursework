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
		cntryname = "���������";
		num_states = 1;
		statename[0] = "-";
		flag[0] = "-";
		capital[0] = "-";
		statehead[0] = "-";
		mention = "����";
		climate = "�������";
		magic = 1;
		races = "����";
		creatures = "-";
	};
	void out() {
		file.open("Atlant.txt");
		file << "�������� ������: \t" << cntryname << endl << endl;
		file << "���������� ����������: \t" << num_states << endl;
		file << "#: " << "\t��������:" << "\t����:" << "\t�������:" << "\t����� �����������:"  << endl;
		for (int i = 0; i < num_states; ++i)
			file << i + 1 << "\t" << statename[i] << "\t" << flag[i] << "\t" << capital[i] << "\t" << statehead[i] << endl;
		file << "���������� � ������ � �������: " << mention << endl;
		file << "������: \t\t" << climate << endl;
		if (magic == 1)
			file << "�����:\t\t\t\t������������" << magic << endl;
		else file << "�����:\t\t\t\t�� ������������" << magic << endl;
		file << "����: \t\t\t" << races << endl;
		file << "���������� ��������: \t\t" << creatures << endl << endl << endl;
		file.close();
	};
	void FreeInst() { refcount--; if (!refcount) { delete this; self = NULL; } }
};
Atlant* Atlant::self = NULL;
int Atlant::refcount = 0;
#pragma once
#include <iostream>
#include <string>
using namespace std;
class Atlant : public COUNTRY {
	static Atlant* self;
	static int refcount;
protected:
	ofstream file;
	Atlant() { printf("Singleton::Singleton \n"); }
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
		statename[0] = "���������";
		flag[0] = "������ ������";
		capital[0] = "���������";
		statehead[0] = "������, ����";
		mention = "���� ������� ������, ����� �������� ����� ��� ��� �����, �.������� ������� � ��.";
		climate = "�������";
		magic = 0;
		races = "�������";
		creatures = "�������";
	};
	void out() {
		file.open("Atlant.txt");
		file << "�������� ������: " << cntryname << endl;
		file << "���������� ����������: " << num_states << endl;
		for (int i = 0; i < num_states; ++i) {
			file << i + 1 << "\t��������:\t" << statename[i] << endl;
			file << "\t����:\t\t" << flag[i] << endl;
			file << "\t�������:\t" << capital[i] << endl;
			file << "\t����� �����������: " << statehead[i] << endl;
		}
		file << "���������� � ������ � �������: " << mention << endl;
		file << "������: " << climate << endl;
		if (magic == 1)
			file << "�����: ������������" << endl;
		else file << "�����: �� ������������" << endl;
		file << "����: " << races << endl;
		file << "���������� ��������: " << creatures << endl << endl << endl;
		file.close();
	};
	void FreeInst() { refcount--; if (!refcount) { delete this; self = NULL; } }
};
Atlant* Atlant::self = NULL;
int Atlant::refcount = 0;
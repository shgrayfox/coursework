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
	void create() {
		cntryname = "������";
		num_states = 4;
		statename[0] = "������"; statename[1] = "��������"; statename[2] = "���������"; statename[3] = "������������� �����������";
		flag[0] = "���� ���"; flag[1] = "�����"; flag[2] = "-"; flag[3] = "������ �����";
		capital[0] = "���-��������"; capital[1] = "������"; capital[2] = "�������"; capital[3] = "�������";
		statehead[0] = "������, ����, ������, �����"; statehead[1] = "���, ���";	statehead[2] = "������, �������"; statehead[3] = "�������";
		mention = "����� ���� ������ �. ������: ������� ������";
		climate = "���������, ������, �������������";
		magic = 1;
		races = "����, ��������� ��������, �����, �����, ��������, ��������, ������, ������, ������, �����";
		creatures = "��������� ��������, �����, �����, ��������, ��������, ������, ������, ������, �����";
		
	};
	void FreeInst() { refcount--; if (!refcount) { delete this; self = NULL; } }
};
Narnia* Narnia::self = NULL;
int Narnia::refcount = 0;
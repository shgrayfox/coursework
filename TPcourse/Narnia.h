#pragma once
#include <iostream>
#include <string>
using namespace std;
class Narnia : public COUNTRY {
	static Narnia* self;
	static int refcount;
protected:
	ofstream file;
	Narnia() {}
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
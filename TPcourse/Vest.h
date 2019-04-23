#pragma once
#include <iostream>
#include <string>
using namespace std;
class Vesteros : public COUNTRY {
	static Vesteros* self;
	static int refcount;
protected:
	Vesteros() { printf("Singleton::Singleton \n"); }
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
		cntryname = "��������";
		num_states = 8;
		statename[0] = "�����"; statename[1] = "��������� �����"; statename[2] = "�������� �����"; statename[3] = "������ �����"; statename[4] = "������ �����"; statename[5] = "�������� �������"; statename[6] = "�������"; statename[7] = "����";
		flag[0] = "��������"; flag[1] = "�����"; flag[2] = "���"; flag[3] = "����"; flag[4] = "����"; flag[5] = "������"; flag[6] = "������"; flag[7] = "������ � �����";
		capital[0] = "����������"; capital[1] = "��������� ������"; capital[2] = "��������"; capital[3] = "��������"; capital[4] = "������� ������"; capital[5] = "����"; capital[6] = "���������"; capital[7] = "��������� �����";
		statehead[0] = "������"; statehead[1] = "���������"; statehead[2] = "����������"; statehead[3] = "�����"; statehead[4] = "������"; statehead[5] = "��������"; statehead[6] = "�������"; statehead[7] = "��������";
		mention = "����� ���� ��.������� ��� ���� � �������, ������ ���� ���������";
		climate = "��������������� ����� ������ ����, ������� ����";
		magic = 1;
		races = "����, ������, �������, ��������, ����������������, ���� ����, ��������, ����, �����";
		creatures = "���� ����, ��������, ����, �����, �������, ���������, ���������� ���, ��������, ���������, �������";
	};
	void FreeInst() { refcount--; if (!refcount) { delete this; self = NULL; } }
};
Vesteros* Vesteros::self = NULL;
int Vesteros::refcount = 0;
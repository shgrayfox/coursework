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
		cntryname = "����������";
		num_states = 9;
		statename[0] = "������"; statename[1] = "������"; statename[2] = "������"; statename[3] = "������"; statename[4] = "������"; statename[5] = "������"; statename[6] = "������"; statename[7] = "������"; statename[8] = "������";
		flag[0] = "-"; flag[1] = "-"; flag[2] = "-"; flag[3] = "-"; flag[4] = "-"; flag[5] = "-"; flag[6] = "-"; flag[7] = "-"; flag[8] = "-";
		capital[0] = "������"; capital[1] = "������"; capital[2] = "������"; capital[3] = "������"; capital[4] = "������"; capital[5] = "������"; capital[6] = "������"; capital[7] = "������"; capital[8] = "������";
		statehead[0] = "������"; statehead[1] = "������"; statehead[2] = "������"; statehead[3] = "������"; statehead[4] = "������"; statehead[5] = "������"; statehead[6] = "������"; statehead[7] = "������"; statehead[8] = "������";
		mention = "-";
		climate = "-";
		magic = 1;
		races = "����, �����, �����, �������, ����������";
		creatures = "����, �����, �����, �������, ����������";
	};
	void out() {
		file.open("MidEr.txt");
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
	void FreeInst() { refcount--; if (!refcount) { delete this; self = NULL; } }
};
MiddleEarth* MiddleEarth::self = NULL;
int MiddleEarth::refcount = 0;
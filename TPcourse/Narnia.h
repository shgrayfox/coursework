#pragma once
#include <iostream>
#include <string>
using namespace std;
class Narnia : public COUNTRY {
	static Narnia* self;
	static int refcount;
protected:
	Narnia() {}
	~Narnia() { printf("Singleton::~Singleton \n"); }
public:
	static Narnia* Instance() {
		if (!self)
			self = new Narnia();
		refcount++;
		return self;
	}
	void create() {
		cntryname = "������";
		num_states = 2;
		statename[0] = "������";
		statename[1] = "������";
		flag[0] = "-";
		capital[0] = "-";
		statehead[0] = "�������";
		mention = "����� ����";
		climate = "������";
		magic = 1;
		races = "����";
		creatures = "��������� ��������, �����, �����";
	};
	void FreeInst() { refcount--; if (!refcount) { delete this; self = NULL; } }
};
Narnia* Narnia::self = NULL;
int Narnia::refcount = 0;
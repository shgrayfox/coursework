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
	static Vesteros* Instance() {
		if (!self)
			self = new Vesteros();
		refcount++;
		return self;
	}
	void create() {
		cntryname = "Вестерос";
		num_states = 2;
		statename[0] = "-";
		flag[0] = "-";
		capital[0] = "-";
		statehead[0] = "-";
		mention = "-";
		climate = "-";
		magic = 1;
		races = "-";
		creatures = "-";
	};
	void FreeInst() { refcount--; if (!refcount) { delete this; self = NULL; } }
};
Vesteros* Vesteros::self = NULL;
int Vesteros::refcount = 0;
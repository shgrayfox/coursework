#pragma once
#include <iostream>
#include <string>
using namespace std;
class Atlant : public COUNTRY {
	static Atlant* self;
	static int refcount;
protected:
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
		cntryname = "Атлантида";
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
Atlant* Atlant::self = NULL;
int Atlant::refcount = 0;
#pragma once
#include <iostream>
#include <string>
using namespace std;
class OZ : public COUNTRY {
	static OZ* self;
	static int refcount;
protected:
	OZ() {}
	~OZ() { printf("Singleton::~Singleton \n"); }
public:
	static OZ* Instance() {
		if (!self)
			self = new OZ();
		refcount++;
		return self;
	}
	void create() {
		cntryname = "Страна Оз";
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
OZ* OZ::self = NULL;
int OZ::refcount = 0;
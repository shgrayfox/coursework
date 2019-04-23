#include <iostream>
#include "Country.h"
#include "MidEr.h"
#include "Narnia.h"
#include "Vest.h"
#include "OZ.h"
#include "Atlant.h"
using namespace std;
int main() {
	system("chcp 1251>nul");
	CTRY ctry;
	ctry.Add(MiddleEarth::Instance());
	ctry.Add(Narnia::Instance());
	ctry.Add(Vesteros::Instance());
	ctry.Add(OZ::Instance());
	ctry.Add(Atlant::Instance());
	ctry.Do();
	return 0;
}
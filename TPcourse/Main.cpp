//Определить класс «Страна».Базовый класс определяет интерфейс для построения стран, но они могут быть специализированы для конкретного(Средиземье, Нарния, Вестерос, Страна Оз, Атлантида).В каждой стране:
//сколько государств(описание флагов(текст), столица, глава государства(или несколько)), в каком фильме или книге упоминается, климат, наличие волшебства, какие расы населяют, какие мифические существа обитают. 
//Использовать паттерн «Одиночка».Результат записываeтся в отдельные выходные файлы.
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
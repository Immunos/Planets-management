#include <iostream>
#include <string>

#include "Planeta.h"
#include "Atmosfera.h"
#include "Powierzchnia.h"

using namespace std;

int main()
{
	string powitanie = "Program do zarzadzania planetami. Wersja 1.0";
	cout << powitanie << endl;
	cout << "==================================" << endl;
	Planeta p1("Mars", 1000000000, 5012, 10, 26, 280, "Brak", 5, 700, "Azot" );
	Planeta p2("Wenus", 100000000, 4213, 21, 13,112,"Brak", 7, 1400, "Siarkowodor");
	p1.dodaj_ksiezyc(123000, 902, 27);
	p2.dodaj_ksiezyc(190320, 1100, 12);
#ifdef _DEBUG
	test_wszystkiego(p1, p2);				// Funkcja testujaca wszystkie operatory i konstruktory
#endif
	return 0;
}
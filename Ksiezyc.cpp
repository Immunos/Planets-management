#include "Ksiezyc.h"



Ksiezyc::Ksiezyc()
{
#ifdef _DEBUG
	cout << "Uruchomiono konstruktor domyslny ksiezyca" << endl;
#endif
	
	masa = 0;
	czas_obiegu = 0;
	promien = 0;
}

Ksiezyc::Ksiezyc(long int masa, int promien, int czas_obiegu)
{
#ifdef _DEBUG
	cout << "Uruchomiono konstruktor z parametrami ksiezyca" << endl;
#endif
	this->masa = masa;
	this->promien = promien;
	this->czas_obiegu = czas_obiegu;
}
void Ksiezyc::wypisz_ksiezyc()
{
	cout << "Masa: " << masa << " t"<< endl;
	cout << "Promien: " << promien << " km" << endl;
	cout << "Okres obiegu: " << czas_obiegu << " dni" << endl;
}
ostream & operator<<(ostream & s, Ksiezyc & k)
{

	s << "Masa: " << k.masa << " t" << endl;
	s << "Promien: " << k.promien << " km" << endl;
	s << "Okres obiegu: " << k.czas_obiegu << " dni" << endl;
	return s;
}
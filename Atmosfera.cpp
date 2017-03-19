#include "Atmosfera.h"

void Atmosfera::wypisz_atmosfere()
{
	cout << "Zawartosc tlenu: " << zaw_tlenu << " %" << endl;
	cout << "Cisnienie: " << cisnienie << " hPa" << endl;
	cout << "Glowny skladnik atmosfery: " << glowny_skladnik << endl;
}

Atmosfera::Atmosfera()
{
#ifdef _DEBUG
	cout << "Uruchomiono konstruktor domyslny atmosfery" << endl;
#endif

	zaw_tlenu = 0;
	glowny_skladnik = "Brak";
	cisnienie = 0;
}

Atmosfera::Atmosfera(int zaw_tlenu, int cisnienie, string glowny_skladnik)
{
#ifdef _DEBUG
	cout << "Uruchomiono konstruktor z parametrami atmosfery" << endl;
#endif
	this->zaw_tlenu = zaw_tlenu;
	this->cisnienie = cisnienie;
	this->glowny_skladnik = glowny_skladnik;
}

ostream & operator<<(ostream & s, Atmosfera & a)
{
	s << "Zawartosc tlenu: " << a.zaw_tlenu << " %" << endl;
	s << "Cisnienie: " << a.cisnienie << " hPa" << endl;
	s << "Glowny skladnik atmosfery: " << a.glowny_skladnik << endl;
	return s;
}
#include "Powierzchnia.h"

Powierzchnia::Powierzchnia()
{
#ifdef _DEBUG
	cout << "Uruchomiono konstruktor domyslny powierzchni" << endl;
#endif

	sr_temperatura = 0;
	zycie = "Brak";
	dl_dnia = 0;
	dl_roku = 0;
}

Powierzchnia::Powierzchnia(int sr_temperatura, int dl_dnia, int dl_roku, string zycie)
{
#ifdef _DEBUG
	cout << "Uruchomiono konstruktor z parametrami powierzchni" << endl;
#endif
	this->sr_temperatura=sr_temperatura;
	this->dl_dnia = dl_dnia;
	this->dl_roku = dl_roku;
	this->zycie = zycie;
}

void Powierzchnia::wypisz_powierzchnie()
{
	cout << "Dlugosc dnia: " << dl_dnia << " h"<< endl;
	cout << "Dlugosc roku: " << dl_roku << " dni"<< endl;
	cout << "Srednia temperatura: " << sr_temperatura << " *C" << endl;
	cout << "Zycie: " << zycie << endl;
}

ostream & operator<<(ostream & s, Powierzchnia & p)
{
	s << "Dlugosc dnia: " << p.dl_dnia << " h" << endl;
	s << "Dlugosc roku: " << p.dl_roku << " dni" << endl;
	s << "Srednia temperatura: " << p.sr_temperatura << " *C" << endl;
	s << "Zycie: " << p.zycie << endl;
	return s;
}


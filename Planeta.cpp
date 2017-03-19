#include "Planeta.h"

int Planeta::nr_planety = 0;   // Inicjalizacja zmiennej statycznej

void Planeta::dodaj_ksiezyc(int masa, int promien, int czas_obiegu)
{
	ksiezyc = new Ksiezyc(masa, promien, czas_obiegu);
	liczba_ksiezycow++;
}

 int Planeta::ile_planet() 
{
	 return nr_planety;
}

void Planeta::wypisz_planete()					// Ta funkcja w zasadzie robi to samo co operator <<, ale na wszelki wypadek ja zostawilem
{
	cout << "========== Dane planety ==========" << endl;
	cout << "Nazwa: "<< nazwa << endl;
	cout << "Masa: " << masa <<" t" << endl;
	cout << "Promien: " << promien<<" km" << endl;
	atmosfera.wypisz_atmosfere();
	powierzchnia.wypisz_powierzchnie();
	for (int i = 1; i <= liczba_ksiezycow; i++)
	{
		cout << endl;
		cout << "Ksiezyc nr " << i << endl;
		ksiezyc[i-1].wypisz_ksiezyc();
		cout << endl;
	}
	cout << "==================================" << endl;
}



Planeta::Planeta(string nazwa, long int masa, int promien, int sr_temperatura, int dl_dnia, int dl_roku, string zycie,
	int zaw_tlenu, int cisnienie, string glowny_skadnik)                   
{																				// Chcialem zrobic jeden konstruktor, ktory by stworzyl Planete
#ifdef _DEBUG																	// wraz z podobiektami wg zadanych parametrow. Nie bardzo wiedzialem
	cout << "Uruchomiono konstruktor z parametrami planety" << endl;			// jak to zrobic, wiec wymyslilem cos takiego. Nie jest to idealne, bo 
#endif																			// powstaja nadlibczbowe podobiekty (robione przez konstruktor domyslny),
	this->nazwa = nazwa;														// ale brak mi lepszego pomys³u.
	this->masa = masa;
	this->promien = promien;
	this->powierzchnia=Powierzchnia(sr_temperatura, dl_dnia, dl_roku, zycie);
	this->atmosfera=Atmosfera(zaw_tlenu, cisnienie, glowny_skadnik);

}

Planeta::Planeta()												
{
#ifdef _DEBUG
	cout << "Uruchomiono konstruktor domyslny planety" << endl;
#endif

	nr_planety++;
	nazwa = "No name";
	masa = 0;
	promien = 0;
	liczba_ksiezycow = 0;

}
Planeta::~Planeta()												
{
#ifdef _DEBUG
	cout << "Uruchomiono destruktor domyslny planety" << endl;
#endif
	if(ksiezyc!=NULL)
	delete []ksiezyc;
}

Planeta::Planeta(const Planeta &p)								// Chyba wreszcie dziala tak jak powinien
{
#ifdef _DEBUG
	cout << "Uruchomiono konstruktor kopiujacy planety" << endl;
#endif
	nazwa = p.nazwa;
	masa = p.masa;
	promien = p.promien;
	atmosfera = p.atmosfera;
	powierzchnia = p.powierzchnia;
	liczba_ksiezycow = p.liczba_ksiezycow;
	ksiezyc = new Ksiezyc[liczba_ksiezycow];
	for (int i = 0; i < liczba_ksiezycow; i++)
		ksiezyc[i] = p.ksiezyc[i];
	nr_planety++;

}

bool Planeta::operator==(const Planeta &p) 
{
	if (p.nazwa == nazwa && masa == p.masa && promien == p.promien && liczba_ksiezycow == p.liczba_ksiezycow)
		return true;
	else
		return false;

}


Planeta& Planeta::operator=(const Planeta &p)					//W przypadku podobiektow wystarczy skorzystac z domyslnego operatora przypisania, prawda?
{
	nazwa = p.nazwa;
	masa = p.masa;
	promien = p.promien;
	atmosfera = p.atmosfera;
	powierzchnia = p.powierzchnia;
	liczba_ksiezycow = p.liczba_ksiezycow;
	ksiezyc = new Ksiezyc[liczba_ksiezycow];
	
	for (int i = 0; i < liczba_ksiezycow; i++)
		ksiezyc[i] = p.ksiezyc[i];

	return *this;

}

bool Planeta::operator>(const Planeta & p)
{
	if (masa < p.masa && promien < p.promien)
		return false;
	else
		return true;
}

bool Planeta::operator<(const Planeta & p)
{
	if (masa > p.masa && promien > p.promien)
		return false;
	else
		return true;
}

Planeta Planeta::operator+(const Planeta & p)
{
	Planeta temp;
	temp.nazwa = p.nazwa;
	temp.masa = masa + p.masa;
	temp.promien = promien + p.promien;
	temp.atmosfera = atmosfera;										// Nie mialem pomyslu jak mozna dodac atmosfere do atmosfery 
	temp.powierzchnia = powierzchnia;								// albo powierzchnie do powierzchni.
	temp.liczba_ksiezycow = liczba_ksiezycow+p.liczba_ksiezycow;
	temp.ksiezyc = new Ksiezyc[temp.liczba_ksiezycow];

	for (int i = 0; i < liczba_ksiezycow; i++)						// Chcialem zeby planeta temp miala rowniez zsumowane ksiezyce
		temp.ksiezyc[i] = ksiezyc[i];
	for (int i = 0; i < p.liczba_ksiezycow;i++)
		temp.ksiezyc[i + liczba_ksiezycow] = p.ksiezyc[i];

	return temp;
}

bool Planeta::operator!=(const Planeta & p)
{
	if (nazwa != p.nazwa || masa != p.masa || promien != p.promien || liczba_ksiezycow!=p.liczba_ksiezycow)
		return true;
	else
		return false;
}

void Planeta::operator[](int numer)							// Najprostsze co mi sie wydawalo, to wypisanie danego ksiezyca
{
	if (numer > liczba_ksiezycow) 
		cout << "Niewlasciwy numer ksiezyca" << endl;
	else {
		cout << ksiezyc[numer];
	}
}

int Planeta::operator!()									// Nie mialem juz pomyslu na operator, wiec stwierdzilem, 
{															// ze skoro nie planeta, to ksiezyce.
	return liczba_ksiezycow;
}

Planeta::operator double()									// Nie wiem na co moznaby skonwertowac planete, ale operator dziala
{
	double x;
	x = (double)masa*(double)promien;
	return x;
}

ostream & operator<<(ostream & s, Planeta & p)
{
	s << "========== Dane planety ==========" << endl;
	s << "Nazwa: " << p.nazwa << endl;
	s << "Masa: " << p.masa << " t" << endl;
	s << "Promien: " << p.promien << " km" << endl;
	s << p.atmosfera;
	s << p.powierzchnia;
	for (int i = 1; i <= p.liczba_ksiezycow; i++)
	{
		s << endl;
		s << "Ksiezyc nr " << i << endl;
		s << p.ksiezyc[i - 1];
		s << endl;
	}
	s << "==================================" << endl;
	return s;
}
#ifdef _DEBUG
void test_wszystkiego(Planeta &p1, Planeta &p2)
{
	cout << "==============Test operatorow==============" << endl<<endl;
	cout << "1. Operator == " << endl;
	cout << "Porownujemy ze soba dwie, wczesniej utworzone planety" << endl;
	if (p1 == p2)
		cout << "Planety " << p1.nazwa << " i " << p2.nazwa << " sa takie same." << endl << endl;
	else
		cout << "Planety " << p1.nazwa << " i " << p2.nazwa << " sa rozne." <<endl<< endl;

	cout << "2. Operator = " << endl;
	cout << "Stworzono nowa planete i przypisano jej wartosci Wenus" << endl;
	Planeta p3 = p2;
	p3.wypisz_planete();
	cout << endl;

	cout << "3. Operator > " << endl;
	if (p1 > p2)
		cout << p1.nazwa << " jest wieksza/y" << endl;
	else
		cout << p1.nazwa << " jest mniejszy/a" << endl;
	cout << endl;

	cout << "4. Operator < " << endl;
	if (p1 < p2)
		cout << p2.nazwa << " jest wieksza/y" << endl;
	else
		cout << p2.nazwa << " jest mniejsza/y" << endl;
	cout << endl;
	
	cout << "5. Operator + " << endl;
	cout << "Nowa planeta jest suma dwoch poprzednich" << endl;
		p3 = p1 + p2;
		cout << p3;
	cout << endl;

	cout << "6. Operator != " << endl;
	if (p1 != p2)
		cout << "Planety " << p1.nazwa << " i " << p2.nazwa << " sa rozne." << endl;
	else
		cout << "Planety " << p1.nazwa << " i " << p2.nazwa << " sa takie same." << endl << endl;
	cout << endl;

	cout << "7. Operator [] " << endl;
	cout << "Wypisanie ksiezyca danej planety" << endl;
	p1[0];
	cout << endl;

	cout << "8. Operator ! " << endl;
	cout << "Wypisanie liczby ksiezycow danej planety" << endl;
	cout << "Liczba ksiezycow: " << !p1 << endl;
	cout << endl;

	cout << "9. Operator konwersji double() " << endl;

	double a = (double(p1));
	cout << "Przemnozony promien i masa wynosza: " << a <<endl;
	cout << endl;

	cout << "10. Operator << " << endl;
	cout << "Operator strumieniowy, wypisujacy planete" << endl;
	cout << p1;
	cout << endl;

	cout << "=========================Koniec testu=========================" << endl;



}

#endif
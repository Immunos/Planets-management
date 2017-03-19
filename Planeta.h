#pragma once

#include <iostream>
#include <string>

#include "Atmosfera.h"
#include "Powierzchnia.h"
#include "Ksiezyc.h"

using namespace std;

class Planeta
{
public:
	void dodaj_ksiezyc(int masa, int promien, int czas_obiegu);
	static int ile_planet();
	void wypisz_planete();
	
																				// Konstruktory i destruktor

	Planeta(string nazwa, long int masa, int promien, int sr_temperatura, int dl_dnia, int dl_roku, string zycie,
	int zaw_tlenu, int cisnienie, string glowny_skadnik);
	Planeta();
	~Planeta();
	Planeta(const Planeta &p);

																				//Operatory 

	bool operator==(const Planeta &p);
	Planeta& operator=(const Planeta &p);
	bool operator>(const Planeta &p);
	bool operator<(const Planeta &p);
	Planeta operator+(const Planeta &p);
	bool operator!=(const Planeta &p);
	void operator[](int ilosc_ksiezycy);
	int operator!();
	operator double();
	friend ostream& operator<<(ostream &s, Planeta &p);
	
																				//Funkcja testujaca wszystkie operatory i konstruktory

	friend void test_wszystkiego(Planeta &p1, Planeta &p2);

private:
	string nazwa;
	long int masa;
	int promien;
	int liczba_ksiezycow;
	Atmosfera atmosfera;
	Powierzchnia powierzchnia;
	Ksiezyc* ksiezyc;
    static int nr_planety;
};


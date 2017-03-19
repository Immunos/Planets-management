#pragma once

#include <iostream>
#include <string>

using namespace std;

class Atmosfera 
{
public:
	void wypisz_atmosfere();
	Atmosfera();	
	Atmosfera(int zaw_tlenu, int cisnienie, string glowny_skladnik);
	friend ostream& operator<<(ostream &s, Atmosfera &a);

private:
	int zaw_tlenu;
	int cisnienie;
	string glowny_skladnik;
};
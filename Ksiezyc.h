#pragma once

#include <iostream>
#include <string>

using namespace std;

class Ksiezyc
{
public:
	Ksiezyc();
	Ksiezyc(long int masa, int promien, int czas_obiegu);
	void wypisz_ksiezyc();
	friend ostream& operator<<(ostream &s, Ksiezyc &k);
private:
	long int masa;
	int promien;
	int czas_obiegu;
};
#pragma once

#include <iostream>
#include <string>

using namespace std;

class Powierzchnia 
{
public:
	Powierzchnia();
	Powierzchnia(int sr_temperatura, int dl_dnia, int dl_roku, string zycie);
	void wypisz_powierzchnie();
	friend ostream& operator<<(ostream &s, Powierzchnia &p);

private:
	int sr_temperatura;
	int dl_dnia;
	int dl_roku;
	string zycie;
};
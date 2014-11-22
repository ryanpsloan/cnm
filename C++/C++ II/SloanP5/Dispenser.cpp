// Ryan Sloan
// ryansdeal@hotmail.com
// Dispenser.h

#include "stdafx.h"
#include "Dispenser.h"
#include <string>
#include <sstream>
using namespace std;

Dispenser::Dispenser()
{
	beverage = "None Selected";
	cost = 0.00;
	total = 0;
}

void Dispenser::SetStock(string n, double c, int t)
{
	beverage = n;
	cost = c;
	total = t;
	
}

string Dispenser::DispenseSoda()
{   stringstream ss;
	ss << beverage << " was selected.";
	total -= 1;
	return ss.str();
}
string Dispenser::GetWriteLogEntry()
{
	stringstream ss;
	ss << beverage << " was dispensed. " << total << " beers remaining in dispenser." <<  endl;
	string input = ss.str();
	return input;
}

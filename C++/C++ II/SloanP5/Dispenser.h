//	Ryan Sloan	
//	Program 5 - CIS2275
//	Dispenser.h

#ifndef _DISPENSER_H
#define _DISPENSER_H
#include "stdafx.h"
#include <string>
using namespace std;

class Dispenser
{
private:
	string beverage;
	double cost;
	int total;

public:
	Dispenser();
	void SetStock(string n, double c, int t);
	
	double GetCost() {return cost;}
	string GetSodaName() {return beverage;}
	int GetStock() {return total;}

	string DispenseSoda();
	string GetWriteLogEntry();
};
#endif
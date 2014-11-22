//	Ryan Sloan	
//	Program 5 - CIS2275
//	VendingMachine.h

#ifndef _VENDINGMACHINE_H
#define _VENDINGMACHINE_H

#include "stdafx.h"
#include "MoneyCtr.h"
#include "Logger.h"
#include "Dispenser.h"
#include <string>
using namespace std;

class VendingMachine
{
private:
	int selection;
	string dispenseString;

	MoneyCtr bank;
	Dispenser D[5];
	Logger writeLogger;

	void DispenseItem();
public:
	VendingMachine();
	~VendingMachine();

	
	void SetCoins(int dol, int qu, int di, int ni);
	void SetSelection(int sel);

 	double GetMoneyInput() {return bank.GetHowMuchInput();}
	string GetDispenseString() {return dispenseString;}
	string GetChange() {return bank.GetReturnMoney();}
	double GetTotalMoney(){return bank.GetTotMoney();}
	string ReturnAllMoneyAndExit();
	void WriteLog(string s);
	void ResetBank();
	
};

#endif
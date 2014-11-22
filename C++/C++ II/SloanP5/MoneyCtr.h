//	Ryan Sloan	
//	Program 5 - CIS2275
//	MoneyCtr.h

#ifndef _MONEYCTR_H
#define _MONEYCTR_H
#include "stdafx.h"
#include <string>
using namespace std;

class MoneyCtr
{
private:
	int dollars, quarters, dimes, nickels;
	int totDol, totQuar, totDime, totNick;
	double totMoney;

	double change, inputAmount, purchAmt;

	string myChange;
	void MakeChange();
	void CalcTotalMoney();
	void CalcInputAmount();
public:
	MoneyCtr();
	double MoneyBack();
	void SetInputMoney(int dol, int quar, int dim, int nick);
	void SetSodaCost(double sodaCost);
	void SetChange(double c);
	

	double GetHowMuchInput(){return inputAmount;}
	string GetReturnMoney() {return myChange;}
	double GetChange() {return change;}
	double GetTotMoney() {return totMoney;}
	
	string GetBeginFile();
	string GetWriteLog();
	
	void ResetBank();

};

#endif
// Ryan Sloan
// ryansdeal@hotmail.com
// MoneyCtr.cpp

#include "stdafx.h"
#include"MoneyCtr.h"
#include"Dispenser.h"
#include"Logger.h"
#include"VendingMachine.h"
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

MoneyCtr::MoneyCtr()
{
	dollars = 0;
	quarters = 0; 
	dimes = 0; 
	nickels = 0;
	totDol = 20; 
	totQuar = 20; 
	totDime = 20; 
	totNick = 20;
	totMoney = 0.00;
	myChange = "Your change $0.00";
	change = 0.00;
	inputAmount = 0.00;
	purchAmt = 0.00;
	CalcTotalMoney();
}

void MoneyCtr::SetInputMoney(int dol, int quar, int dim, int nick)
{
	dollars = dol;
	quarters = quar;
	dimes = dim;
	nickels = nick;
	CalcInputAmount();
	
}

void MoneyCtr::MakeChange()
 {	
	change = inputAmount - purchAmt;
	stringstream ss;
	ss << "Your change is *$" << change;
	myChange = ss.str();
	totMoney -= change;
	inputAmount -= purchAmt;
	inputAmount -= change;
	
	
}	
	
void MoneyCtr::SetChange(double c)
{
	change = c;
}
void MoneyCtr::CalcTotalMoney()
{
	totDol += dollars;
	totQuar += quarters;
	totDime += dimes;
	totNick += nickels;
	totMoney = totDol * 1.00;
	totMoney += totQuar * 0.25;
	totMoney += totDime * 0.10;
	totMoney += totNick * 0.05;
	
}

void MoneyCtr::CalcInputAmount()
{
	inputAmount = dollars * 1.00;
	inputAmount += quarters * 0.25;
	inputAmount += dimes * 0.10;
	inputAmount += nickels * 0.05;
	CalcTotalMoney();
}

void MoneyCtr::ResetBank()
{
	dollars = 0;
	quarters = 0;
	dimes = 0;
	nickels = 0;
	totDol = 0;
	totQuar = 0;
	totDime = 0;
	totNick = 0;
	totMoney = 28.00;
	inputAmount = 0;
	CalcInputAmount();
	CalcTotalMoney();
}

void MoneyCtr::SetSodaCost(double sodaCost)
{
	purchAmt = sodaCost;
	MakeChange();
}


string MoneyCtr::GetBeginFile()
{	stringstream ss;
	ss << "$" << totMoney << " Total Money in Bank" << endl;
	ss << totDol << " Dollars."<< endl;
	ss << totQuar << " Quarters." << endl;
	ss << totDime << " Dimes." << endl;
	ss << totNick << " Nickels." << endl;
	return ss.str();
}
string MoneyCtr::GetWriteLog()
{	stringstream ss;
	ss << "$" << totMoney << " Total Money in Bank";
	return ss.str();
}



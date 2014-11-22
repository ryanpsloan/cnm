// Ryan Sloan
// rsloan2@cnm.edu
// MoneyChanger.cpp

#include"MoneyChanger.h"
#include<iostream>

using namespace std;

void Header()
{
	cout << "Ryan Sloan\n" << "Exercise 3\n" << "The MoneyChanger Class\n";
}


void MoneyChanger::determineChange()
{
	totalChange = amountGiven - totalCost;
	remainingAmount = static_cast<int>(totalChange*100);
}


MoneyChanger::MoneyChanger()
{
	totalCost = 7.65;
	amountGiven = 10.00;
	totalChange = 2.35;
	remainingAmount = static_cast<int>(totalChange*100);
}

void MoneyChanger::setTotalCost(double purchasePrice, double amountPaid)
{
	totalCost = purchasePrice;
	amountGiven = amountPaid;
	determineChange();
}

void MoneyChanger::getBills(int &v20s, int &v10s, int &v5s, int &v1s)
{			
			// Find the number of twenties
			v20s = remainingAmount / 2000;
			remainingAmount = remainingAmount % 2000;

			// Find the number of tens
			v10s = remainingAmount / 1000;
			remainingAmount = remainingAmount % 1000;

			// Find the number of fives
			v5s = remainingAmount / 500;
			remainingAmount = remainingAmount % 500;
		
			// Find the number of dollars
			v1s = remainingAmount / 100;
			remainingAmount = remainingAmount % 100;
					
}

void MoneyChanger::getCoins(int &Quarters,int &Dimes, int &Nickles, int &Pennies)
{
			// Find the number of remaining quarters
			Quarters = remainingAmount / 25;
			remainingAmount = remainingAmount % 25;
		
			// Find the number of remaining dimes
			Dimes = remainingAmount / 10;
			remainingAmount = remainingAmount % 10;
		
			// Find the number of remaining nickles
			Nickles = remainingAmount / 5;
			remainingAmount = remainingAmount % 5;
		
			// Find the number of remaining pennies
			Pennies = remainingAmount;
}
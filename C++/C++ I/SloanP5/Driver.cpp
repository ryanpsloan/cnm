// CIS1275 - Feridoon Ghanbari
// Ryan Sloan - rsloan2@cnm.edu
// SloanP5/Driver.cpp

#include<iostream>
#include<string>
#include<iomanip>
#include"Whiskey.h"
using namespace std;

int main()
{
	Header();
	cout << fixed << showpoint;
	cout.precision(2);
	string answer;
	do
	{
		string name;
		int diameter, height, numOfBarrels;
		AskName(name);
		AskForBarrels(diameter, height, numOfBarrels);
		double volumeLiters = CalcNetWhiskeyVol(diameter, height, numOfBarrels);
		double volumeFinal = 0;
		int numOfBottles = 0;
		int numOfCases = 0;
		double remainingBottles = 0;
		double remainder = DetermineVol(volumeLiters, volumeFinal, numOfBottles, numOfCases, remainingBottles);
		cout << "The total volume of " << name << " Whiskey is " << volumeFinal << " liters. " << endl;
		cout << "The number of Cases is " << numOfCases << " and " << "The number of 2.0 Liter Bottles is " << numOfBottles << endl;
		cout << "There are " << remainingBottles << " bottles remaining, a total of " << remainder << " liters. " << endl;
		cout << "Calculate another? yes/no : ";
		cout << endl;
		getline(cin,answer);
	} while (answer == "yes");	
	cout << "GoodBye" << endl;
	return 0;
}
// Ryan Sloan
// rsloan2@cnm.edu
// CIS2275 - Program 2
// Driver.cpp

#include <string>
#include <iostream>
#include <stdio.h>
#include "MortCalc.h"
using namespace std;

int main()
{
	double p, i;
	int n;
	string name;
	Header();
	cout << "Welcome to the Mortgage Calculator " << endl;
	cout << endl;
	name = AskForName();
	MortCalc mc;
	string result = mc.getFormattedString();
	cout << endl;
	cout << "The default loan information is: " << endl;
	cout << result << endl;
	cout << endl;
	char loop = 'y';
	while (loop == 'y')
	{
		int menu;
		cout << "Select an input option" << endl;
		cout << "Enter 1 for single entry" << endl;
		cout << "Enter 2 for multiple entry" << endl;
		cout << ">> ";
		cin >> menu;
		switch(menu)
		{
			case 1:
				cout << name << endl;
				cout << "Enter the Principal amount: ";
				cin >> p;
				cin.ignore();
				cout << "Enter the Interest Rate as a percentage (i.e. 3.25): ";
				cin >> i;
				cin.ignore();
				cout << "Enter the Term in years: ";
				cin >> n;
				cin.ignore();
				break;
			case 2:
				cout << "Enter the Principal, then the Interest, then the Term in Years: " << endl;
				cin >> p >> i >> n;
				break;
			default:
				cout << "The option you entered is invalid." << endl;
		}
		MortCalc calc(p,i,n);
		cout << "The total value of the loan is $" << calc.getTotalLoan() << endl;
		cout << endl;
		cout << "The total interest is $" << calc.getTotalInterest() << endl;
		cout << endl;
		cout << "The monthly payment is $" << calc.getMonthlyPayment() << endl;
		cout << endl;
		string filename;
		bool fileOpen = mc.WriteFile(name, mc.getFormattedString(), filename);
		if(fileOpen)
		{
			cout << "Your data was written to file at " << filename << endl;
		}
		else
		{
			cout << "The attempt to open the file at " << filename << " was unsuccessful." << endl;
		}	
		cout << endl;
		cout << "Would you like to do another calculation? y/n ";
		cin >> loop;
		cin.ignore();
	}
	cout << endl;
	cout << "Goodbye and Farewell" << endl;	
	return 0;
}
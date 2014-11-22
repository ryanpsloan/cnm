// CIS2275
// Ryan Sloan
// rsloan2@cnm.edu
// SloanP1.cpp

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include "Header.h"
using namespace std;
int main()
{
	string choice;
	//header
	PrintHeader();
	//Function gets username and returns it as a string
	string name = AskForName();
	do
	{
		//Declare variables
		double principal = 0.00;
		double interest = 0.00;
		int years = 0;
		//Get loan info
		AskForLoanInfo(principal,interest,years,name);
		//variables to pass by pointer
		double mnthlypymt = 0.00;
		double totalloan = 0.00;
		double totalinterest = 0.00;
		//pointers with variable reference assignments
		double* ppymt = &mnthlypymt;
		double* ptloan = &totalloan;
		double* ptint = &totalinterest;
		//Function calculates values and sets values by pointer
		MortCalc(principal, interest, years, ppymt, ptloan, ptint);
		//function calculates values and returns a string object
		string result = MortCalc(principal, interest, years);
		//prints string to the screen
		cout << result << endl;
		//sets precision to 2 decimal places
		cout << showpoint << fixed;
		cout.precision(2);
		cout << endl;
		//output
		cout << "Transferred by pointer: " << endl;
		cout << "Your monthly payment is $" << mnthlypymt << endl;
		cout << "Your total loan value is $" << totalloan << endl;
		cout << "The total interest paid is $" << totalinterest << endl;
		//declare a string to pass by reference
		string filename;
		//function opens file if successful returns a true
		bool file = WriteFile(name, result, filename);
		if (!file)
		{
			cout << "The file was not opened successfully." << endl;
		}
		else
		{
			cout << "The file was successfully written to " << filename << "." << endl;
		}
		cout << endl;
		//Prompt to determine to loop or not
		cout << name << ", would you like to calculate another mortgage? y/n: ";
		getline(cin,choice);
	}while(choice == "y");

	cout << endl;
	cout << "Goodbye" << endl;
}
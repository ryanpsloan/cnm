// Ryan Sloan
// rsloan2@cnm.edu
// CIS2275 - Program 4
// MortCalc.cpp


#include "MortCalc.h"
#include <string>
#include <cmath> 
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

string AskForName()
{
	string name;
	cout << "Enter your name: ";
	getline(cin, name);
	return name;
}

void MortCalc::Calculate()
{
	monthlyPayment = (principal * interest) / (q * (1 - (pow(1+(interest/q),-(years*q)))));
	totalLoan = (monthlyPayment * q) * years;
	totalInterest = totalLoan - principal;
	stringstream ss;
	ss << "A loan with a principal of " << principal << "\n" 
	   << "and an interest rate of " << interest << "\n" 
	   << "for a term of " << years << " years, \n" 
	   << "has a monthly payment of $"<< monthlyPayment << "\n"
	   << "and a total value of $" << totalLoan << "\n" 
	   << "with a total interest of $" << totalInterest;
	formattedString = ss.str();
						
}

bool MortCalc::WriteFile(string name, string formattedString, string &rFileName)
{
	static int counter = 0;
	counter++;
	stringstream ss;
	ss << name << counter << ".txt";
	rFileName = ss.str();
	
	// declare the output file object
	ofstream outputFile;

	// Open the file for writing
	outputFile.open(rFileName);

	// Check that we've open the file
	if(!outputFile)
	{
		cout << "\nWhoops! Can't open find " << rFileName;
		return false;
	}

	// Write to the file
	outputFile << formattedString << endl;
	

	// close the file
	outputFile.close();
	return true;
	

}
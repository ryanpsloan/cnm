// CIS2275
// Ryan Sloan
// rsloan2@cnm.edu
// SloanP1.cpp

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
using namespace std;

void PrintHeader()
{
	cout << "Program 1 - Mortgage Calculator" << endl;
	cout << "Ryan Sloan " << endl;
	cout << "Review";
	cout << endl;
	cout << "Mortgage Calculator" << endl;
	cout << endl;
}

string AskForName()
{
	string name;
	cout << "Enter Your Name: ";
	getline(cin,name);
	cout << endl;
	return name;
}

void AskForLoanInfo(double &principal,double &interest,int &years,string name)
{
	cout << name << ", enter the principal amount: ";
	cin >> principal;
	cin.ignore();
	cout << endl;
	cout << "Enter the interest rate as a number. i.e 3.55% as .0355: ";
	cin >> interest;
	cin.ignore();
	cout << endl;
	cout << "Finally, enter the term in years: ";
	cin >> years;
	cin.ignore();
	cout << endl;
}

void MortCalc(double principal, double interest, int years, double *ppymt, double *ptloan, double *ptint)
{
	int q = 12;
	*ppymt = (principal * interest) / (q * (1 - (pow(1+(interest/q),-(years*q)))));
	*ptloan = *ppymt * (q * years);
	*ptint = *ptloan - principal;
	
}

string MortCalc(double principal, double interest, int years)
{
	stringstream ss;
	int q = 12;
	double mnthlypymnt = (principal * interest) / (q * (1 - (pow(1+(interest/q),-(years*q)))));
	double totalloanvalue = mnthlypymnt * (q * years);
	double totalinterest = totalloanvalue - principal;
	
	ss << "A loan with a Principal of $" << principal << " and an Interest rate of " << interest * 100 << "%" << endl;
	ss << "with the term of " << years << " years, has a monthly payment of $" << mnthlypymnt << "." << endl;
	ss << "The total loan value is $" << totalloanvalue << " and total interest is $" << totalinterest << "."; 
	return ss.str();
}

bool WriteFile(string name, string result, string &filename)
{
	//declare the counter
	static int counter = 0;
	//increment the counter everytime the function
	counter++;
	stringstream ss;
	ss << name << "_" << counter << ".txt";
	filename = ss.str();
	
	//Output File
	ofstream outputFile;

	// Open the file for writing
	outputFile.open(filename);

	// Check that we've open the file
	if(!outputFile)
	{
		cout << "\nWhoops! Can't open find " << filename;
		return false;
	}

	// Write to the file
	outputFile << result << endl;
	

	// close the file
	outputFile.close();

	cout << endl;
	return true;
}
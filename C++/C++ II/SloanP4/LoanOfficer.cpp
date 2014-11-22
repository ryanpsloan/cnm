// Ryan Sloan
// ryansdeal@hotmail.com
// LoanOfficer.cpp
// Program 4

#include "MortCalc.h"
#include "LoanOfficer.h"
#include<string>
#include<iostream>
#include<sstream>
#include<fstream>
using namespace std;

void LoanOfficer::Calculate()
{
	monthlyPayment = mc.getMonthlyPayment();
	if (monthlyExpenses + monthlyPayment <= .50*monthlyIncome)
		bApproved = true;
	else
		bApproved = false;
}	
LoanOfficer::LoanOfficer()
{
	mc.setInterest(4.10);
	mc.setYears(30);
	bankName = "C++ Bank";
	welcome = "Welcome to " + bankName + "'s Mortgage Lending Platform";
	userName = "";
	loanOfficer = "Ryan Sloan";
	
}
	
void LoanOfficer::setPrincipal(double p)
{
	principal = p;
	mc.setPrincipal(principal);
	Calculate();
}
string LoanOfficer::getIntro()
{
	stringstream ss;
	ss << welcome << " " << userName << ", the current \ninterest rate is 4.10% and the current Loan term is 30 years.\n";
	ss << "My name is " << loanOfficer << ", I will be your loan officer.";
	
	return ss.str();
}
string LoanOfficer::getLoanApproval()
{
	stringstream ss;	
	if(bApproved){
		ss << "Congratulations! You have been approved for a $" << principal << " loan. \nThe interest rate is 4.10% with a term of 30 years. \n";
		ss << "The total loan value is $" << mc.getTotalLoan() << ", and the total interest is $" << mc.getTotalInterest() << "." << endl; 
		ss << "Your monthly payment will be $" << mc.getMonthlyPayment() << ".\n" << endl;
	}
	else 
	{
		ss << "We are sorry you were not approved for a loan with " << bankName << endl;
		ss << "due to the fact that your monthly payment and monthly expenses $" << monthlyExpenses + monthlyPayment << endl;
		ss << "exceeded 50% of your income $" << monthlyIncome << endl;
	}
	loanInfo = ss.str();
	return loanInfo;
}
string LoanOfficer::getFilename()
{	
	return mc.getFormattedString();
}
void LoanOfficer::WriteFile(string name)
{
	static int counter = 0;
	counter++;
	stringstream ss;
	ss << name << counter << ".txt";
	fileName = ss.str();
	
	// declare the output file object
	ofstream outputFile;

	// Open the file for writing
	outputFile.open(fileName);

	// Check that we've open the file
	if(!outputFile)
	{
		bWriteFile = false;
	}

	// Write to the file
	outputFile << loanInfo << endl;
	

	// close the file
	outputFile.close();
	bWriteFile = true;
}
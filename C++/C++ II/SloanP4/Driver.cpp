// Ryan Sloan
// ryansdeal@hotmail.com
// Driver.cpp
// Program 4

#include "MortCalc.h"
#include "LoanOfficer.h"
#include "Functions.h"

#include <string>
#include <iostream>

using namespace std;

int main()
{
	Header();
	LoanOfficer officer;
	MortCalc mortcalc;

	cout << "Please provide your name.\n";
	cout << ">> ";
	string name;
	getline(cin, name);
	officer.setUserName(name);
	cout << endl;
	
	cout << officer.getIntro();
	cout << endl;
	char loopCondition = 'y';
	
	do
	{
		cout << "What is your monthly income?\n";
		cout << ">> $";
		double i;
		cin >> i;
		officer.setMonthlyIncome(i);
		cout << endl;

		cout << "What are your monthly expenses?\n";
		cout << ">> $";
	
		double me;
		cin >> me;
		officer.setMonthlyExpenses(me);
		cout << endl;
	
		cout << "How much are you looking to borrow?\n";
		cout << ">> $";
		double p;
		cin >> p;
		officer.setPrincipal(p);
		cout << endl;

		cout << "Let me process this information, this will only take a second.";
		cout << endl;
		cout << "Processing...\n\n";
		cout << endl;
		bool approval = officer.isLoanApproved();
		if(approval)
			cout << ">>>Congratulations! You are approved!<<<\n\n" << endl;
		else
			cout << "I'm sorry you were not approved. See details below.\n";
		string loanApproval = officer.getLoanApproval();
		cout << loanApproval;
		cout << endl;
		cout << "Would you like to have this information written to file? y/n: ";
		char answer;
		cin >> answer;
		if (answer == 'y') {
			officer.WriteFile(name);	
			if(officer.isWriteFile())
			{
				cout << ">> Your data has been written to file at " << officer.getFileName() << "\n\n";
			}
			else 
			{
				cout << "We were unable to write the information to file." << endl;
			}
		}
		
		cout << "Would you like to process another request? y/n:" ;
		cin >> loopCondition;
		cout << endl << endl;
	}while (loopCondition == 'y');
	cout << endl;
	cout << "Thanks for using C++ Bank. Goodbye" << endl;
}
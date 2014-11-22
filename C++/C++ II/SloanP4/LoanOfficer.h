// Ryan Sloan
// ryansdeal@hotmail.com
// LoanOfficer.h
// Program 4

#ifndef _LOANOFFICER_H
#define _LOANOFFICER_H

#include "MortCalc.h"
#include<string>
#include<sstream>
using namespace std;


class LoanOfficer
{
	private:
		MortCalc mc;
		double monthlyExpenses, principal, monthlyPayment, monthlyIncome, totalLoan, ratio;
		string userName, bankName, loanOfficer, loanInfo, welcome, fileName;
		bool bApproved, bWriteFile;
		int counter;
		void Calculate();
	public:
		LoanOfficer();
		//sets
		void setMonthlyPayment(double mp) {monthlyPayment = mp;}
		void setUserName(string un) {userName = un;}
		void setMonthlyExpenses(double me) {monthlyExpenses = me;}
		void setPrincipal(double p);
		void setMonthlyIncome(double i) {monthlyIncome = i;}
		//gets
		string getIntro();
		string getLoanApproval();
		string getFileName() {return fileName;}
		bool isLoanApproved() {return bApproved;}
		bool isWriteFile() {return bWriteFile;}
		string getFilename();
		void WriteFile(string name);
};
#endif
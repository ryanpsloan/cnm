// Ryan Sloan
// rsloan2@cnm.edu
// CIS2275 - Program 2
// MortCalc.h

#include <string>
using namespace std;

void Header();
string AskForName();


class MortCalc
{
private:
	double principal, interest; //Interest is expected to come in in percentage format i.e. 3.25 
	int years, q;
	double monthlyPayment, totalLoan, totalInterest;
	string formattedString;
	void Calculate();

public:
	MortCalc() {principal = 325000; interest = .0325; years = 30; q = 12; Calculate();}
	MortCalc(double p, double i, int n) {principal = p; interest = i/100; years = n; q = 12; Calculate();}
	void setPrincipal(double p) {principal = p; Calculate();}
	void setInterest(double i) {interest = i/100; Calculate();}
	void setYears(int n) {years = n; Calculate();}
	void setAll(double p, double i, int n){principal = p; interest = i/100; years = n; q = 12; Calculate();}
	double getMonthlyPayment() {return monthlyPayment;}
	double getTotalLoan() {return totalLoan;}
	double getTotalInterest() {return totalInterest;}
	string getFormattedString() {return formattedString;}
	bool WriteFile(string name, string formattedString, string &rFileName);
	
};
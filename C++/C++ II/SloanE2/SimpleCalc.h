// Ryan Sloan
// rsloan2@cnm.edu
// CIS2275 - C ++ II
// File: SimpleCalc.h


#ifndef _SIMPLECALC_H
#define _SIMPLECALC_H
#include<string>
using namespace std;

void Header();

class SimpleCalc
{
private:
	char operation;
	int number1;
	int number2;
	int answer;
	string results;

public:
	SimpleCalc(); //default constructor
	void setOperation(char oper, int op1, int op2);
	string getResults();
};

#endif
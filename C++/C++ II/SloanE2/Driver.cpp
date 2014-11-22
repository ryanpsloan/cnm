// Ryan Sloan
// rsloan2@cnm.edu
// CIS2275 - C ++ II
// File: Driver.cpp

#include"SimpleCalc.h"
#include<string>
#include<iostream>
using namespace std;

int main()
{
	Header();
	cout << "Welcome to the C++ Calculator" << endl;
	cout << endl;
	cout << endl;
	//Calc object
	SimpleCalc calc;
	//while condition variable
	char loop = 'y';
	while (loop == 'y')
	{
		//variables for input		
		int op1 = 0;
		int op2 = 0;
		char oper = '+';
		//first int input
		cout << "Enter the first number to calculate: ";
		cin >> op1;
		cin.ignore();
		//operation input
		cout << "Choose the operation ( +  -  *  /  % ): ";
		cin >> oper;
		cin.ignore();
		//second int input
		cout << "Enter the second number to calculate: ";
		cin >> op2;
		cin.ignore();
		//calling setOperation to perform calculations
		calc.setOperation(oper, op1, op2);
		cout << endl;
		//calling getResults to output the results
		cout << calc.getResults() << endl;
		//checking if user would like to do another loop
		cout << "Would you like another operation? y/n ";
		cin >> loop;
		cin.ignore();
		cout << endl;
	}
		
	cout << "Goodbye and Farewell" << endl;
}
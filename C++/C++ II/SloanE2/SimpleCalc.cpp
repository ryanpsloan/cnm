// Ryan Sloan
// rsloan2@cnm.edu
// CIS2275 - C ++ II
// File: SimpleCalc.cpp

#include"SimpleCalc.h"
#include<string>
#include<iostream>
#include<sstream>
using namespace std;

void Header()
{
	cout << "Ryan Sloan \n" << "Exercise 2 \n" << "CIS2275" << endl;
}

SimpleCalc::SimpleCalc()
{
	operation = '+';
	number1 = 5;
	number2 = 5;

}
	
void SimpleCalc::setOperation(char oper, int op1, int op2)
{
	//assign values to class variables
	operation = oper;
	number1 = op1;
	number2 = op2;

	//perform appropriate calculations based on user input
	if (operation == '+')
	{
		answer = number1 + number2;
	}
	else if (operation == '-')
	{
		answer = number1 - number2;
	}
	else if (operation == '*')
	{
		answer = number1 * number2;
	}
	else if (operation == '/')
	{
		if(op2 == 0)
		{
			getResults();	//if division by zero go to getResults
		}
		else
		{
			answer = number1 / number2;
		}
	}
	else if (operation == '%')
	{
		answer = number1 % number2;
	}
	stringstream ss;
	//determine if division by zero if so output error message
	if (operation == '/' && number2 == 0)
	{
		ss << "Your operation is division: " << number1 << " " << operation << " " << number2 << " Illegal Operation";
		results = ss.str();
	}
	//determine operation chosen and output right message
	else if (operation == '+')
	{
		ss << "Your operation is addition: " << number1 << " " << operation << " " << number2 << " = " << answer;
		results = ss.str();
	}
	else if (operation == '-')
	{
		ss << "Your operation is subtraction: " << number1 << " " << operation << " " << number2 << " = " << answer;
		results = ss.str();
	}
	else if (operation == '*')
	{
		ss << "Your operation is multiplication: " << number1 << " " << operation << " " << number2 << " = " << answer;
		results = ss.str();
	}
	else if (operation == '/')
	{
		ss << "Your operation is division: " << number1 << " " << operation << " " << number2 << " = " << answer;
		results = ss.str();
	}
	else if (operation == '%')
	{
		ss << "Your operation is modulus: " << number1 << " " << operation << " " << number2 << " = " << answer;
		results = ss.str();
	}
}

string SimpleCalc::getResults()
{	
	return results;

}
// CIS1275 - Feridoon Ghanbari
// Ryan Sloan - rsloan2@cnm.edu
// SloanQ3/Driver.cpp

#include <iostream>
#include <string>
#include "Ribbon.h"

using namespace std;
int main()
{
	Header();
	cout << "Ribbon Calculator" << endl;
	cout << endl;
	string answer;
	do
	{
		cout << "To calculate the length of a ribbon needed to wrap" << endl;
		cout << "your package, enter the package dimensions. " << endl;
		cout << endl;
		double length, width, height;
		cout << "Enter the Length:  ";
		cin >> length;
		cin.ignore();
		cout << endl;
		cout << "Enter the Width:  ";
		cin >> width;
		cin.ignore();
		cout << endl;
		cout << "Enter the Height:  ";
		cin >> height;
		cin.ignore();
		cout << endl;
		double ribbonLength = CalcRibbon(length, width, height);
		WriteRibbonReport(ribbonLength, length, width, height);



		cout << "Would you like to calculate another? y/n" << endl;
		getline(cin, answer);
		cout << endl;
	} while(answer == "y");
	cout << "Goodbye!" << endl;
	return 0;
}
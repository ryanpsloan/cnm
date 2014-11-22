// CIS1275 - Feridoon Ghanbari
// Ryan Sloan - rsloan2@cnm.edu
// SloanE15/Driver.cpp

#include <iostream>
#include <cstring>
#include <string>
#include "Functions.h"

using namespace std;

int main()
{
	Header();
	char cstring1[51];
	char cstring2[51];
	char response;
	do
	{
		cout << "Enter a string of up to 50 characters that you want to reverse." << endl;
		cin.getline(cstring1, 51);
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(255,'\n');
		}
		int length = strlen(cstring1);
		cout << endl;
		cout << "The sentence you want to reverse is: " << endl;
		cout << cstring1 << endl;
		cout << endl;
		cout << "The reverse of this string is: " << endl;
		ReverseIt(cstring1, cstring2, length);
		cout << endl;
		cout << "Do you want to reverse another cstring? y/n ";
		cin >> response;
		cout << endl;
		cin.ignore();
	}while (response == 'y');
	cout << "GoodBye" << endl;
	cout << endl;
	return 0;
}
// CIS1275 - Feridoon Ghanbari
// Ryan Sloan - rsloan2@cnm.edu
// SloanE15/Functions.cpp

#include <iostream>
#include <cstring>

using namespace std;

void Header()
{
	cout << "Ryan Sloan" << endl;
	cout << "Exercise 15" << endl;
	cout << "C - Strings and Character Arrays" << endl;
	cout << endl;
}

void ReverseIt(char cstring1[], char cstring2[], int length)
{
	cstring2[length] = '\0';
	int j = 0;
	for (int i = length - 1; i >= 0; i--)
	{	
		cstring2[j] = cstring1[i];
		j++;
	}
	cout << cstring2;
	cout << endl;
	
}
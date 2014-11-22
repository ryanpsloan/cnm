//Ryan Sloan
//driver.cpp

#include <string>
#include <iostream>
#include "Date.h"
;using namespace std;

void WriteHeader();

//###########################################
//INSTRUCTIONS
//The main() should create two Date objects.
//"one" uses the default constructor.
//"two" uses the overloaded constructor.

//Add  code in main so that the object names 
//are written before the getFormattedDate() call.  

//Once one and two are created, cout << the string
//from getFormattedDate()
//###########################################

int main()
{
	WriteHeader();

	Date one;		
	Date two(12,22,1999);	
			
	string s1, s2;

	cout << "Date object name: one\n"; //added object name cout
	s1 = one.getFormattedDate();
	cout << s1 << endl;

	cout << "Date object name: two\n"; //added object name cout
	s2 = two.getFormattedDate();
	cout << s2 << endl;

	cout << "\n\n Goodbye for now from Quiz 3\n\n";

	return 0;
}

void WriteHeader()
{					//changed name;
	cout << "\n\n Ryan Sloan \n CIS 2275 Spring 2013 "
		<<"In-Class Quiz 3\n Fix a broken program.\n" << endl;
}
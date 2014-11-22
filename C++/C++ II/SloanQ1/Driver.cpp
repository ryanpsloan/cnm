// Ryan Sloan
// rsloan2@cnm.edu
// Driver.cpp

#include"Dog.h"
#include<iostream>
#include<string>
using namespace std;

int main()
{
	Header();

	cout << "Welcome to the dog show! \n" << endl;

	//first dog object Default constructor
	Dog first;
	//calling GetFormattedString
	string dog1 = first.GetFormattedString();

	cout << "Let' see our first Dog:" << endl << dog1 << "\n\n";
	//second dog object overloaded constructor
	Dog second("Highlander", 25.0, 5, "Male", "Scottish Terrier");
	//calling GetFormattedString
	string dog2 = second.GetFormattedString();

	cout << "Our second Dog is: " << endl << dog2 << "\n\n";
	//third dog object default constructor
	Dog third;
	//adjust the object fields with the set method
	third.SetData("Whisper" , 10.0, 2, "Female", "Poodle");
	//call GetFormattedString
	string dog3 = third.GetFormattedString();

	cout << "Our final Dog is: " << endl << dog3 << "\n\n";

	return 0;
}
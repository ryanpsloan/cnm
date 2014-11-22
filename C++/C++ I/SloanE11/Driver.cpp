// CIS1275 - Feridoon Ghanbari
// Ryan Sloan - rsloan2@cnm.edu
// SloanE11/Driver.cpp

#include <iostream>
#include <string>

using namespace std;

void Header();
void GetTwoNumbers(int &num1, int &num2);
int FindBigOne(int num1, int num2);

int main()
{
	Header();
	string answer = "y";
	int num1 = 0, num2 = 0;
	do
	{
		GetTwoNumbers(num1, num2);
		int larger = FindBigOne(num1,num2);
		cout << "The larger of the two numbers you entered" << endl;
		cout << "is " << larger << "." << endl;
		cout << "Do another set? y/n" << endl;
		getline(cin, answer);	
		cout << endl;
	} while (answer == "y");
	cout << "GoodBye";
	return 0;
}

void Header()
{
	cout << "Ryan Sloan" << endl;
	cout << "Exercise 11" << endl;
	cout << "Objective - Functions and References" << endl;
	cout << endl;
}

void GetTwoNumbers(int &num1, int &num2)
{
	cout << "Enter an Integer: ";
	cin >> num1;
	cin.ignore();
	cout << "Enter another Integer: ";
	cin >> num2;
	cin.ignore();
}

int FindBigOne(int num1, int num2)
{
	if(num1 > num2)
		return num1;
	else if (num1 < num2)
		return num2;
	else if (num1 == num2)
		return num1;
}

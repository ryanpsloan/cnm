// CIS1275 - Feridoon Ghanbari
// Exercise 5 
// Ryan Sloan, rsloan2@cnm.edu
// SloanE5/Driver.cpp

#include <iostream>

using namespace std;

int main()
{
	int int1 = 0;
	int int2 = 0;
	
	cout << "Ryan Sloan" << endl;
	cout << "Exercise 5" << endl;
	cout << "Objective: Using for Loops" << endl;
	cout << endl;
	char repeat;
	do
	{
		cout << "Enter an Integer." << endl;
		cin >> int1;
		cin.ignore();
		cout << "Enter another Integer larger than the first." << endl;
		cin >> int2;
		cin.ignore();
		cout << endl;
		if (int1 == int2)
		{
			cout << "The values you entered are equal." << endl;
			cout << "Do again?" << endl;
			cin >> repeat;	
			cout << endl;
		}
		else if (int1 > int2)
		{
			cout << "I am reordering your numbers as the first integer was greater than the second." << endl;
			int temp = int1;
			int1 = int2;
			int2 = temp;
			int sum = int1;
			cout << "The integers between the two integers you entered are: " << endl;
			for (int i = int1 + 1; i < int2; ++i)
			{ 
				cout << i << endl;
				sum += i;
			}
			sum += int2;
			cout << "The sum of the integers " << int1 << " through " << int2 << " is: " << sum << endl;
			cout << "Do again?" << endl;
			cin >> repeat;		
			cout << endl;
		}
		else if (int1 < int2)
		{
			int sum = int1;
			cout << "The integers between the two integers you entered are: " << endl;
			for (int i = int1 + 1; i < int2; ++i)
			{ 
				cout << i << endl;
				sum += i;
			}
			sum += int2;
			cout << "The sum of the integers from " << int1 << " through " << int2 << " is: " << sum << endl;
			cout << "Do again?" << endl;
			cin >> repeat;
			cout << endl;
		}
	} while (repeat == 'y' || repeat == 'Y');
	cout << endl;
	cout << "Good-bye.";
	cout << endl;

	return 0;
}
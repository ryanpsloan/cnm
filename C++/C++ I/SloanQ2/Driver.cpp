// CIS 1275 - Feridoon Ghanbari
// Ryan Sloan, rsloan2@cnm.edu
// SloanQ2/Driver.cpp
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "Ryan Sloan" << endl;
	cout << "Quiz 2" << endl;
	cout << "if else and while loops" << endl;
	cout << endl;
	int number = 0;
	string answer = "yes";
	while (answer == "yes")
	{
		cout << "Pick a number between 1 and 99.  ";
		cin >> number;
		cin.ignore();
		if (number > 0 && number < 10)
		{
			cout << "ONE DIGIT BIG!" << endl;
		}
		else if (number >= 10 && number <= 99)
		{
			cout << "TWO DIGITS BIG!" << endl;
		}
		else
		{
			cout << "OUT OF RANGE." << endl;
		}
		cout << "Would you like to enter another number? yes/no" << endl;
		getline(cin, answer);
		
	} 
	
	cout << "Good-bye and Farewell" << endl << endl;
	
	
	
	return 0;
}
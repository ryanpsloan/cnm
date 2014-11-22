// Ryan Sloan
// rsloan2@cnm.edu
// Driver.cpp

#include"MoneyChanger.h"
#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	Header();
	MoneyChanger money;
	char loopCondition = 'y';
	while (loopCondition == 'y')
	{
		int numberOfTwentyDollars;
		int numberOfTenDollars;
		int numberOfFiveDollars;
		int numberOfOneDollars;
		int numberOfQuarters;
		int numberOfDimes;
		int numberOfNickles;
		int numberOfPennies ;
		double price;
		double amount;
		cout << "Welcome to the Change Calculator \n\n";
		cout << "Enter the Price of the item you are purchasing: $" ;
		cin >> price;
		cin.ignore();
		cout << "Enter the Amount of money you paid with: $";
		cin >> amount;
		money.setTotalCost(price,amount);
		double change = money.getTotalChange();
		if (change > 0.00)
		{
			money.getBills(numberOfTwentyDollars, numberOfTenDollars, numberOfFiveDollars, numberOfOneDollars);
			money.getCoins(numberOfQuarters, numberOfDimes, numberOfNickles, numberOfPennies);
			cout << fixed << showpoint;
			cout.precision(2);
			cout << "Your change $" << change << " consists of \n";
			cout << "\t" << numberOfTwentyDollars << " twenties\n" ;
			cout << "\t" << numberOfTenDollars << " tens\n" ;
			cout << "\t" << numberOfFiveDollars << " fives\n" ;
			cout << "\t" << numberOfOneDollars << " ones\n" ;
			cout << "\t" << numberOfQuarters << " quarters\n";
			cout << "\t" << numberOfDimes << " dimes\n" ;
			cout << "\t" << numberOfNickles << " nickles\n";
			cout << "\t" << numberOfPennies << " pennies\n";
			cout << endl;
		}
		else if (change == 0.00)
		{
			cout << fixed << showpoint;
			cout.precision(2);
			cout << "Your change is $" << change << endl << endl;
		}
		else 
		{
			cout << "The amount you entered is less than the price" << endl << endl;
		}
		cout << "Would you like to make more change? y/n ";
		cin >> loopCondition;
	}
	cout << "Goodbye and Farewell";
	return 0;
}


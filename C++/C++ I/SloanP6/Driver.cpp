// CIS1275 - Feridoon Ghanbari
// Ryan Sloan - rsloan2@cnm.edu
// SloanP6/Driver.cpp

#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<ctime>
#include<sstream>
#include"Parking.h"
using namespace std;


int main()
{
	string answer;
	Header();
	do
	{
		int outHour;
		int outMin;
		int month, day, year;
		ObtainTimeOut(outHour,outMin,month,day,year);
		
		int inHour = 00;
		char colon = ':';
		int inMinute = 00;
		AskTimeIn(inHour, colon, inMinute);
		
		bool time = ValidateTime(inHour, inMinute, outHour, outMin);
		double fee = 0.0;
		int totalHr = 0;
		int totalMin = 0;
		if (time)
		{
			
			fee = CalculateFee(inHour, inMinute, outHour, outMin, totalHr, totalMin);
			cout << "The total time you parked was " << totalHr << " HR and " << totalMin << " MIN." << endl;
			cout << "The fee for parking is $" << fee << "." << endl;
			cout << endl;
		}
		else
		{
			cout << "The time you entered was not valid." << endl;
		}
		string receipt;
		if (time)
		{
			cout << "Would you like a receipt? yes/no "; 
			getline(cin, receipt);
			cout << endl;
		
			if (receipt == "yes")
			{
				WriteReceipt(inHour, inMinute, outHour, outMin, totalHr, totalMin, month, day, year, fee);
			}
			else
			{
				cout << "Okay then. Thank you for your patronage." << endl;
				cout << endl;
			}

		}
		cout << "Would you like to continue parking? yes/no ";
		getline(cin, answer);
		cout << endl;

	} while(answer == "yes");

	cout << "Thank you for your business." << endl;
	cout << endl;

	return 0;
}
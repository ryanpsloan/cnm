// CIS1275 - Feridoon Ghanbari
// Ryan Sloan, rsloan2@cnm.edu
// SloanP4/Driver.cpp

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include "WindChill.h"

using namespace std;

int main ()
{
	cout << "Ryan Sloan" << endl;
	cout << "WindChill Program" << endl;
	cout << "Objective: using fuctions" << endl;
	cout << endl;
	double temp, windsp, windChill;
	int frostbiteTime, valid;
	string answer = "y";

	do
	{
		temp = askForTemperature();
		windsp = askForWindSpeed();
		valid = validateTempWS(temp, windsp);
		if (valid == 0)
		{
			windChill = calcWindchill(temp, windsp);
			frostbiteTime = determineFrostbiteTimes(temp, windsp);	

			cout << fixed << showpoint;
			cout.precision(2);
			cout << "If the temperature is " << temp << " degrees F" << endl;
			cout << "and the wind is blowing at " << windsp << " miles per hour" << endl;
			cout << "it feels like " << windChill << " degrees, ";
			if (frostbiteTime >= 0) 
			{
				cout << "and you can experience " << endl;
				cout << "frostbite in " << frostbiteTime << " minutes." << endl;
			}
			else
			{
				cout << "and you are in " << endl; 
				cout << "no immediate danger of frostbite." << endl;
			}
		}
		else if (valid == 1)
		{
			cout << "Both of the values you entered are invalid. Check to make sure " << endl; 
			cout << "the temperature is 40 degrees or below and the windspeed is " << endl;
			cout << "5 mph or faster." << endl;
		}
		else if (valid == 2)
		{
			cout << "The value you entered for temperature is invalid." << endl;
			cout << "Check to make sure the temperature" << endl;
			cout << "is 40 degrees or below." << endl;
			
		}
		else if (valid == 3)
		{
			cout << "The value you entered for windspeed is invalid. Check to make " << endl;
			cout << "sure the windspeed is 5 mph or faster." << endl;
		}

		cout << endl;
		cout << "Do another? y/n ";
		getline(cin, answer);
		cout << endl;

	} while (answer == "y");

	cout << "Goodbye" << endl << endl;

	return 0;
}
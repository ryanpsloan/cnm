// CIS1275 - Feridoon Ghanbari
// Ryan Sloan, rsloan2@cnm.edu
// SloanP4/WindChill.cpp

#include "WindChill.h"
#include <iostream>
#include <cmath>
using namespace std;

double askForTemperature()
{
	double temp;
	cout << "Enter a temperature at or below 40 deg F ==> ";
	cin >> temp;
	cin.ignore();
	cout << endl;
	return temp;
}

double askForWindSpeed()
{
	double wind;
	cout << "Enter the windspeed at or above 5 mph ==> ";
	cin >> wind;
	cin.ignore();
	cout << endl;
	return wind;
}

int validateTempWS(double temp, double windsp)
{
	if(temp <= 40 && windsp >= 5)
	{
		return 0;
	}
	else if(windsp < 5 && temp <= 40)
	{
		return 3;
	}
	else if(temp > 40 && windsp >= 5)
	{
		return 2;
	}
	else
	{
		return 1;
	}
}

double calcWindchill(double temp, double windsp)
{
	double windchillcalc = 35.74 + (0.6215 * temp) - (35.75 * pow(windsp, 0.16)) + ((0.4275 * temp) * pow(windsp, 0.16));
	return windchillcalc;
}

int determineFrostbiteTimes(double temp, double windsp)
{
	int fbt;
	fbt = ((-24.5 * ((0.667 * (windsp * 8.0/5)) + 4.8)) + 2111) * pow((-4.8 - ((temp - 32) * 5.0/9)), -1.668);
	
	if(fbt < 30)
	{
		return fbt;
	}
	else
	{
		return -1;
	}
	
}
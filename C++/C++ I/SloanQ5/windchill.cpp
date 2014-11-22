// Ryan Sloan rsloan2@cnm.edu
// Quiz 5
// windchill.cpp

// function definitions 

#include <iostream>
#include <string>
#include <cmath>
#include "windchill.h"

using namespace std;

//Error: the return type of the function defintion doesn't match the prototype, change int to void
void header()
{
	cout << "Ryan Sloan\n\n";
	cout << "This program will ask the user for a temperature and windspeed\n";
	cout << "and then calculate the windchill and time to frostbite based on\n";
	cout << "NOAA formulas.\n\n";
}

double askfortemperature()
{	
	double temp;

	cout << "What is the temperature: ";
	cin >> temp;
	return temp;

}//end askfortemperature

double askforwindspeed()
{	
	double wind;

	cout << "What is the windspeed: ";
	cin >> wind;
	return wind;

}//end askforwindspeed

//Make sure the temp is <= 40 and windspeed >= 5mph
//and return an integer indicating the result
int validatetempws(double temp, double windsp)
{	
	/*
	temp good, windsp good: 1
	temp good, windsp bad: -2
	temp bad, windsp good: -1
	temp bad, windsp bad:   0
	*/

	if (temp <= 40) //temp is in range
	{
		if (windsp >= 5) //windsp is in range and so is temp
			return 1;
		else             //windsp is out of range, temp is in range
			return -2;
	}
	else //temp > 40 (out of range)
	{
		if (windsp >= 5) //windsp in range, temp out of range
			return -1;
		else 
			return 0; //windsp and temp out of range
	}

}//end validatempws


//NOAA windchill formula
double calcwindchill(double temp, double windsp)//calculate windchill temp
{
	double wc;

	wc = 35.74 + (.6215 * temp) - (35.75 * pow(windsp, .16)) + (.4275 * temp * pow(windsp, .16));
	return wc;

}//end calcwindchill


//NOAA time to frostbite formula
//Error: the parameter values in a function definition need to be prefixed by a datatype
int determinefrostbitetimes(double temp,  double windsp)//calculate minutes to frostbite
{
	int fb;

	fb = ((-24.5 * ((.667 * (windsp * 8/5)) + 4.8)) + 2111) * pow((-4.8 - ((temp - 32) * 5/9)), -1.668);
	return fb;

}//end determinefrostbitetimes
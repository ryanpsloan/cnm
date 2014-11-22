// Ryan Sloan - rsloan2@cnm.edu
// Quiz 5 
// driver.cpp

#include <iostream>
#include <string>
#include <iomanip>
#include "windchill.h"

using namespace std;

/*call functions for input, validate the results, calculate windchill and frostbite time
  Possible validation codes:
	temp good, windsp good: 1
	temp good, windsp bad: -2
	temp bad, windsp good: -1
	temp bad, windsp bad:   0
  Also, check to see if frostbitetime is reasonable (>=0 and <=30mins)
*/
int main()
{
	char cond = 'y';
	int valid, frostbitetime;
	double windsp, temp, windchill;
	
	header();
	cout << fixed << showpoint << setprecision(2);

	while (cond == 'y')
	{
		temp = askfortemperature();
		windsp = askforwindspeed();
		valid = validatetempws(temp, windsp);

		switch (valid)
		{
		case -2:
			cout << "\nWind speed out of range\n\n";
			break;
		case -1:
			cout << "\nTemperature out of range\n\n";
			break;
		case 0:
			cout << "\nTemperature and windspeed out of range\n\n";
			break;
		case 1:										//Error: the parameter values are not prefixed by datatype in function calls, remove datatype
			frostbitetime = determinefrostbitetimes(temp,windsp);
			windchill = calcwindchill(temp, windsp);
			cout << "\nIf the temp is " << temp
													//Error: Remove \t and \n so output is clear
				<< " and the wind is blowing " << windsp << " it feels like " << windchill << " degrees \n";
			if (frostbitetime >= 0 && frostbitetime <= 30) //valid result
				cout << "and you can experience frostbite in " << frostbitetime << " minutes.\n\n";
			else //negative number returned means FB not imminent
				cout << "but there is no immediate threat of frostbite.\n\n";
		}//end switch
		
		cout << "Would you like to do another windchill/time to frostbite calculation? y/n  ";
		cin >> cond;
		cout << endl;

	}//end while

	return 0;

}
		


			
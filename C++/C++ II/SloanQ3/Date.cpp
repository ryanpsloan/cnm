//Date.cpp


#include <ctime>
#include <string>
#include <sstream>
#include <iostream>
#include "Date.h"
;using namespace std;

Date::Date()
{
	time_t SystemTime;
	time(&SystemTime);
	struct tm OSTime;
	errno_t err;
	err = localtime_s(&OSTime, &SystemTime);

	//SETTING CLASS VARIABLES TO THE CURRENT DATE
	month = OSTime.tm_mon; //removed + 1 to make the months match the indexies of the array
	day = OSTime.tm_mday;
	//changed variable to year from yr - yr is not a class variable
	year = OSTime.tm_year + 1900;


	//fill array with month names.
	MonthNames[0].assign("January");
	MonthNames[1].assign("February");
	MonthNames[2].assign("March");
	MonthNames[3].assign("April");
	MonthNames[4].assign("May");
	MonthNames[5].assign("June");
	MonthNames[6].assign("July");
	MonthNames[7].assign("August");
	MonthNames[8].assign("September");
	MonthNames[9].assign("October");
	MonthNames[10].assign("November");
	MonthNames[11].assign("December");
	
}	


Date::Date(int m, int d, int y)
{
	//ASSIGN THE INPUTTED DATE INTO THE CLASS VARS
	month = m - 1; //added -1 to coordinate the index number with the month number;
	day = d;
	year = y;
}



string Date::getFormattedDate()
{
	stringstream ss;
								//can't get MonthNames[month] to print when the value of month is 11
	ss << "\n The Date is: " << MonthNames[month] << " " << day << ", " << year << endl;
																					//added an endl;
	return ss.str();
	
}





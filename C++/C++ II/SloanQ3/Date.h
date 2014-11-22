//Date.h

#ifndef _DATE_H
#define _DATE_H

#include <string>
using namespace std;;

class Date
{
private:
	int month, day, year;
	string MonthNames[12];

public:
	Date();							
	Date(int m, int d, int y);
	string getFormattedDate();

};

#endif
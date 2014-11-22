//	Ryan Sloan	
//	Program 5 - CIS2275
//	Logger.h

#ifndef _LOGGER_H
#define _LOGGER_H
#include "stdafx.h"
#include "MoneyCtr.h"
#include "Dispenser.h"
#include <fstream>
#include <string>

using namespace std;

class Logger
{
private:
	string filename;
	char timeRightNow[20];
	char dateRightNow[20];
	bool bLogOpen;
	int hour, min, sec, day, month, year;

	ofstream output;
	void FileName();
	void TimeAndDate();
	

public:
	Logger();

	void StartLog(string s);
	void WriteLog(string s);
	void CloseLog(string s);

	bool IsLogOpen(){return bLogOpen;}
};


#endif
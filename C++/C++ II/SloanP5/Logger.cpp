//Ryan Sloan
//ryansdeal@hotmail.com
//Logger.cpp

#include "stdafx.h"
#include"Logger.h"
#include "Dispenser.h"
#include "MoneyCtr.h"
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
using namespace std;

void Logger::FileName()
{
	TimeAndDate();
	stringstream ss;
	ss << "Log_";
	ss << "Date_" << month << "_" << day << "_" << year + 1900 << "_";
	ss << "Time_" << hour << min;
	ss << ".txt";
	filename = ss.str();
}

void Logger::TimeAndDate()
{
	time_t SystemTime;
	time(&SystemTime);
	struct tm *OStime;
	OStime = localtime(&SystemTime);
	hour = OStime->tm_hour;
	min = OStime->tm_min;
	sec = OStime->tm_sec;
	month = OStime->tm_mon + 1;
	day = OStime->tm_mday;
	year = OStime->tm_year;
	_strtime_s(timeRightNow);
	_strdate_s(dateRightNow);
}
Logger::Logger()
{
	FileName();
	output.open(filename);
	if(!output)
	{
		bLogOpen = false;
	}
	TimeAndDate();
	output << timeRightNow << endl;
	bLogOpen = true;
}

void Logger::StartLog(string s)
{
	TimeAndDate();
	output << "Begin Log >> " << endl;
	output << s << endl;
}

void Logger::WriteLog(string s)
{
	TimeAndDate();
	output << timeRightNow << endl;
	output << s << endl;
	
}
void Logger::CloseLog(string s)
{
	TimeAndDate();
	output << timeRightNow << endl;
	output << s;
	output.close();
}

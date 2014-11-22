// CIS1275 - Feridoon Ghanbari
// Ryan Sloan - rsloan2@cnm.edu
// SloanP6/Parking.cpp

#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<fstream>
#include<ctime>
#include<sstream>

using namespace std;

void Header()
{
	cout << "Ryan Sloan" << endl;
	cout << "Program 6 - C++ Parking Garage" << endl;
	cout <<	"Pointers, References, Functions" << endl;
	cout <<	endl;
}

void AskTimeIn(int &hour, char &colon, int &minute)
{
	cout << "Welcome to the C++ Parking Garage " << endl;
	cout << "We are open from 4:00 to 23:59. " << endl;
	cout << "The cost to park is $2 per 30 minute interval. " << endl;
	cout << "Enter the time in 24 hr HH:MM format that you arrived at the garage -> ";
	cin >> hour >> colon >> minute;
	cin.ignore();
}

void ObtainTimeOut(int &outHour, int &outMin, int &month, int &day, int &year)
{
	time_t systemTime;
	time(&systemTime);
	struct tm *OStime;
	OStime = localtime(&systemTime);
	outHour = OStime-> tm_hour + 1;
	outMin = OStime-> tm_min;
	month = OStime -> tm_mon;
	day = OStime -> tm_mday;
	year = OStime -> tm_year + 1900;
	cout << "Current Time is " << outHour << ":" << outMin << endl;
}

bool ValidateTime(int inHour, int inMinute, int outHour, int outMin)
{
	if (inHour >= 4 && inHour < 24)
	{
		if(inMinute >= 0 && inMinute < 60)
		{
			int totalIn = inHour * 60 + inMinute;
			int totalOut = outHour * 60 + outMin;
			if (totalIn < totalOut)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
	
}

double CalculateFee(int &inHour, int &inMinute, int &outHour, int &outMin, int &totalHr, int &totalMin)
{
	
	if (inMinute > outMin)
	{
		int tempHour = outHour;
		int tempMin = outMin;
		tempHour--;
		tempMin += 60;
		totalMin = tempMin - inMinute;
		totalHr = tempHour - inHour;

	}
	else
	{
		totalMin = outMin - inMinute;
		totalHr = outHour - inHour;
	}
	int totalfee = 0;
	int totalMinStay = (totalHr * 60) + totalMin;
	int per30Min = totalMinStay/30;
	int partial = totalMinStay % 30;
	int per30interval = per30Min * 2;
	if (partial > 0 && partial < 30)
	{
		totalfee = per30interval + 2;
	}
	else
	{
		totalfee = per30interval;
	}
	return totalfee;
}

void WriteReceipt(int &inHour, int &inMinute, int &outHour, int &outMin, int &totalHr, int &totalMin, int month, int day, int year, double fee)
{
	stringstream ss;
	ss << inHour << "_" << inMinute << ".txt";
	string filename = ss.str();
	ofstream outData;
	outData.open(filename);
	if (!outData)
	{
		cout << "Unable to write to " << filename;
	}
	else
	{
		outData << "C++ International" << endl;
		outData << "     Airport     " << endl;
		outData << month << "/" << day << "/" << year << endl;
		outData << "Time in: " << inHour << ":" << inMinute << endl;
		outData << "Time out: " << outHour << ":" << outMin << endl;
		outData << endl;
		outData << "Total Time Parked" << endl;
		outData << totalHr << "HR and " << totalMin << "MIN" << endl;
		outData << endl;
		outData << "Fee" << setw(5) << "$" << fee << endl;
		outData << endl;
		outData << "HAVE A NICE DAY" << endl;
		outData << endl;
		cout << "Your receipt has been written to " << filename << endl;
	}
	outData.close();
}
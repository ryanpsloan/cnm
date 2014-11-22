// CIS1275 Feridoon Ghanbari
// Ryan Sloan - rsloan2@cnm.edu
// Program 7 SloanP7/Driver.cpp

#include <iostream>
#include <fstream>
#include <string>
#include "Functions.h"

using namespace std;


int main()
{
	string header[5];
	
	string columnheader[11];
	
	string carrierdateflighttaildestination[52][5];
	
	int scheduleddeparturetime[52][2];
	int actualdeparturetime[52][2];
	
	int elapsedtime[52][2];
	int calculateelapsedtime[52];
	string elapsed[52];
	
	string source;
	
	int calculateddepttime[52];
	int calculatedacttime[52];
	int finalvalues[52];
	string times[52];

	string filename = "ontime_summary_csv.txt";
	
	source = ReadData(filename, header, columnheader, carrierdateflighttaildestination, scheduleddeparturetime, actualdeparturetime, elapsedtime);
	CalculateDeparture(scheduleddeparturetime, actualdeparturetime, calculateddepttime, calculatedacttime, finalvalues);
	CalculateElapsed(elapsedtime,calculateelapsedtime);
	Coordinate(finalvalues,times,calculateelapsedtime,elapsed);
	Output(header,columnheader,carrierdateflighttaildestination,scheduleddeparturetime,actualdeparturetime,elapsedtime,source,times,elapsed,finalvalues,calculateelapsedtime);


	return 0;
}
// CIS1275 Feridoon Ghanbari
// Ryan Sloan - rsloan2@cnm.edu
// Program 7 SloanP7/Functions.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

string ReadData(string filename, string header[], string columnheader[], string carrierdateflighttaildestination[][5], int scheduleddeparturetime[][2], int actualdeparturetime[][2], int elapsedtime[][2])
{
	string source;
	ifstream inputStream;
	inputStream.open(filename);
	if (!inputStream)
	{
		cout << "Unable to Open the File " << filename << ".";
		exit(1);
	}
	else
	{
		for (int g = 0; g < 5; ++g)
		{
			getline(inputStream, header[g]);
		}
		for (int h = 0; h < 11; ++h)
		{
			getline(inputStream, columnheader[h],' ');
		}
		for (int i = 0; i < 52; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				inputStream >> carrierdateflighttaildestination[i][j];
			
			}
			char colon;
			for (int k = 0; k < 2; ++k)
			{
				if (k == 0)
				{
					inputStream >> scheduleddeparturetime[i][k] >> colon;
				}
				else
				{
					inputStream >> scheduleddeparturetime[i][k];
				}
					
			}
			for (int l = 0; l < 2; ++l)
			{
				if (l == 0)
				{
					inputStream >> actualdeparturetime[i][l] >> colon;
				}
				else
				{
					inputStream >> actualdeparturetime[i][l];
				}
					
			}
			for (int m = 0; m < 2; ++m)
			{
				inputStream >> elapsedtime[i][m];
			}
		}
		string empty;
		getline(inputStream, empty);
		getline(inputStream,source);
		inputStream.close();
	}	
	return source;
}

void CalculateDeparture(int scheduleddeparturetime[][2], int actualdeparturetime[][2], int calculateddepttime[], int calculatedacttime[], int finalvalues[])
{
	for (int i = 0; i < 52; ++i)
	{
		calculateddepttime[i] = (scheduleddeparturetime[i][0]*60) + scheduleddeparturetime[i][1];
		calculatedacttime[i] = (actualdeparturetime[i][0]*60) + actualdeparturetime[i][1];
	}

	for (int j = 0; j < 52; ++j)
	{
		finalvalues[j] = calculateddepttime[j] - calculatedacttime[j];
	}
}

void CalculateElapsed(int elapsedtime[][2], int calculateelapsedtime[])
{
	for (int i = 0; i < 52; ++i)
	{
		calculateelapsedtime[i] = elapsedtime[i][0] - elapsedtime[i][1];
	}
}

void Coordinate(int finalvalues[], string times[], int calculateelapsedtime[], string elapsed[])
{
	
	for (int i = 0; i < 52; ++i)
	{
		if (finalvalues[i] > 0)
			times[i] = "Early";
		else if (finalvalues[i]  == 0)
			times[i] = "On-Time";
		else if (finalvalues[i] < 0)
			times[i] = "Late";
	}
	
	for (int j = 0; j < 52; ++j)
	{
		if (calculateelapsedtime[j] > 0)
			elapsed[j] = "Early";
		else if (calculateelapsedtime[j] == 0)
			elapsed[j] = "On-Time";
		else if (calculateelapsedtime[j] < 0)
			elapsed[j] = "Late";
	}
}

void Output(string header[], string columnheader[], string carrierdateflighttaildestination[][5], int scheduleddeparturetime[][2], int actualdeparturetime[][2], int elapsedtime[][2], string source, string times[], string elapsed[], int finalvalues[], int calculateelapsedtime[])
{
		for (int g = 0; g < 5; ++g)
		{
			cout << header[g] << endl;
		}
		cout << setw(7) << "Carrier" << setw(5) << "Date" << setw(8) << "Flt_Num" << setw(9) << "Tail_Num" << setw(6) << "Dest " << setw(11) << "Sch_Depart " << setw(11) << "Act_Depart" << setw(11) << "Sch_Elapse" << setw(11) << "Act_Elapse" << endl;
		cout << endl;
		for (int i = 0; i < 52; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (j == 0)
				cout << setw(2) << carrierdateflighttaildestination[i][j] << " ";
				else if (j == 1)
				cout << setw(8) << carrierdateflighttaildestination[i][j];
				else if (j == 2)
				cout << setw(5) << carrierdateflighttaildestination[i][j] << " ";
				else if (j == 3)
				cout << setw(8
				) << carrierdateflighttaildestination[i][j];
				else if (j == 4)
				cout << setw(8) << carrierdateflighttaildestination[i][j] << " ";

			}
			for (int k = 0; k < 2; ++k)
			{	
				if (k == 0)
				cout << setw(2) << setfill('0') << scheduleddeparturetime[i][k] << ":";
				else
				cout << setw(2) << setfill('0') << scheduleddeparturetime[i][k] << " ";
			}
			for (int l = 0; l < 2; ++l)
			{
				if (l == 0)
				cout << setw(2) << setfill('0') << actualdeparturetime[i][l] << ":";
				else
				cout << setw(2) << setfill('0') << actualdeparturetime[i][l] << " ";

			}
			cout << setfill(' ') << setw(6) << times[i];
			for (int m = 0; m < 2; ++m)
			{
				cout << setw(6) << elapsedtime[i][m];
			} 
			cout << setw(5) << " " << elapsed[i] << endl;
			
		}
		cout << source << endl;

}




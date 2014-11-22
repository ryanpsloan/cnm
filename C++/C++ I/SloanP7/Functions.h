// CIS1275 Feridoon Ghanbari
// Ryan Sloan - rsloan2@cnm.edu
// Program 7 SloanP7/Functions.h

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string ReadData(string filename, string header[], string columnheader[], string carrierdateflighttaildestination[][5], int scheduleddeparturetime[][2], int actualdeparturetime[][2], int elapsedtime[][2]);
void CalculateDeparture(int scheduleddeparturetime[][2], int actualdeparturetime[][2], int calculateddepttime[], int calculatedacttime[], int finalvalues[]);
void CalculateElapsed(int elapsedtime[][2], int calculateelapsedtime[]);
void Coordinate(int finalvalues[], string times[], int calculateelapsedtime[], string elapsed[]);
void Output(string header[], string columnheader[], string carrierdateflighttaildestination[][5], int scheduleddeparturetime[][2], int actualdeparturetime[][2], int elapsedtime[][2], string source, string times[], string elapsed[], int finalvalues[], int calculateelapsedtime[]);
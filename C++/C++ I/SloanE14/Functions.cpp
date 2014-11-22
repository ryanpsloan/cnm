//Ryan Sloan - rsloan2@cnm.edu
//CIS1275 - Feridoon Ghanbari

//Chapter 6
//C++ Sorting Oak Leaves 
//Functions.cpp

#include "Functions.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;


bool ReadFile(double oakLeaves[],int &rTotal)
{
	ifstream Indata;
	Indata.open("OakLeaves.txt");
	if(!Indata)
	{
		return false;
	}
	else
	{
		char comma;
		while (!Indata.eof())
		{
			Indata >> oakLeaves[rTotal] >> comma;
			rTotal++;
		
		}
		Indata.close();
		return true;
	}
	
}
	
void Write(double oakLeaves[], int total, double aveSize)
{
	ofstream output;
	string filename;

	cout << "\n Please enter the name of the output file:  ";
	getline(cin,filename);
	output.open(filename.c_str() );

	output.setf(ios::fixed);
	output.precision(3);
	output<< "\n Oak Leave Results ";
	output << "\n\n Average value of our " << total << " leaves:  "
		<< aveSize;

	output << "\n\n The 3 smallest are: " ;
	for(int j = 0; j < 3; j++)	
	{
		output << oakLeaves[j] << "    ";
	}

	output << "\n\n The 3 largest are: " ;
	for(int j = total - 3; j < total; j++)	
	{
		output << oakLeaves[j] << "    ";
	}
	
	output<< "\n\n Not requested, but just to double check, \n here are the 25 sorted leaves\n";
	for(int j = 0; j < total; j++)	
	{
		output << setw(2) << j << ":  " << oakLeaves[j] << "\n";
	}

	output.close();

}

double FindAve(double oakLeaves[], int total)
{
	double sum = 0;
	double avg;

	for (int i = 0; i < total; ++i)
	{
		sum += oakLeaves[i];
	}

	avg = sum/total;
	return avg;
}


void SortOakLeaves(double oakLeaves[], int total)
{

	//This is a Bubble Sort
	int i,j;
	double temp;

	for(i = 0; i < total - 1; i++)
	{
		for(j = 1; j < total; ++j)
		{
			if(oakLeaves[j-1] > oakLeaves[j])
			{
				temp = oakLeaves[j];
				oakLeaves[j] = oakLeaves[j-1];
				oakLeaves[j-1] = temp;
			}
		}
	}
}


void WriteHeader()
{
//Opening greeting
	cout << "Welcome to the \"Sort the Oak leaves\" program!" << endl;
	cout << "\nThe object of this program is to take in 25 Oak " << endl;
	cout << "leaf sizes from a data file and then sort the data!" << endl;
}
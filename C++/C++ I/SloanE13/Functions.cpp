//Arrays_SearchIt
//This program will read in an array of up to
//300 ints and then sort it.  It will also ask
//the user for two ints, and search for them 
//in the sorted array.  It will return true or
//false for each int searched for.

//Functions.cpp

//Ryan Sloan - rsloan2@cnm.edu


#include <iostream>
#include <fstream>
using namespace std;

//writes header to screen
void Header()
{
	cout << "\n Review - Arrays, Files, Pointers\nSearch For Numbers"
		<< "\nSearches for two numbers in an integer array read from a file.";
}

//reads data from data file into an array
bool ReadFile(int nums[], int &rtotal)
{
	ifstream Indata;
	

	Indata.open("Numbers.txt");
	if(!Indata)
	{
		cout << "Error opening the file";
		return false;
	}
	else
	{
		while (!Indata.eof())
		{
			
			Indata >> nums[rtotal];
			rtotal++;
			
		}
		Indata.close();
		return true;
	}
}

//sorts data from file low to high
//using the Bubble Sort
void Sort(int nums[], int total)
{
	int i, j, temp;

	for(i = 0; i < (total - 1); i++)
	{
		for(j = 1; j < total; j++)
		{
			if(nums[j - 1] > nums[j])
			{
				temp = nums[j];
				nums[j] = nums[j - 1];
				nums[j - 1] = temp;
			}
		}
	}
}

//asks user for 2 integers to search for in the array
void Get2Integers(int &rn1, int &rn2)
{
	cout << "\n\n\nPlease enter the first number to search for: ";
	cin >> rn1;
	cout << "\n\nPlease enter the second number to search for: ";
	cin >> rn2;
}

//searches the array of numbers for the numbers entered by the user
void SearchIt(int nums[], int total, int n1, int n2, bool &rsearch1, bool &rsearch2)
{
	for (int i = 0; i < total; ++i)
	{
		if(n1 == nums[i])
		{
			rsearch1 = true;
		}
	}
	
	for (int i = 0; i < total; ++i)
	{
		if(n2 == nums[i])
		{
			rsearch2 = true;
		}
	}
}
	





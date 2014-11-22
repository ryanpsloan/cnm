//Arrays_SearchIt
//This program will read in an array of up to
//300 ints and then sort it.  It will also ask
//the user for two ints, and search for them 
//in the sorted array.  It will return true or
//false for each int searched for.

//Make a folder using your name and the exercise number
//such as GhanbariE13.  Put this project into that
//folder. 

//Your assignment is to go the Functions.cpp file, and
//write the code for the ReadFile and SearchIt functions
//Then make sure the program runs properly.

//As usual, drop your project, LastnameE13, in the Assignments
//folder on the I-Drive.  Print a copy of the Functions.cpp,
//Make sure you name is ON THE TOP, and hand it in to me.

//Driver.cpp

//Ryan Sloan - rsloan2@cnm.edu

#include <iostream>
#include <string>
#include "Functions.h"
using namespace std;

int main()
{
	const int TOTAL = 300;
	int total = 0;
	int nums[TOTAL], n1, n2;
	bool bOK, search1 = false, search2 = false;
	string cont;

	Header();
	bOK = ReadFile(nums, total);

	//check to see if file opened - exit if no file
	if(! bOK)
	{
		cout << "\n\nNo File Found! Exiting...\n\n";
		exit(1);
	}

	cout << "\n\nTotal number of integers read from file: " << total;

	Sort(nums, total);

	//do while loop to continue searching for numbers in array
	do
	{
		Get2Integers(n1, n2);
		SearchIt(nums, total, n1, n2, search1, search2);
	
		if(search1 == true)
		{
			cout << "\n\nThe number " << n1 << " was found in the data file!";
		}
		else
		{
			cout << "\n\nThe number " << n1 << " was not found in the data file.";
		}

		if(search2 == true)
		{
			cout << "\n\n\nThe number " << n2 << " was found in the data file!\n\n";
		}
		else
		{
			cout << "\n\n\nThe number " << n2 << " was not found in the data file.\n\n";
		}

		cout << "\nWould you like to go again (yes/no)? ";
		cin >> cont;
	}while(cont == "yes");

	cout << "\n\n\nGOODBYE!!!\n\n\n\n";

	return 0;
}

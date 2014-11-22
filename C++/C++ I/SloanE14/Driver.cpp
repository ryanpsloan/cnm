//Ryan Sloan - rsloan2@cnm.edu
//CIS1275 - Feridoon Ghanbari

//Chapter 6
//C++ Sorting Oak Leaves 
//Driver.cpp

/*Please  make a new folder named LastNameE14 and place this project inside it.
As usual, drop the folder in the appropriate place on the I-Drive.
Please print all three files and staple them together, with the Driver (this file) on the top. 
Make sure you put your name at the top of ALL three files.

The program is mostly written.  Your job is to write the body of two functions:
the ReadFile function and the FindAve function.

The rest of the program works fine, so once you get those files written, it will run.
The file to be read is in this project and is called OakLeaves.txt  Do not make one up.*/


#include "Functions.h"
#include <iostream>
using namespace std;

int main()
{
	double oakLeaves[25];

	WriteHeader();
	int total = 0;
	bool ok = ReadFile(oakLeaves,total);

	if(!ok)
	{
		cout << "\n Whoops, couldn't find the file. "
			<< "\n Exiting program. Bye. \n ";
		exit(1);
	}

	double aveSize = FindAve(oakLeaves, total);
	
	SortOakLeaves(oakLeaves,total);

	Write(oakLeaves, total, aveSize);

	cout << "\n All finished with the leaves.  Bye! \n\n";
	return 0;
}


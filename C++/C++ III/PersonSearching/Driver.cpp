//Ryan Sloan
//C++ III Program 3 - Searching
//Barbara Johnston

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "PersonSort.h"
#include "SloanPersonGen\PersonGen.h"
#include "SloanPersonGen\Person.h"
#include "SloanPersonGen\Date.h"
#include "Search.h"


using namespace std;

int main()
{
	stringstream ss;
	string logName = "Sloan_Oct9_Log.txt"; 
	
	//cout << "Enter a File Name i.e. 'PersonLog1.txt': ";
	//cin >> logName;
	//cin.ignore();
	cout << endl << endl;

	cout << "Ryan Sloan" << "                              " << "Log filename: " << logName << endl << endl;
	ss << "Ryan Sloan" << "                              " << "Log filename: " << logName << endl << endl;

	Person pArr[1000];
	int size = 1000;
	PersonGen pGen;
	string fileName = "Oct9-2013Test.txt";
	//Opens the file to read
	bool isOpen = pGen.useFile(fileName);
	if (isOpen)
	{
		cout << "File is Open, Using " << fileName << endl << endl;
		ss << "File is Open, Using " << fileName << endl << endl;

	}
	else
	{
		cout << "Unable to Open File, Randomly Generating" << endl << endl;
		ss << "Unable to Open File, Randomly Generating" << endl << endl;
	}
	
	for (int i = 0; i < size; ++i)
	{
		pArr[i] = pGen.getPerson();
	}
	for (int i = 0; i < 20; ++i)
	{
		cout << pArr[i].getFullDesc() << endl;
		ss << pArr[i].getFullDesc() << endl;
	}
	
	//Array created and filled data is outputed
	cout << "-------------------------------------------" << endl;
	
	PersonSort pSort;
	pSort.shellSort(pArr, size);
	//Sorts pArr

	//Outputs Sorted pArr
	/*for(int i = 0; i < size; ++i)
	{
		cout << (i + 1) << pArr[i].getFullDesc() << endl;
		ss << (i + 1) << pArr[i].getFullDesc() << endl;
		
	
	}*/
	
	//Searches pArr for specified name using three search algorithms
	char choice = 'N';
	do 
	{	
		cout << endl;
		string target;
		int position = 0;
		int *pPosition = &position;
		int numComp = 0;
		int *pNumCompares = &numComp;
		cout << "Enter a name to search for i.e. LAST, FIRST: ";
		ss << endl << "Enter a name to search for: " << endl;
		getline(cin, target);
		ss << target << endl << endl;
		cout << "Searching for: " << target << endl;
		cout << endl;
		//Runs sequential search function
		bool seqSearch = SequentialSearch(pArr, size, target, pPosition, pNumCompares);
		if (seqSearch)
		{
			cout << "Sequential Search" << "                   " << target << " was found at position " << *pPosition << endl;
			cout << "                                          " << "Number of Compares " << *pNumCompares << endl << endl;
			ss << "Sequential Search" << "                   " << target << " was found at position " << *pPosition << endl;
			ss << "                                          " << "Number of Compares " << *pNumCompares << endl << endl;
		}
		else
		{
			cout << "Sequential Search" << "                   " << target << " wasn't found" << endl;
			cout << "                                          " << "Number of Compares " << *pNumCompares << endl << endl;
			ss << "Sequential Search" << "                   " << target << " wasn't found" << endl;
			ss << "                                          " << "Number of Compares " << *pNumCompares << endl << endl;
		}
		//Runs binary search function
		bool binSearch = BinarySearch(pArr, size, target, pPosition, pNumCompares);
		if (binSearch)
		{
			cout << "Binary Search" << "                       " << target << " was found at position " << *pPosition << endl;
			cout << "                                          " << "Number of Compares " << *pNumCompares << endl << endl;
			ss << "Binary Search" << "                       " << target << " was found at position " << *pPosition << endl;
			ss << "                                          " << "Number of Compares " << *pNumCompares << endl << endl;
		}
		else
		{
			cout << "Binary Search" << "                       " << target << " wasn't found" << endl;
			cout << "                                          " << "Number of Compares " << *pNumCompares << endl << endl;
			ss << "Binary Search" << "                       " << target << " wasn't found" << endl;
			ss << "                                          " << "Number of Compares " << *pNumCompares << endl << endl;
		}
		//Runs recursive binary search function
		bool recSearch = RunRecursiveSearch(pArr, size, target, pPosition, pNumCompares);
		if (recSearch)
		{
			cout << "Recursive Search" << "                    " << target << " was found at position " << *pPosition << endl;
			cout << "                                          " << "Number of Compares " << *pNumCompares << endl << endl;
			ss << "Recursive Search" << "                    " << target << " was found at position " << *pPosition << endl;
			ss << "                                          " << "Number of Compares " << *pNumCompares << endl << endl;
		}
		else
		{
			cout << "Recursive Search" << "                    " << target << " wasn't found" << endl;
			cout << "                                          " << "Number of Compares " << *pNumCompares << endl << endl;
			ss << "Recursive Search" << "                    " << target << " wasn't found" << endl;
			ss << "                                          " << "Number of Compares " << *pNumCompares << endl << endl;
		}
		//Tests to see if user would like to perform another search
		cout << "Would you like to search another name? Enter Y/N: ";
		cin >> choice;
		cin.ignore();


	} while (choice == 'Y');
	//Log Output
	ofstream logFile;
	logFile.open(logName,ios::app);
	if (logFile)
	{
		cout << "Log has been created at " << logName << endl;
		logFile << ss.str();
		logFile.close();
	}
	else
	{
		cout << "Log was not created." << endl;
	}
	//end
	cout << endl;
	cout << "-------EXITING-------" << endl;

	return 0;
}
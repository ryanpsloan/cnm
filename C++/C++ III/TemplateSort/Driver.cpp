#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "TemplateSort.h"
#include "SloanPersonGen\PersonGen.h"

using namespace std;

#define INTSIZE 200000
#define STRSIZE 25000
#define PERSIZE 2000
#define INTFILE "BJTest200K.txt"
#define STRFILE "BJName25000.txt"
#define PERFILE "BJ_Persons2000.txt"


int main()
{	
	string outputName;
	cout << "Enter a FileName for the Output File include '.txt' on the end: ";
	getline(cin, outputName);
	stringstream ss, ss1, ss2;
	ifstream readFileInt, readFileStr;
	//opening file
	readFileInt.open(INTFILE);
	readFileStr.open(STRFILE);
	if (readFileInt) {
		cout << "Reading Int Data from File... " << "\n" << endl;
	}
	else{
		cout << "Unable to Read Int File \n" << endl;
	}
	if (readFileStr) {
		cout << "Reading Str Data from File... " << "\n" << endl;
	}
	else {
		cout << "Unable to Read Str File \n" << endl;
	}
		clock_t start, stop;
	//declare the sorters
		Sort<int> intSorter;      //sorter for integers
		Sort<string> strSorter;	//sorter for strings
		Sort<Person> perSorter;	//sorter for Persons
	//create the arrays
		//int array
		int *intArr = new int[INTSIZE];
		int *intDummyArr = new int[INTSIZE];
		
		for (int i = 0; i < INTSIZE; ++i)
		{
			string temp;
			getline(readFileInt, temp);
			int conversion = atoi(temp.c_str());
			intArr[i] = conversion; 
			intDummyArr[i] = intArr[i];
			
		}
		readFileInt.close();
		//string array
		string *strArr = new string[STRSIZE];
		string *strDummyArr = new string[STRSIZE];
		string temp;
		for (int i = 0; i < STRSIZE; ++i) 
		{
			getline(readFileStr, temp);
			strArr[i] = temp;
			strDummyArr[i] = strArr[i];
		}
		readFileStr.close();
		//Person Array
		cout << "Creating Persons..." << endl;
		Person *perArr = new Person[PERSIZE];
		Person *perDummyArr = new Person[PERSIZE];
		PersonGen *pg = new PersonGen();
		pg->useFile(PERFILE);
		for (int i = 0; i < PERSIZE; ++i) 
		{
			perArr[i] = pg->getPerson();
			perDummyArr[i] = perArr[i];
		}
		
		int diff_in_msec;
		double numOfSeconds;
		string sortName;

//begin bubblesort
		cout << "Bubble ------------------------ " << endl;
	//Display Int Array
		cout << "Unsorted Int Array..." << endl;
		cout << "First 10 and Last 10 Values...\n" << endl;
		for(int i = 0; i < 10; ++i)
		{
			if(i == 0) {
				cout << "First 10..." << endl;
			}
			cout << intArr[i] << endl;
			
		}
		cout << endl;
		for(int i = 199990; i < INTSIZE; ++i)
		{
			if(i == 199990) {
				cout << "Last 10..." << endl;
			}
			cout << intArr[i] << endl;
			
		}
		cout << "===========================" << endl;
	//Start BubbleSort
		sortName = "BubbleSort Int  ";
		cout << "Starting " << sortName << "-----------------------" << endl;
		start = clock();
		intSorter.BubbleSort(intArr, INTSIZE);
		stop = clock();
		diff_in_msec = (int) (stop - start);
		numOfSeconds = (diff_in_msec/1000) + ((diff_in_msec % 1000)/1000.00);
		cout << sortName << "                       " <<  diff_in_msec << " : " << numOfSeconds << endl << endl;
		ss << sortName << "                       " <<  diff_in_msec << " : " << numOfSeconds << endl;
		
	//Display Sorted Array
		cout << "Sorted Int Array..." << endl;
		cout << "First 10 and Last 10 Values...\n" << endl;
		for(int i = 0; i < 10; ++i)
		{
			if(i == 0) {
				cout << "First 10..." << endl;
			}
			cout << intArr[i] << endl;
			
		}
		cout << endl;
		for(int i = 199990; i < INTSIZE; ++i)
		{
			if(i == 199990) {
				cout << "Last 10..." << endl;
			}
			
			cout << intArr[i] << endl;
		}
		cout << "===========================" << endl;
	
		cout << "*********************************" << endl;
		cout << "\n\n";
		
	//Display Str Array
		cout << "Unsorted Str Array..." << endl;
		cout << "First 10 and Last 10 Values...\n" << endl;
		for(int i = 0; i < 10; ++i)
		{
			if(i == 0) {
				cout << "First 10..." << endl;
			}
			
			cout << strArr[i] << endl;
			if(i == 9) {
				cout << endl;
			}
		}
		
		for(int i = 24990; i < STRSIZE; ++i)
		{
			if(i == 24990) {
				cout << "Last 10..." << endl;
			}
			cout << strArr[i] << endl;
			
		}
		cout << "===========================" << endl;
	//Sort Str
		sortName = "BubbleSort Str  ";
		cout << "Starting " << sortName << "-----------------------" << endl;
		start = clock();
		strSorter.BubbleSort(strArr, STRSIZE);
		stop = clock();
		diff_in_msec = (int) (stop - start);
		numOfSeconds = (diff_in_msec/1000) + ((diff_in_msec % 1000)/1000.00);
		cout << sortName << "                       " <<  diff_in_msec << " : " << numOfSeconds << endl << endl;
		ss1 << sortName << "                       " <<  diff_in_msec << " : " << numOfSeconds << endl;
		cout << "Sorted Str Array..." << endl;
		cout << "First 10 and Last 10 Values...\n" << endl;
		for(int i = 0; i < 10; ++i)
		{
			if(i == 0) {
				cout << "First 10..." << endl;
			}
			cout << strArr[i] << endl;
			if(i == 9)
			{
				cout << endl;
			}
		}
		
		for(int i = 24990; i < STRSIZE; ++i)
		{
			if(i == 24990) {
				cout << "Last 10..." << endl;
			}
			cout << strArr[i] << endl;

			
		}
		cout << "===========================" << endl;
		cout << "\n\n";
		cout << "*********************************" << endl;
	//Display Person Array
		cout << "Unsorted Person Array..." << endl;
		cout << "First 10 and Last 10 Values...\n" << endl;
		for(int i = 0; i < 10; ++i)
		{
			if(i == 0) {
				cout << "First 10..." << endl;
			}
			cout << perArr[i].getName() << endl;
			if(i == 9) {
				cout << endl;
			}
			
		}
		
		for(int i = 9990; i < PERSIZE; ++i)
		{
			if(i == 9990) {
				cout << "Last 10..." << endl;
			}
			cout << perArr[i].getName() << endl;

			
		}
		cout << "===========================" << endl;
	//Sort Person
		sortName = "BubbleSort Person ";
		cout << "Starting " << sortName << "-----------------------" << endl;
		start = clock();
		perSorter.BubbleSort(perArr, PERSIZE);
		stop = clock();
		diff_in_msec = (int) (stop - start);
		numOfSeconds = (diff_in_msec/1000) + ((diff_in_msec % 1000)/1000.00);
		cout << sortName << "                       " <<  diff_in_msec << " : " << numOfSeconds << endl << endl;
		ss2 << sortName << "                       " <<  diff_in_msec << " : " << numOfSeconds << endl;
		cout << "Sorted Person Array..." << endl;
		cout << "First 10 and Last 10 Values..." << endl;
		for(int i = 0; i < 10; ++i)
		{
			if(i == 0) {
				cout << "First 10..." << endl;
			}
			cout << perArr[i].getName() << endl;
			if (i == 9) {
				cout << endl;
			}
		}
		
		for(int i = 9990; i < PERSIZE; ++i)
		{
			if(i == 9990) {
				cout << "Last 10..." << endl;
			}
			cout << perArr[i].getName() << endl;
			
		}
		cout << "===========================" << endl;
		cout << "\n\n";
	//refill the array for a new sort
		cout << "Copying " << INTSIZE << " numbers from the Temp Int Array . . ." << endl;
		
		for (int i = 0; i < INTSIZE; ++i)
		{
			
			intArr[i] = intDummyArr[i];
			
		}
		cout << "Copying " << STRSIZE << " strings from the Temp Str Array . . ." << endl;
		
		for (int i = 0; i < STRSIZE; ++i) 
		{
			strArr[i] = strDummyArr[i];
		}
		
		cout << "Copying " << PERSIZE << " Persons from the Temp Per Array . . ." << endl;
		for (int i = 0; i < PERSIZE; ++i) 
		{
			perArr[i] = perDummyArr[i];
		}
		cout << "\n\n";

//begin comb11sort
		cout << "Comb11 ------------------------ " << endl;
	//Display Int Array
		cout << "Unsorted Int Array..." << endl;
		cout << "First 10 and Last 10 Values...\n" << endl;
		for(int i = 0; i < 10; ++i)
		{
			if(i == 0) {
				cout << "First 10..." << endl;
			}
			cout << intArr[i] << endl;
			
		}
		cout << endl;
		for(int i = 199990; i < INTSIZE; ++i)
		{
			if(i == 199990) {
				cout << "Last 10..." << endl;
			}
			cout << intArr[i] << endl;
			
		}
		cout << "===========================" << endl;
	//Start Sort
		sortName = "Comb11Sort Int  ";
		cout << "Starting " << sortName << "-----------------------" << endl;
		start = clock();
		intSorter.Comb11Sort(intArr, INTSIZE);
		stop = clock();
		diff_in_msec = (int) (stop - start);
		numOfSeconds = (diff_in_msec/1000) + ((diff_in_msec % 1000)/1000.00);
		cout << sortName << "                       " <<  diff_in_msec << " : " << numOfSeconds << endl << endl;
		ss << sortName << "                       " <<  diff_in_msec << " : " << numOfSeconds << endl;
		
	//Display Sorted Array
		cout << "Sorted Int Array..." << endl;
		cout << "First 10 and Last 10 Values...\n" << endl;
		for(int i = 0; i < 10; ++i)
		{
			if(i == 0) {
				cout << "First 10..." << endl;
			}
			cout << intArr[i] << endl;
			
		}
		cout << endl;
		for(int i = 199990; i < INTSIZE; ++i)
		{
			if(i == 199990) {
				cout << "Last 10..." << endl;
			}
			
			cout << intArr[i] << endl;
		}
		cout << "===========================" << endl;
	
		cout << "*********************************" << endl;
		cout << "\n\n";
		
	//Display Str Array
		cout << "Unsorted Str Array..." << endl;
		cout << "First 10 and Last 10 Values...\n" << endl;
		for(int i = 0; i < 10; ++i)
		{
			if(i == 0) {
				cout << "First 10..." << endl;
			}
			
			cout << strArr[i] << endl;
			if(i == 9) {
				cout << endl;
			}
		}
		
		for(int i = 24990; i < STRSIZE; ++i)
		{
			if(i == 24990) {
				cout << "Last 10..." << endl;
			}
			cout << strArr[i] << endl;
			
		}
		cout << "===========================" << endl;
	//Sort Str
		sortName = "Comb11Sort Str  ";
		cout << "Starting " << sortName << "-----------------------" << endl;
		start = clock();
		strSorter.Comb11Sort(strArr, STRSIZE);
		stop = clock();
		diff_in_msec = (int) (stop - start);
		numOfSeconds = (diff_in_msec/1000) + ((diff_in_msec % 1000)/1000.00);
		cout << sortName << "                       " <<  diff_in_msec << " : " << numOfSeconds << endl << endl;
		ss1 << sortName << "                       " <<  diff_in_msec << " : " << numOfSeconds << endl;
		cout << "Sorted Str Array..." << endl;
		cout << "First 10 and Last 10 Values...\n" << endl;
		for(int i = 0; i < 10; ++i)
		{
			if(i == 0) {
				cout << "First 10..." << endl;
			}
			cout << strArr[i] << endl;
			if(i == 9)
			{
				cout << endl;
			}
		}
		
		for(int i = 24990; i < STRSIZE; ++i)
		{
			if(i == 24990) {
				cout << "Last 10..." << endl;
			}
			cout << strArr[i] << endl;

			
		}
		cout << "===========================" << endl;
		cout << "\n\n";
		cout << "*********************************" << endl;
	//Display Person Array
		cout << "Unsorted Person Array..." << endl;
		cout << "First 10 and Last 10 Values...\n" << endl;
		for(int i = 0; i < 10; ++i)
		{
			if(i == 0) {
				cout << "First 10..." << endl;
			}
			cout << perArr[i].getName() << endl;
			if(i == 9) {
				cout << endl;
			}
			
		}
		
		for(int i = 9990; i < PERSIZE; ++i)
		{
			if(i == 9990) {
				cout << "Last 10..." << endl;
			}
			cout << perArr[i].getName() << endl;

			
		}
		cout << "===========================" << endl;
	//Sort Person
		sortName = "Comb11Sort Person ";
		cout << "Starting " << sortName << "-----------------------" << endl;
		start = clock();
		perSorter.Comb11Sort(perArr, PERSIZE);
		stop = clock();
		diff_in_msec = (int) (stop - start);
		numOfSeconds = (diff_in_msec/1000) + ((diff_in_msec % 1000)/1000.00);
		cout << sortName << "                       " <<  diff_in_msec << " : " << numOfSeconds << endl << endl;
		ss2 << sortName << "                       " <<  diff_in_msec << " : " << numOfSeconds << endl;
		cout << "Sorted Person Array..." << endl;
		cout << "First 10 and Last 10 Values..." << endl;
		for(int i = 0; i < 10; ++i)
		{
			if(i == 0) {
				cout << "First 10..." << endl;
			}
			cout << perArr[i].getName() << endl;
			if (i == 9) {
				cout << endl;
			}
		}
		
		for(int i = 9990; i < PERSIZE; ++i)
		{
			if(i == 9990) {
				cout << "Last 10..." << endl;
			}
			cout << perArr[i].getName() << endl;
			
		}
		cout << "===========================" << endl;
		cout << "\n\n";
	//refill the array for a new sort
		cout << "Copying " << INTSIZE << " numbers from the Temp Int Array . . ." << endl;
		
		for (int i = 0; i < INTSIZE; ++i)
		{
			
			intArr[i] = intDummyArr[i];
			
		}
		cout << "Copying " << STRSIZE << " strings from the Temp Str Array . . ." << endl;
		
		for (int i = 0; i < STRSIZE; ++i) 
		{
			strArr[i] = strDummyArr[i];
		}
		
		cout << "Copying " << PERSIZE << " Persons from the Temp Per Array . . ." << endl;
		for (int i = 0; i < PERSIZE; ++i) 
		{
			perArr[i] = perDummyArr[i];
		}
		cout << "\n\n";

//begin insertionsort
		cout << "Insertion ------------------------ " << endl;
	//Display Int Array
		cout << "Unsorted Int Array..." << endl;
		cout << "First 10 and Last 10 Values...\n" << endl;
		for(int i = 0; i < 10; ++i)
		{
			if(i == 0) {
				cout << "First 10..." << endl;
			}
			cout << intArr[i] << endl;
			
		}
		cout << endl;
		for(int i = 199990; i < INTSIZE; ++i)
		{
			if(i == 199990) {
				cout << "Last 10..." << endl;
			}
			cout << intArr[i] << endl;
			
		}
		cout << "===========================" << endl;
	//Start Sort
		sortName = "InsertionSort Int  ";
		cout << "Starting " << sortName << "-----------------------" << endl;
		start = clock();
		intSorter.InsertionSort(intArr, INTSIZE);
		stop = clock();
		diff_in_msec = (int) (stop - start);
		numOfSeconds = (diff_in_msec/1000) + ((diff_in_msec % 1000)/1000.00);
		cout << sortName << "                       " <<  diff_in_msec << " : " << numOfSeconds << endl << endl;
		ss << sortName << "                    " <<  diff_in_msec << " : " << numOfSeconds << endl;
		
	//Display Sorted Array
		cout << "Sorted Int Array..." << endl;
		cout << "First 10 and Last 10 Values...\n" << endl;
		for(int i = 0; i < 10; ++i)
		{
			if(i == 0) {
				cout << "First 10..." << endl;
			}
			cout << intArr[i] << endl;
			
		}
		cout << endl;
		for(int i = 199990; i < INTSIZE; ++i)
		{
			if(i == 199990) {
				cout << "Last 10..." << endl;
			}
			
			cout << intArr[i] << endl;
		}
		cout << "===========================" << endl;
	
		cout << "*********************************" << endl;
		cout << "\n\n";
		
	//Display Str Array
		cout << "Unsorted Str Array..." << endl;
		cout << "First 10 and Last 10 Values...\n" << endl;
		for(int i = 0; i < 10; ++i)
		{
			if(i == 0) {
				cout << "First 10..." << endl;
			}
			
			cout << strArr[i] << endl;
			if(i == 9) {
				cout << endl;
			}
		}
		
		for(int i = 24990; i < STRSIZE; ++i)
		{
			if(i == 24990) {
				cout << "Last 10..." << endl;
			}
			cout << strArr[i] << endl;
			
		}
		cout << "===========================" << endl;
	//Sort Str
		sortName = "InsertionSort Str  ";
		cout << "Starting " << sortName << "-----------------------" << endl;
		start = clock();
		strSorter.InsertionSort(strArr, STRSIZE);
		stop = clock();
		diff_in_msec = (int) (stop - start);
		numOfSeconds = (diff_in_msec/1000) + ((diff_in_msec % 1000)/1000.00);
		cout << sortName << "                       " <<  diff_in_msec << " : " << numOfSeconds << endl << endl;
		ss1 << sortName << "                    " <<  diff_in_msec << " : " << numOfSeconds << endl;
		cout << "Sorted Str Array..." << endl;
		cout << "First 10 and Last 10 Values...\n" << endl;
		for(int i = 0; i < 10; ++i)
		{
			if(i == 0) {
				cout << "First 10..." << endl;
			}
			cout << strArr[i] << endl;
			if(i == 9)
			{
				cout << endl;
			}
		}
		
		for(int i = 24990; i < STRSIZE; ++i)
		{
			if(i == 24990) {
				cout << "Last 10..." << endl;
			}
			cout << strArr[i] << endl;

			
		}
		cout << "===========================" << endl;
		cout << "\n\n";
		cout << "*********************************" << endl;
	//Display Person Array
		cout << "Unsorted Person Array..." << endl;
		cout << "First 10 and Last 10 Values...\n" << endl;
		for(int i = 0; i < 10; ++i)
		{
			if(i == 0) {
				cout << "First 10..." << endl;
			}
			cout << perArr[i].getName() << endl;
			if(i == 9) {
				cout << endl;
			}
			
		}
		
		for(int i = 9990; i < PERSIZE; ++i)
		{
			if(i == 9990) {
				cout << "Last 10..." << endl;
			}
			cout << perArr[i].getName() << endl;

			
		}
		cout << "===========================" << endl;
	//Sort Person
		sortName = "InsertionSort Person ";
		cout << "Starting " << sortName << "-----------------------" << endl;
		start = clock();
		perSorter.InsertionSort(perArr, PERSIZE);
		stop = clock();
		diff_in_msec = (int) (stop - start);
		numOfSeconds = (diff_in_msec/1000) + ((diff_in_msec % 1000)/1000.00);
		cout << sortName << "                       " <<  diff_in_msec << " : " << numOfSeconds << endl << endl;
		ss2 << sortName << "                    " <<  diff_in_msec << " : " << numOfSeconds << endl;
		cout << "Sorted Person Array..." << endl;
		cout << "First 10 and Last 10 Values..." << endl;
		for(int i = 0; i < 10; ++i)
		{
			if(i == 0) {
				cout << "First 10..." << endl;
			}
			cout << perArr[i].getName() << endl;
			if (i == 9) {
				cout << endl;
			}
		}
		
		for(int i = 9990; i < PERSIZE; ++i)
		{
			if(i == 9990) {
				cout << "Last 10..." << endl;
			}
			cout << perArr[i].getName() << endl;
			
		}
		cout << "===========================" << endl;
		cout << "\n\n";
	//refill the array for a new sort
		cout << "Copying " << INTSIZE << " numbers from the Temp Int Array . . ." << endl;
		
		for (int i = 0; i < INTSIZE; ++i)
		{
			
			intArr[i] = intDummyArr[i];
			
		}
		cout << "Copying " << STRSIZE << " strings from the Temp Str Array . . ." << endl;
		
		for (int i = 0; i < STRSIZE; ++i) 
		{
			strArr[i] = strDummyArr[i];
		}
		
		cout << "Copying " << PERSIZE << " Persons from the Temp Per Array . . ." << endl;
		for (int i = 0; i < PERSIZE; ++i) 
		{
			perArr[i] = perDummyArr[i];
		}
		cout << "\n\n";
		
//begin selectionsort
		cout << "Selection ------------------------ " << endl;
	//Display Int Array
		cout << "Unsorted Int Array..." << endl;
		cout << "First 10 and Last 10 Values...\n" << endl;
		for(int i = 0; i < 10; ++i)
		{
			if(i == 0) {
				cout << "First 10..." << endl;
			}
			cout << intArr[i] << endl;
			
		}
		cout << endl;
		for(int i = 199990; i < INTSIZE; ++i)
		{
			if(i == 199990) {
				cout << "Last 10..." << endl;
			}
			cout << intArr[i] << endl;
			
		}
		cout << "===========================" << endl;
	//Start Sort
		sortName = "SelectionSort Int  ";
		cout << "Starting " << sortName << "-----------------------" << endl;
		start = clock();
		intSorter.SelectionSort(intArr, INTSIZE);
		stop = clock();
		diff_in_msec = (int) (stop - start);
		numOfSeconds = (diff_in_msec/1000) + ((diff_in_msec % 1000)/1000.00);
		cout << sortName << "                       " <<  diff_in_msec << " : " << numOfSeconds << endl << endl;
		ss << sortName << "                    " <<  diff_in_msec << " : " << numOfSeconds << endl;
		
	//Display Sorted Array
		cout << "Sorted Int Array..." << endl;
		cout << "First 10 and Last 10 Values...\n" << endl;
		for(int i = 0; i < 10; ++i)
		{
			if(i == 0) {
				cout << "First 10..." << endl;
			}
			cout << intArr[i] << endl;
			
		}
		cout << endl;
		for(int i = 199990; i < INTSIZE; ++i)
		{
			if(i == 199990) {
				cout << "Last 10..." << endl;
			}
			
			cout << intArr[i] << endl;
		}
		cout << "===========================" << endl;
	
		cout << "*********************************" << endl;
		cout << "\n\n";
		
	//Display Str Array
		cout << "Unsorted Str Array..." << endl;
		cout << "First 10 and Last 10 Values...\n" << endl;
		for(int i = 0; i < 10; ++i)
		{
			if(i == 0) {
				cout << "First 10..." << endl;
			}
			
			cout << strArr[i] << endl;
			if(i == 9) {
				cout << endl;
			}
		}
		
		for(int i = 24990; i < STRSIZE; ++i)
		{
			if(i == 24990) {
				cout << "Last 10..." << endl;
			}
			cout << strArr[i] << endl;
			
		}
		cout << "===========================" << endl;
	//Sort Str
		sortName = "SelectionSort Str  ";
		cout << "Starting " << sortName << "-----------------------" << endl;
		start = clock();
		strSorter.SelectionSort(strArr, STRSIZE);
		stop = clock();
		diff_in_msec = (int) (stop - start);
		numOfSeconds = (diff_in_msec/1000) + ((diff_in_msec % 1000)/1000.00);
		cout << sortName << "                       " <<  diff_in_msec << " : " << numOfSeconds << endl << endl;
		ss1 << sortName << "                    " <<  diff_in_msec << " : " << numOfSeconds << endl;
		cout << "Sorted Str Array..." << endl;
		cout << "First 10 and Last 10 Values...\n" << endl;
		for(int i = 0; i < 10; ++i)
		{
			if(i == 0) {
				cout << "First 10..." << endl;
			}
			cout << strArr[i] << endl;
			if(i == 9)
			{
				cout << endl;
			}
		}
		
		for(int i = 24990; i < STRSIZE; ++i)
		{
			if(i == 24990) {
				cout << "Last 10..." << endl;
			}
			cout << strArr[i] << endl;

			
		}
		cout << "===========================" << endl;
		cout << "\n\n";
		cout << "*********************************" << endl;
	//Display Person Array
		cout << "Unsorted Person Array..." << endl;
		cout << "First 10 and Last 10 Values...\n" << endl;
		for(int i = 0; i < 10; ++i)
		{
			if(i == 0) {
				cout << "First 10..." << endl;
			}
			cout << perArr[i].getName() << endl;
			if(i == 9) {
				cout << endl;
			}
			
		}
		
		for(int i = 9990; i < PERSIZE; ++i)
		{
			if(i == 9990) {
				cout << "Last 10..." << endl;
			}
			cout << perArr[i].getName() << endl;

			
		}
		cout << "===========================" << endl;
	//Sort Person
		sortName = "SelectionSort Person ";
		cout << "Starting " << sortName << "-----------------------" << endl;
		start = clock();
		perSorter.SelectionSort(perArr, PERSIZE);
		stop = clock();
		diff_in_msec = (int) (stop - start);
		numOfSeconds = (diff_in_msec/1000) + ((diff_in_msec % 1000)/1000.00);
		cout << sortName << "                       " <<  diff_in_msec << " : " << numOfSeconds << endl << endl;
		ss2 << sortName << "                    " <<  diff_in_msec << " : " << numOfSeconds << endl;
		cout << "Sorted Person Array..." << endl;
		cout << "First 10 and Last 10 Values..." << endl;
		for(int i = 0; i < 10; ++i)
		{
			if(i == 0) {
				cout << "First 10..." << endl;
			}
			cout << perArr[i].getName() << endl;
			if (i == 9) {
				cout << endl;
			}
		}
		
		for(int i = 9990; i < PERSIZE; ++i)
		{
			if(i == 9990) {
				cout << "Last 10..." << endl;
			}
			cout << perArr[i].getName() << endl;
			
		}
		cout << "===========================" << endl;
		cout << "\n\n";
	//refill the array for a new sort
		cout << "Copying " << INTSIZE << " numbers from the Temp Int Array . . ." << endl;
		
		for (int i = 0; i < INTSIZE; ++i)
		{
			
			intArr[i] = intDummyArr[i];
			
		}
		cout << "Copying " << STRSIZE << " strings from the Temp Str Array . . ." << endl;
		
		for (int i = 0; i < STRSIZE; ++i) 
		{
			strArr[i] = strDummyArr[i];
		}
		
		cout << "Copying " << PERSIZE << " Persons from the Temp Per Array . . ." << endl;
		for (int i = 0; i < PERSIZE; ++i) 
		{
			perArr[i] = perDummyArr[i];
		}
		cout << "\n\n";

//begin shakersort
		cout << "Shaker ------------------------ " << endl;
	//Display Int Array
		cout << "Unsorted Int Array..." << endl;
		cout << "First 10 and Last 10 Values...\n" << endl;
		for(int i = 0; i < 10; ++i)
		{
			if(i == 0) {
				cout << "First 10..." << endl;
			}
			cout << intArr[i] << endl;
			
		}
		cout << endl;
		for(int i = 199990; i < INTSIZE; ++i)
		{
			if(i == 199990) {
				cout << "Last 10..." << endl;
			}
			cout << intArr[i] << endl;
			
		}
		cout << "===========================" << endl;
	//Start Sort
		sortName = "ShakerSort Int  ";
		cout << "Starting " << sortName << "-----------------------" << endl;
		start = clock();
		intSorter.ShakerSort(intArr, INTSIZE);
		stop = clock();
		diff_in_msec = (int) (stop - start);
		numOfSeconds = (diff_in_msec/1000) + ((diff_in_msec % 1000)/1000.00);
		cout << sortName << "                       " <<  diff_in_msec << " : " << numOfSeconds << endl << endl;
		ss << sortName << "                       " <<  diff_in_msec << " : " << numOfSeconds << endl;
		
	//Display Sorted Array
		cout << "Sorted Int Array..." << endl;
		cout << "First 10 and Last 10 Values...\n" << endl;
		for(int i = 0; i < 10; ++i)
		{
			if(i == 0) {
				cout << "First 10..." << endl;
			}
			cout << intArr[i] << endl;
			
		}
		cout << endl;
		for(int i = 199990; i < INTSIZE; ++i)
		{
			if(i == 199990) {
				cout << "Last 10..." << endl;
			}
			
			cout << intArr[i] << endl;
		}
		cout << "===========================" << endl;
	
		cout << "*********************************" << endl;
		cout << "\n\n";
		
	//Display Str Array
		cout << "Unsorted Str Array..." << endl;
		cout << "First 10 and Last 10 Values...\n" << endl;
		for(int i = 0; i < 10; ++i)
		{
			if(i == 0) {
				cout << "First 10..." << endl;
			}
			
			cout << strArr[i] << endl;
			if(i == 9) {
				cout << endl;
			}
		}
		
		for(int i = 24990; i < STRSIZE; ++i)
		{
			if(i == 24990) {
				cout << "Last 10..." << endl;
			}
			cout << strArr[i] << endl;
			
		}
		cout << "===========================" << endl;
	//Sort Str
		sortName = "ShakerSort Str  ";
		cout << "Starting " << sortName << "-----------------------" << endl;
		start = clock();
		strSorter.ShakerSort(strArr, STRSIZE);
		stop = clock();
		diff_in_msec = (int) (stop - start);
		numOfSeconds = (diff_in_msec/1000) + ((diff_in_msec % 1000)/1000.00);
		cout << sortName << "                       " <<  diff_in_msec << " : " << numOfSeconds << endl << endl;
		ss1 << sortName << "                       " <<  diff_in_msec << " : " << numOfSeconds << endl;
		cout << "Sorted Str Array..." << endl;
		cout << "First 10 and Last 10 Values...\n" << endl;
		for(int i = 0; i < 10; ++i)
		{
			if(i == 0) {
				cout << "First 10..." << endl;
			}
			cout << strArr[i] << endl;
			if(i == 9)
			{
				cout << endl;
			}
		}
		
		for(int i = 24990; i < STRSIZE; ++i)
		{
			if(i == 24990) {
				cout << "Last 10..." << endl;
			}
			cout << strArr[i] << endl;

			
		}
		cout << "===========================" << endl;
		cout << "\n\n";
		cout << "*********************************" << endl;
	//Display Person Array
		cout << "Unsorted Person Array..." << endl;
		cout << "First 10 and Last 10 Values...\n" << endl;
		for(int i = 0; i < 10; ++i)
		{
			if(i == 0) {
				cout << "First 10..." << endl;
			}
			cout << perArr[i].getName() << endl;
			if(i == 9) {
				cout << endl;
			}
			
		}
		
		for(int i = 9990; i < PERSIZE; ++i)
		{
			if(i == 9990) {
				cout << "Last 10..." << endl;
			}
			cout << perArr[i].getName() << endl;

			
		}
		cout << "===========================" << endl;
	//Sort Person
		sortName = "ShakerSort Person ";
		cout << "Starting " << sortName << "-----------------------" << endl;
		start = clock();
		perSorter.ShakerSort(perArr, PERSIZE);
		stop = clock();
		diff_in_msec = (int) (stop - start);
		numOfSeconds = (diff_in_msec/1000) + ((diff_in_msec % 1000)/1000.00);
		cout << sortName << "                       " <<  diff_in_msec << " : " << numOfSeconds << endl << endl;
		ss2 << sortName << "                       " <<  diff_in_msec << " : " << numOfSeconds << endl;
		cout << "Sorted Person Array..." << endl;
		cout << "First 10 and Last 10 Values..." << endl;
		for(int i = 0; i < 10; ++i)
		{
			if(i == 0) {
				cout << "First 10..." << endl;
			}
			cout << perArr[i].getName() << endl;
			if (i == 9) {
				cout << endl;
			}
		}
		
		for(int i = 9990; i < PERSIZE; ++i)
		{
			if(i == 9990) {
				cout << "Last 10..." << endl;
			}
			cout << perArr[i].getName() << endl;
			
		}
		cout << "===========================" << endl;
		cout << "\n\n";
	
		ofstream outputLog;
		
		outputLog.open(outputName);
		if(outputLog) {
			outputLog << "Ryan Sloan Time Log\n" << endl;
			outputLog << "Number of integer values sorted by each routine: " << INTSIZE << endl;
			outputLog << "Number of string values sorted by each routine: " << STRSIZE << endl;
			outputLog << "Number of Persons sorted by each routine: " << PERSIZE << endl << endl;
			outputLog << "Template Sort Information for Integers" << endl;
			outputLog << "Name of Sort Function: " << "    " << "Elapsed Time in msec.secs" << endl;
			outputLog << ss.str() << endl << endl;
			outputLog << "Template Sort Information for Strings" << endl;
			outputLog << "Name of Sort Function: " << "    " << "Elapsed Time in msec.secs" << endl;
			outputLog << ss1.str() << endl << endl;
			outputLog << "Template Sort Information for Persons" << endl;
			outputLog << "Name of Sort Function: " << "						" << "Elapsed Time in msec.secs" << endl;
			outputLog << ss2.str();
			outputLog.close();
			cout << "Times have been logged at: " << outputName << endl;
		}
		else {
			cout << "Unable to Write Log..." << endl;
		}
		
		cout << "---------END---------" << endl;
		
	return 0;
}
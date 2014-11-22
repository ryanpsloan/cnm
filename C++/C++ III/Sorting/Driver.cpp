#include <iostream>
#include <string>
#include <time.h>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "Sort.h"

using namespace std;

#define SIZE 200000
#define FILENAME "BJTest200K.txt"
#define LO 0
#define HI 199999

int main()
{	
	/*ofstream numFile;
	numFile.open("NumFile.txt", ios::app);
	for (int h = 0; h < 100000; ++h)
	{
		numFile << rand() % 100000 + 1 << endl;	
	}*/
	stringstream ss;
	bool bfileOpen;
	ifstream readFile;
	//opening file
	readFile.open(FILENAME);
	if(!readFile)
	{
		bfileOpen = false;
	}
	else
	{
		bfileOpen = true;
	}

	if(bfileOpen)
	{
		cout << "Reading Data from file " << FILENAME << "\n" << endl;
		clock_t start, stop;
		srand(static_cast <unsigned int> (time(0)));
	//declare the sorter
		Sort sorter;
	//create the array
		int* MasterArr = new int[SIZE];
		int* Arr = new int[SIZE];
	//fill the array with numbers 
		cout << "Filling Master Array with " << SIZE << " numbers from " << FILENAME << "\n" << endl;
		for (int i = 0; i < SIZE; ++i)
		{
			string temp;
			getline(readFile, temp);
			int conversion = atoi(temp.c_str());
			MasterArr[i] = conversion;

		}
		readFile.close();

		cout << "Copying " << SIZE << " numbers from the Master Array to Working Array . . ." << endl;
		for(int j = 0; j < SIZE; ++j)
		{
			Arr[j] = MasterArr[j];
		}

		////cout the array unsorted
		//for(int i = 0; i < 5; ++i)
		//{
		//	cout << (i+1) << ".   " << Arr[i] << endl;
		//}
		//cout << "Unsorted --------------------------------------------" << endl;
		
			
	//begin the bubblesort
		string sortName = "BubbleSort ";
		cout << "Starting " << sortName << "-----------------------" << endl;
		start = clock();
		sorter.bubblesort(Arr, SIZE);
		stop = clock();
		int diff_in_msec = (int) (stop - start);
		cout.precision(5);
		double numOfSeconds = (diff_in_msec/1000) + ((diff_in_msec % 1000)/1000.00);
		cout << sortName << "Execution time: " <<  numOfSeconds << " seconds.\n\n" << endl;
		ss << sortName << "Execution time: " <<  numOfSeconds << " seconds.\n\n" << endl;
		////cout the sorted array
		//for(int j = 0; j < 5; ++j)
		//{
		//cout << (j+1) << ".    " << Arr[j] << endl;
		//}
		//cout << "Sorted ----------------------------------------------" << endl;
		
		
	//refill the array for a new sort
		cout << "Copying " << SIZE << " numbers from the Master Array . . ." << endl;
		for(int k = 0; k < SIZE; ++k)
		{
			Arr[k] = MasterArr[k];
		}
		
		////cout the array unsorted
		//for(int i = 0; i < 5; ++i)
		//{
		//	cout << (i+1) << ".   " << Arr[i] << endl;
		//}
		//cout << "Unsorted --------------------------------------------" << endl;
		
				
	//begin comb11sort
		sortName = "Comb11Sort  ";
		cout << "Starting " << sortName << "-----------------------" << endl;
		start = clock();
		sorter.comb11sort(Arr, SIZE);
		stop = clock();
		diff_in_msec = (int) (stop - start);
		numOfSeconds = (diff_in_msec/1000) + ((diff_in_msec % 1000)/1000.00);
		cout << sortName << "Execution time: " <<  numOfSeconds << " seconds.\n\n" << endl;
		ss << sortName << "Execution time: " <<  numOfSeconds << " seconds.\n\n" << endl;
		//	//cout the sorted array
		//for(int j = 0; j < 5; ++j)
		//{
		//cout << (j+1) << ".    " << Arr[j] << endl;
		//}
		//cout << "Sorted ----------------------------------------------" << endl;
		
		
	//refill the array for a new sort
		cout << "Copying " << SIZE << " numbers from the Master Array . . ." << endl;
		for(int l = 0; l < SIZE; ++l)
		{
			Arr[l] = MasterArr[l];
		}
		
		////cout the array unsorted
		//for(int i = 0; i < 5; ++i)
		//{
		//	cout << (i+1) << ".   " << Arr[i] << endl;
		//}
		//cout << "Unsorted --------------------------------------------" << endl;
		
	
	//begin goofysort
		sortName = "GoofySort ";
		cout << "Starting " << sortName << "-----------------------" << endl;
		start = clock();
		sorter.goofysort(Arr, SIZE);
		stop = clock();
		diff_in_msec = (int) (stop - start);
		numOfSeconds = (diff_in_msec/1000) + ((diff_in_msec % 1000)/1000.00);
		cout << sortName << "Execution time: " <<  numOfSeconds << " seconds.\n\n" << endl;
		ss << sortName << "Execution time: " <<  numOfSeconds << " seconds.\n\n" << endl;
		//	//cout the sorted array
		//for(int j = 0; j < 5; ++j)
		//{
		//	cout << (j+1) << ".    " << Arr[j] << endl;
		//}
		//cout << "Sorted ----------------------------------------------" << endl;
		
	//refill the array for a new sort
		cout << "Copying " << SIZE << " numbers from the Master Array . . ." << endl;
		for(int m = 0; m < SIZE; ++m)
		{
			Arr[m] = MasterArr[m];
		}
		
		////cout the array unsorted
		//for(int i = 0; i < 5; ++i)
		//{
		//	cout << (i+1) << ".   " << Arr[i] << endl;
		//}
		//cout << "Unsorted --------------------------------------------" << endl;
		
	
	//begin Insertionsort
		sortName = "InsertionSort ";
		cout << "Starting " << sortName << "-----------------------" << endl;
		start = clock();
		sorter.insertionsort(Arr, SIZE);
		stop = clock();
		diff_in_msec = (int) (stop - start);
		numOfSeconds = (diff_in_msec/1000) + ((diff_in_msec % 1000)/1000.00);
		cout << sortName << "Execution time: " <<  numOfSeconds << " seconds.\n\n" << endl;
		ss << sortName << "Execution time: " <<  numOfSeconds << " seconds.\n\n" << endl;
		//	//cout the sorted array
		//for(int j = 0; j < 5; ++j)
		//{
		//cout << (j+1) << ".    " << Arr[j] << endl;
		//}
		//cout << "Sorted ----------------------------------------------" << endl;
		
	//refill the array for a new sort
		cout << "Copying " << SIZE << " numbers from the Master Array . . ." << endl;
		for(int n = 0; n < SIZE; ++n)
		{
			Arr[n] = MasterArr[n];
		}
		
		////cout the array unsorted
		//for(int i = 0; i < 5; ++i)
		//{
		//	cout << (i+1) << ".   " << Arr[i] << endl;
		//}
		//cout << "Unsorted --------------------------------------------" << endl;
		
	
	//begin Selectionsort
		sortName = "SelectionSort ";
		cout << "Starting " << sortName << "-----------------------" << endl;
		start = clock();
		sorter.selectionsort(Arr, SIZE);
		stop = clock();
		diff_in_msec = (int) (stop - start);
		numOfSeconds = (diff_in_msec/1000) + ((diff_in_msec % 1000)/1000.00);
		cout << sortName << "Execution time: " <<  numOfSeconds << " seconds.\n\n" << endl;
		ss << sortName << "Execution time: " <<  numOfSeconds << " seconds.\n\n" << endl;
		//cout the sorted array
		/*for(int j = 0; j < 5; ++j)
		{
		cout << (j+1) << ".    " << Arr[j] << endl;
		}
		cout << "Sorted ----------------------------------------------" << endl;*/

	//refill the array for a new sort
		cout << "Copying " << SIZE << " numbers from the Master Array . . ." << endl;
		for(int p = 0; p < SIZE; ++p)
		{
			Arr[p] = MasterArr[p];
		}
		
		////cout the array unsorted
		//for(int i = 0; i < 5; ++i)
		//{
		//	cout << (i+1) << ".   " << Arr[i] << endl;
		//}
		//cout << "Unsorted --------------------------------------------" << endl;
		
	
	//begin Shakersort
		sortName = "ShakerSort ";
		cout << "Starting " << sortName << "-----------------------" << endl;
		start = clock();
		sorter.shakersort(Arr, SIZE);
		stop = clock();
		diff_in_msec = (int) (stop - start);
		numOfSeconds = (diff_in_msec/1000) + ((diff_in_msec % 1000)/1000.00);
		cout << sortName << "Execution time: " <<  numOfSeconds << " seconds.\n\n" << endl;
		ss << sortName << "Execution time: " <<  numOfSeconds << " seconds.\n\n" << endl;
		//cout the sorted array
		//for(int j = 0; j < 5; ++j)
		//{
		//cout << (j+1) << ".    " << Arr[j] << endl;
		//}
		//cout << "Sorted ----------------------------------------------" << endl;

	//refill the array for a new sort
		cout << "Copying " << SIZE << " numbers from the Master Array . . ." << endl;
		for(int q = 0; q < SIZE; ++q)
		{
			Arr[q] = MasterArr[q];
		}
		
		////cout the array unsorted
		//for(int i = 0; i < 5; ++i)
		//{
		//	cout << (i+1) << ".   " << Arr[i] << endl;
		//}
		//cout << "Unsorted --------------------------------------------" << endl;
		
	
	//begin Shellsort
		sortName = "ShellSort ";
		cout << "Starting " << sortName << "-----------------------" << endl;
		start = clock();
		sorter.shellsort(Arr, SIZE);
		stop = clock();
		diff_in_msec = (int) (stop - start);
		numOfSeconds = (diff_in_msec/1000) + ((diff_in_msec % 1000)/1000.00);
		cout << sortName << "Execution time: " <<  numOfSeconds << " seconds.\n\n" << endl;
		ss << sortName << "Execution time: " <<  numOfSeconds << " seconds.\n\n" << endl;
		//	//cout the sorted array
		//for(int j = 0; j < 5; ++j)
		//{
		//cout << (j+1) << ".    " << Arr[j] << endl;
		//}
		//cout << "Sorted ----------------------------------------------" << endl;
		
	//refill the array for a new sort
		cout << "Copying " << SIZE << " numbers from the Master Array . . ." << endl;
		for(int r = 0; r < SIZE; ++r)
		{
			Arr[r] = MasterArr[r];
		}
		//cout the array unsorted
		/*for(int i = 0; i < 5; ++i)
		{
			cout << (i+1) << ".   " << Arr[i] << endl;
		}
		cout << "Unsorted --------------------------------------------" << endl;*/
		
	//begin QuickSort
		sortName = "QuickSort ";
		cout << "Starting " << sortName << "-----------------------" << endl;
		start = clock();
		sorter.quicksort(Arr, SIZE, LO, HI);
		stop = clock();
		diff_in_msec = (int) (stop - start);
		numOfSeconds = (diff_in_msec/1000) + ((diff_in_msec % 1000)/1000.00);
		cout << sortName << "Execution time: " <<  numOfSeconds << " seconds.\n\n" << endl;
		ss << sortName << "Execution time: " <<  numOfSeconds << " seconds.\n\n" << endl;
		//cout the sorted array
		/*for(int j = 0; j < 5; ++j)
		{
		cout << (j+1) << ".    " << Arr[j] << endl;
		}
		cout << "Sorted ----------------------------------------------" << endl;*/

	//refill the array for a new sort
		cout << "Copying " << SIZE << " numbers from the Master Array . . ." << endl;
		for(int s = 0; s < SIZE; ++s)
		{
			Arr[s] = MasterArr[s];
		}
		//cout the array unsorted
	/*	for(int i = 0; i < 5; ++i)
		{
			cout << (i+1) << ".   " << Arr[i] << endl;
		}
		cout << "Unsorted --------------------------------------------" << endl;*/
		
	
	//begin InPlaceMerge
		sortName = "InPlaceMerge ";
		cout << "Starting " << sortName << "-----------------------" << endl;
		start = clock();
		sorter.inplacemerge(Arr, SIZE, LO, HI);
		stop = clock();
		diff_in_msec = (int) (stop - start);
		numOfSeconds = (diff_in_msec/1000) + ((diff_in_msec % 1000)/1000.00);
		cout << sortName << "Execution time: " <<  numOfSeconds << " seconds.\n\n" << endl;
		ss << sortName << "Execution time: " <<  numOfSeconds << " seconds.\n\n" << endl;
		//cout the sorted array
		/*for(int j = 0; j < 5; ++j)
		{
		cout << (j+1) << ".    " << Arr[j] << endl;
		}
		cout << "Sorted ----------------------------------------------" << endl;*/
		ofstream outputLog;
		outputLog.open("Ryan_Sloan_TimeLog200K.txt");
		outputLog << "Ryan Sloan Time Log" << endl;
		outputLog << "FileName: " << FILENAME << endl;
		outputLog << "FileSize: " << SIZE << endl;
		outputLog << endl << endl << endl;
		outputLog << ss.str();
		outputLog.close();
		cout << "Times have been logged at TimeLog.txt" << endl;
		delete Arr;
		delete MasterArr;

		
	}
	else
	{
		cout << "Unable to read data from file " << FILENAME << ". Exiting..." << endl;
		exit(0);
	}

	


	
	
	

	return 0;
}
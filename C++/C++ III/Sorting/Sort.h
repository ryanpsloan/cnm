//Ryan Sloan
//C++ III - Barbara Johnson Fall 2013
//Program 4 - Sort.h

#include <string>
#include <fstream>
using namespace std;

class Sort
{
		
public:
	void bubblesort(int Arr[],int size);					//This is sort A
	void comb11sort(int Arr[],int size);					//This is sort I
	void goofysort(int Arr[],int size);						//This is sort C
	void insertionsort(int Arr[],int size);					//This is sort J
	void selectionsort(int Arr[],int size);					//This is sort G
	void shakersort(int Arr[],int size);					//This is sort H
	void shellsort(int Arr[],int size);						//This is sort D
	void quicksort(int Arr[],int size, int lo0, int hi0);	//This is sort E
	void inplacemerge(int Arr[],int size, int lo0, int hi0);//This is sort B

};
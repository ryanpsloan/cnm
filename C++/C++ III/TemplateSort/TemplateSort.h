#include <cstdlib>
#ifndef _TEMPLATESORT_H
#define _TEMPLATESORT_H

template <class T> 
class Sort
{
public:
	Sort();
	~Sort();
	void BubbleSort(T a[], int total);
	void Comb11Sort(T a[], int total);			    
	void InsertionSort(T a[], int total);				    
	void SelectionSort(T a[], int total);				    
	void ShakerSort(T a[], int total);
};
#endif
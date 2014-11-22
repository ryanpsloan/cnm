#include "TemplateSort.h"
#include <string>
#include <cstdlib>
#include "SloanPersonGen\PersonGen.h"

using namespace std;

template class Sort<int>;
template class Sort<string>;
template class Sort<Person>;

template <class T> 
Sort<T>::Sort()
{

}

template <class T>
Sort<T>::~Sort()
{
	
}

template <class T> 
void Sort<T>::BubbleSort(T a[], int total)
{
	T X;
	int i,j;
	for(i = 0; i < total - 1; ++i ) 
	{
		for(j = 1; j < total; ++j) 
		{
			if (a[j-1] > a[j])
			{
				X = a[j];
				a[j] = a[j-1];
				a[j-1] = X;
			}
		}
	} 
}

template <class T> 
void Sort<T>::Comb11Sort(T a[], int size) 
{
	float SHRINKFACTOR = (float)1.3;
	int gap, top;
    int i, j;
	T X;

    gap = size;
    do {
   
		gap = (int) ((float) gap / SHRINKFACTOR);
        switch (gap) 
		{
			case 0: 
				gap = 1;
				break;
            case 9: 
            case 10: 
                gap = 11;
                break;
            default: 
				break;
        }
            
            top = size - gap;
            for (i = 0; i < top; i++) {
                j = i + gap;
                if (a[i] > a[j]) {
                    X = a[i];
                    a[i] = a[j];
                    a[j] = X;
                    
                }
                
            }
        } while (gap > 1);
        
		
}

template <class T> 
void Sort<T>::InsertionSort(T a[], int size)
{
	T X;
	for (int i = 1; i < size; i++) {
	    int j = i;
		
		X = a[i];
	    while ((j > 0) && (a[j-1] > X)) {
                
	        a[j] = a[j-1];
	        j--;
	        
		}
	    a[j] = X;
           
     }
	
}

template <class T> 
void Sort<T>::SelectionSort(T a[], int size)
{
	T X;
	for (int i = 0; i < size; i++) {
			int min = i;
            int j;
			

            for (j = i + 1; j < size; j++) {
	        
				if (a[j] < a[min]) {
                    min = j;
                }
	        
			}

            X = a[min];
            a[min] = a[i];
			a[i] = X;
	    
        }

}
 
template <class T> 
void Sort<T>::ShakerSort(T a[], int size)
{
	int i = 0;
	int k = size - 1;
	T X;
	while (i < k) {
	    int min = i;
	    int max = i;
            int j;
            for (j = i + 1; j <= k; j++) {
	        

		if (a[j] < a[min]) {
                    min = j;
                }
		if (a[j] > a[max]) {
                    max = j;
                }
	        
	    }
			
        X = a[min];
		a[min] = a[i];
		a[i] = X;
	
	    if (max == i) {
	        X = a[min];
	        a[min] = a[k];
	 		a[k] = X;
	    } 
		else {
	        X = a[max];
	        a[max] = a[k];
	        a[k] = X;
	    }
	   
	    i++;
	    k--;
	}
	

}
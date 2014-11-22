#include "Sort.h"
#include <sstream>
#include <fstream>


void Sort::bubblesort(int Arr[],int size) //This is sort A
{
	for (int i = size -1 ; i >= 0; --i ) {
           
	    for (int j = 0; j < i; j++) {
			if (Arr[j] > Arr[j+1]) {
				int t = Arr[j];
				Arr[j] = Arr[j+1];
				Arr[j+1] = t;
			}
		}
	}
	
}
void Sort::comb11sort(int Arr[],int size) //This is sort I
{
	float SHRINKFACTOR = (float)1.3;
	int gap, top;
    int i, j;

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
                if (Arr[i] > Arr[j]) {
                    int t = Arr[i];
                    Arr[i] = Arr[j];
                    Arr[j] = t;
                    
                }
                
            }
        } while (gap > 1);
        
		
}


void Sort::goofysort(int Arr[],int size)//This is sort C
{
	int i = size - 1;
	while (i > 0)
	{
		if (Arr[i-1] <= Arr[i])
		{
			--i;
		}
		else 
		{
			int temp = Arr[i];
			Arr[i] = Arr[i-1];
			Arr[i-1] = temp;
			if( i < size - 1)
			{
				++i;
			}
			else
			{
				--i;
			}
		}
	}
}

void Sort::inplacemerge(int Arr[],int size, int lo0, int hi0)//This is sort B
{
	int lo = lo0;
	int hi = hi0;
	if (lo >= hi) {
	    return;
	}
	int mid = (lo + hi) / 2;

        /*
         *  Partition the list into two lists and sort them recursively
         */
        inplacemerge(Arr, size, lo, mid);
        inplacemerge(Arr, size, mid + 1, hi);

        /*
         *  Merge the two sorted lists
         */
		int end_lo = mid;
        int start_hi = mid + 1;
	while ((lo <= end_lo) && (start_hi <= hi)) {
          
            if (Arr[lo] < Arr[start_hi]) {
                lo++;
            } else {
                /*  
                 *  a[lo] >= a[start_hi]
                 *  The next element comes from the second list, 
                 *  move the a[start_hi] element into the next 
                 *  position and shuffle all the other elements up.
                 */
				int T = Arr[start_hi];
                for (int k = start_hi - 1; k >= lo; k--) {
                    Arr[k+1] = Arr[k];
                   
                }
                Arr[lo] = T;
                lo++;
                end_lo++;
                start_hi++;
            }
        }
}

 





void Sort::insertionsort(int Arr[],int size)//This is sort J
{
	for (int i = 1; i < size; i++) {
	    int j = i;
	    int B = Arr[i];
	    while ((j > 0) && (Arr[j-1] > B)) {
                
	        Arr[j] = Arr[j-1];
	        j--;
	        
		}
	    Arr[j] = B;
           
     }
	
}

void Sort::quicksort(int Arr[],int size, int lo0, int hi0) //This is sort E
{  
	int lo = lo0;
	int hi = hi0;
	
	if (lo >= hi) {
	    return;
	}
        else if( lo == hi - 1 ) {
            /*
             *  sort a two element list by swapping if necessary 
             */
            if (Arr[lo] > Arr[hi]) {
                int T = Arr[lo];
                Arr[lo] = Arr[hi];
                Arr[hi] = T;
            }
            return;
	}


        /*
         *  Pick a pivot and move it out of the way
         */
	int pivot = Arr[(lo + hi) / 2];
        Arr[(lo + hi) / 2] = Arr[hi];
        Arr[hi] = pivot;

        while( lo < hi ) {
            /*
             *  Search forward from a[lo] until an element is found that
             *  is greater than the pivot or lo >= hi 
             */
            while (Arr[lo] <= pivot && lo < hi) {
				lo++;
			}

            /*
             *  Search backward from a[hi] until element is found that
             *  is less than the pivot, or lo >= hi
             */
			 while (pivot <= Arr[hi] && lo < hi ) {
				hi--;
			}

            /*
             *  Swap elements a[lo] and a[hi]
             */
            if( lo < hi ) {
                int T = Arr[lo];
                Arr[lo] = Arr[hi];
                Arr[hi] = T;
                
            }
		}

        /*
         *  Put the median in the "center" of the list
         */
        Arr[size-1] = Arr[hi];
        Arr[hi] = pivot;

        /*
         *  Recursive calls, elements a[lo0] to a[lo-1] are less than or
         *  equal to pivot, elements a[hi+1] to a[hi0] are greater than
         *  pivot.
         */
	quicksort(Arr, size, lo0, lo-1);
	quicksort(Arr, size, hi+1, hi0);
}

void Sort::selectionsort(int Arr[],int size)//This is sort G
{
	for (int i = 0; i < size; i++) {
			int min = i;
            int j;

            /*
             *  Find the smallest element in the unsorted list
             */
            for (j = i + 1; j < size; j++) {
	        

				if (Arr[j] < Arr[min]) {
                    min = j;
                }
	        
			}

            /*
             *  Swap the smallest unsorted element into the end of the
             *  sorted list.
             */
            int T = Arr[min];
            Arr[min] = Arr[i];
			Arr[i] = T;
	    
        }
	
}

void Sort::shakersort(int Arr[],int size)//This is sort H
{
	int i = 0;
	int k = size - 1;
	while (i < k) {
	    int min = i;
	    int max = i;
            int j;
            for (j = i + 1; j <= k; j++) {
	        

		if (Arr[j] < Arr[min]) {
                    min = j;
                }
		if (Arr[j] > Arr[max]) {
                    max = j;
                }
	        
	    }

        int T = Arr[min];
        Arr[min] = Arr[i];
		Arr[i] = T;
	
	    if (max == i) {
	        T = Arr[min];
	        Arr[min] = Arr[k];
	 		Arr[k] = T;
	    } 
		else {
	        T = Arr[max];
	        Arr[max] = Arr[k];
	        Arr[k] = T;
	    }
	   
	    i++;
	    k--;
	}
	

}

void Sort::shellsort(int Arr[],int size) //This is sort D
{
	int h = 1;
        /* 
         * find the largest h value possible 
         */
    while ((h * 3 + 1) < size) {
	    h = 3 * h + 1;
	}

        /* 
         * while h remains larger than 0 
         */
        while( h > 0 ) {
            /* 
             * for each set of elements (there are h sets)
             */
            for (int i = h - 1; i < size; i++) {
                /* 
                 * pick the last element in the set
                 */
                int B = Arr[i];
                int j = i;
                /*
                 * compare the element at B to the one before it in the set
                 * if they are out of order continue this loop, moving
                 * elements "back" to make room for B to be inserted.
                 */
                for( j = i; (j >= h) && (Arr[j-h] > B); j -= h) {
                    Arr[j] = Arr[j-h];
		        }
                /*
                 *  insert B into the correct place
                 */
                Arr[j] = B;
	       
            }
            /* 
             * all sets h-sorted, now decrease set size
             */
            h = h / 3;
        }

}




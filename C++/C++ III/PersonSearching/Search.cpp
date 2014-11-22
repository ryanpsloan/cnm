//
//
//
#include<string>
#include<iostream>
#include "SloanPersonGen\Person.h"
#include "Search.h"

using namespace std;

bool SequentialSearch(Person pArr[], int size, string target, int *position, int *pNumCompares)
{
	*position = 0;
	*pNumCompares = 0;
	int i = 0;
	do
	{
		string testName = pArr[i].getName();
		*position = (i + 1);
		*pNumCompares += 1;
		if(testName == target)
		{
			return true;
		}
		else if (testName > target)
		{
			*position = -1;
			return false;
		}
		++i;	
	} while (i < size);
	*position = -1;
	return false;
}

bool BinarySearch(Person pArr[], int size, string target, int *position, int *pNumCompares)
{
	int i = 0, first = 0, last = (size - 1), halfWay = (last - first)/2;
	*position = 0;
	*pNumCompares = 0;
	do
	{
		*pNumCompares += 1;
		if (pArr[halfWay].getName() == target)
		{
			*position = (halfWay + 1);
			return true;
		}
		
		if (target > pArr[halfWay].getName())
		{
			first = halfWay;
			halfWay = first + ((last - first)/2);
		}
		else if (target < pArr[halfWay].getName())
		{
			last = halfWay;
			halfWay = (last - ((last - first)/2));
		}
		
		if (last - first == 1)
		{
			if(pArr[first].getName() == target)
			{
				*position = (first + 1);
				*pNumCompares += 1;
				return true;
			}
			else if (pArr[last].getName() == target)
			{
				*position = (last + 1);
				*pNumCompares += 1;
				return true;
			}
			else
			{
				*position = -1;
				return false;
			}
		}
		++i;
	} while(i < size);
	*position = -1;
	return false;
}

bool RunRecursiveSearch(Person pArr[], int size, string target, int *position, int *pNumCompares)
{
	int first = 0, last = (size - 1);
	*position = 0;
	*pNumCompares = 0;
	
	bool bRun = RecursiveBinarySearch(pArr, target, first, last, position, pNumCompares);
	if(bRun)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool RecursiveBinarySearch(Person pArr[], string target, int first, int last, int *position, int *pNumCompares)
{
	int halfWay = (last - first)/2;
	if (first >= halfWay)
	{
		halfWay += first;
	}
	else if (last <= halfWay)
	{
		halfWay = last - halfWay;
	}
	*pNumCompares += 1;
	if (pArr[halfWay].getName() == target)
	{
		*position = (halfWay + 1);
		return true;
	}
	
	if (target > pArr[halfWay].getName())
	{
		first = halfWay;
	}
	else if (target < pArr[halfWay].getName())
	{
		last = halfWay;
	}
	if (last - first == 1)
	{
		if (pArr[first].getName() == target)
		{
			*position = (first + 1);
			*pNumCompares += 1;
			return true;
		}
		else if (pArr[last].getName() == target)
		{
			*position = (last + 1);
			*pNumCompares += 1;
			return true;
		}
		else
		{
			*position = -1;
			return false;
		}
	}
	bool bTest = RecursiveBinarySearch(pArr, target, first, last, position, pNumCompares);
	if(bTest)
	{return true;}
	else
	{return false;}
}
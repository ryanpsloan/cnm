#include <string>
#include "SloanPersonGen\Person.h"
using namespace std;

#ifndef _SEARCH_H
#define _SEARCH_H

bool SequentialSearch(Person pArr[], int size, string target, int *position, int *pNumCompares);

bool BinarySearch(Person pArr[], int size, string target, int *position, int *pNumCompares);

bool RunRecursiveSearch(Person pArr[], int size, string target, int *position, int *pNumCompares);

bool RecursiveBinarySearch(Person pArr[], string target, int first, int last, int *position, int *pNumCompares);

#endif




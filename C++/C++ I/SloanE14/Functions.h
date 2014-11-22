//Ryan Sloan - rsloan2@cnm.edu
//CIS1275 - Feridoon Ghanbari

//Chapter 6
//C++ Sorting Oak Leaves 
//Functions.h

#include <string>
using namespace std;

bool ReadFile(double oakLeaves[],int &rTotal);
double FindAve(double oakLeaves[], int total);
void SortOakLeaves(double dLeafSizes[], int total);
void Write(double oakLeaves[], int total, double aveSize);
void WriteHeader();
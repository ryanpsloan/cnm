// Ryan Sloan - rsloan2@cnm.edu
// CIS1275 - Feridoon Ghanbari
// Exercise 16

#include<iostream>
#include<string>
#include<iomanip>
#include "Array.h"
using namespace std;

int main()
{
	string answer = "y";
do
{
	srand(unsigned int (NULL));
	Header();
	cout << fixed << showpoint << setprecision(4);
	cout << "The purpose of this program is to calculate the average and standard deviation " << endl;
	cout << endl;
	const int SIZE = 1000;
	int array[SIZE];
	FillArray(array, SIZE);
	double avg = AvgArray(array, SIZE);
	cout << "The average of 1000 randomly generated numbers between 0 and 2000 is \n";
	cout << avg;
	cout << endl;
	double stdDev = StdDeviation(array, SIZE, avg);
	cout << "The standard deviation is \n";
	cout << stdDev;
	cout << endl;
	cout << "Would you like to perform another calculation? y/n  ";
	getline(cin, answer);
} while (answer == "y");
	return 0;
}
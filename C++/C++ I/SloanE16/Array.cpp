// Ryan Sloan - rsloan2@cnm.edu
// CIS1275 - Feridoon Ghanbari
// Exercise 16

#include<iostream>
#include<cmath>

using namespace std;

void Header()
{
	cout << "Ryan Sloan" << endl;
	cout << "Exercise 16" << endl;
	cout << "Functions Arrays and Statistics" << endl;
	cout << endl;
}
void FillArray(int array[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		array[i] = rand() % 2000;
	}

}
double AvgArray(int array[], int size)
{
	double sum = 0;
	for (int j = 0; j < size; ++j)
	{
		sum += array[j];
	}
	double avg = sum/size;
	return avg;
}
double StdDeviation(int array[], int size, double avg)
{
	double sum = 0;
	for (int k = 0; k < size; ++k)
	{
		sum += pow((array[k] - avg),2);
		
	}
	//cout << sum << endl;
	double stdD = sqrt((1.0/size)*sum);
		
	return stdD;
}
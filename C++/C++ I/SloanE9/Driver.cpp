// CIS1275 - Feridoon Ghanbari
// Ryan Sloan, rsloan2@cnm.edu
// SloanE9/Driver.cpp

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

void Header();
int GetRandomNum(int m);
int GetRandomNum(int i, int j);
double GetRandomNum();


int main()
{
	Header();
	srand(time(NULL));
	string answer;
	int m = 100;
	int i = 100;
	int j = 500;
	do
	{
		cout << setw(10) << "0 & m-1 " << " | "<< setw(10) << "i & j " << " | " << setw(10) << "0.000 & 1.000" << endl;
		cout << fixed << showpoint;
		cout.precision(3);
		for (int k = 0; k < 15; ++k)
		{
			int random1 = GetRandomNum(m);
			int random2 = GetRandomNum(i,j);
			double random3 = GetRandomNum();
			
			cout << setw(10) << random1 << " | " << setw(10) << random2 << " | " << setw(10) << random3 << endl;
		}

		cout << "Would you like to do another? yes/no  ";
		getline(cin, answer);
		cout << endl;
	} while (answer == "yes");
	cout << "Goodbye!" << endl;
}

void Header()
{
	cout << "Ryan Sloan" << endl;
	cout << "Exercise 9 - Overloaded Functions" << endl;
	cout << endl;
}

int GetRandomNum(int m)
{
	return rand() % m;
}

int GetRandomNum(int i, int j)
{
	int random = (rand() % j) + i; 
	if (random > 500)
		random = 500;
	return random;
}

double GetRandomNum()
{
	return (rand() % 1001) / 1000.00;
}
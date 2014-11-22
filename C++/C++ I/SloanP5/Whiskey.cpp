// CIS1275 - Feridoon Ghanbari
// Ryan Sloan - rsloan2@cnm.edu
// SloanP5/Whiskey.cpp

#include<iostream>
#include<string>
#include<cmath>

using namespace std;

void Header()
{
	cout << "Ryan Sloan" << endl;
	cout << "C++ Whiskey" << endl;
	cout << "References and Functions" << endl;
	cout << endl;
}

void AskName(string &name)
{
	cout << "What is the name of the Whiskey?" << endl;
	getline(cin, name);
}
void AskForBarrels(int &diameter, int &height, int &numOfBarrels)
{
	cout << "Enter the inside diameter of the barrel in inches: ";
	cin >> diameter;
	cout << "Enter the height of the barrel in inches: ";
	cin >> height;
	cout << "Enter the number of barrels with this measurement: ";
	cin >> numOfBarrels;
	cin.ignore();
	cout << endl;
}
double CalcNetWhiskeyVol(int &diameter, int &height, int &numOfBarrels)
{
	double volume1 = 3.14159 * pow((diameter/2.0),2) * height;
	//cout << volume1 << " ";
	double volume5 = numOfBarrels * (volume1);
	//cout << volume5 << " ";
	double volumeGallons = volume5/231;
	//cout << volumeGallons << " ";
	double volumeLiters = volumeGallons * 3.785;
	//cout << volumeLiters << " ";
	return volumeLiters;
}

double DetermineVol(double &volumeLiters, double &volumeFinal, int &numOfBottles, int &numOfCases, double &remainingBottles)
{
	volumeFinal = .95 * volumeLiters;
	double remainingLiters = volumeFinal - floor(volumeFinal);
	if(static_cast<int>(volumeFinal) % 2 == 1)
	{
		remainingLiters += 1;
	}
	numOfBottles += floor(volumeFinal) / 2.0;
	numOfCases = numOfBottles / 12.0;
	remainingBottles += remainingLiters/2.0;
	
	return remainingLiters;
}
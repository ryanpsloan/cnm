//This program allows the user to determine the volume of a cylinder. 
//Pointers and references are both used here.

//Functions.cpp

#include "Functions.h"
#include <iostream>
using namespace std;

#define pi 3.141592265

//Pointers for this Ask
void AskRandHCyl(double &radius, double &height)
{
	cout << "\n\n Please enter the radius and height of a cylinder \n";
	cout << "\nie. 5.5    22.8   ==> ";

	cin >> radius >> height;

}

//References for the Calc
void CalcVolAndSA(double radius, double height, double &volume, double &surfaceArea)
{

	double areaTop = pi * pow(radius,2);

	//calculate the volume, 
	volume = areaTop * height;

	//calculate the surface area
	double topCircumference = pi * 2 * radius;
	double cylinderArea = topCircumference * height;
	
	//surface area is the sum of cylinderArea + top + bottom
	surfaceArea = cylinderArea + 2.0*areaTop;
}
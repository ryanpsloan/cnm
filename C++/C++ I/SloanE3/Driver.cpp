// CIS1275 - Feridoon Ghanbari
// Ryan Sloan, rsloan2@cnm.edu
// Exercise 3 - Square Pyramid
// Driver.cpp

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
	double base;
	double height;
	double volume;
	double side;
	double area;
	double surfacearea;

	cout << "Ryan Sloan Exercise 3";
	//setting the precision
	cout << fixed << showpoint;
	cout.precision(3);
	//Program Head
	cout << "Exercise 3 - Square Pyramid \n";
	cout << "Ryan Sloan \n";
	cout << "Objective: Using Mathematical calculations \n" << endl;
	
	cout << "Would you like to calculate the surface area and  \n";
	cout << "volume of a square pyramid? \n";
	cout << endl;
	cout << "A square pyramid has a base that is square and all four \n";
	cout << "triangle faces are congruent isosceles triangles. \n";
	cout << endl;
	//Getting input from the user
	cout << "In feet, enter the base: ";
	cin >> base;
	cout << "In feet, enter the height: ";
	cin >> height;
	cout << endl;
	//outputting the users input
	cout << "The base of this pyramid is: " << base << endl;
	cout << "The height of this pyramid is: " << height << endl;
	cout << endl;
	//calculating the volume
	volume = (pow(base, 2) * height)/3.0;
	//outputting the result
	cout << "Based upon my calculations, the volume of this " << endl; 
	cout << "pyramid is " << volume << " feet cubed. " << endl;
	//calculating the surface area
	side = sqrt(pow(height, 2) + pow((base/2), 2));
	area = side * (base/2);
	surfacearea = 4 * area;
	//cout << side << " "; // used for checking the calculations against the test cases
	//cout << area << " ";
	cout << endl;
	//outputting the result.
	cout << "The surface area is " << surfacearea << " ft." << endl;
}
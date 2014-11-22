// CIS1275 - Feridoon Ghanbari
// Ryan Sloan, rsloan2@cnm.edu
// Program 2 - SloanP2\Driver.cpp

#include <iostream>	//for cout cin getline
#include <string> // for strings
#include <iomanip>// for precision
#include <cmath> // for pow()

#define Pi 3.14159265359		//The value of PI

using namespace std;

int main()
{
	//Header
	cout << "Ryan Sloan" << endl;
	cout << "Program 2" << endl;
	cout << "Objective - math, loops, cin and cout" << endl;
	cout << endl;

	//Variable Declarations
	double density;
	const double densityAu = 0.698; //lb/in3
	const double densityPb = 0.410; //lb/in3
	const double densityAl = 0.098; //lb/in3
	const double densityAg = 0.379; //lb/in3
	double length = 0;
	double diameter = 0;
	string metal;
	char answer;
	string stringmetal;

	//Set precision
	cout << fixed << showpoint;
	cout.precision(2);
	
	//Output
	cout << "We are going to calculate the total volume and mass of your cylinder." << endl;
	cout << endl;

	do
	{
		//Input string from user
		cout <<"First, input the material the cylinder is made of." << endl;
		cout << "For Gold enter \"Au\", for Silver enter \"Ag\", " << endl;
		cout << "for Aluminum enter \"Al\", for Lead enter \"Pb\": "; 
		getline(cin, metal); 
		cout << endl;
		//Compare string against if statements to determine density
		if (metal == "Au")
		{
			density = densityAu; 
			stringmetal = "gold";
		}
		else if (metal == "Ag")
		{
			density = densityAg;
			stringmetal = "silver";
		}
		else if (metal == "Al")
		{
			density = densityAl;
			stringmetal = "aluminum";
		}
		else if (metal == "Pb")
		{
			density = densityPb;
			stringmetal = "lead";
		}

		//Input double from the user
		cout << "Now, input the dimensions of your cylinder in inches." << endl;
		cout << "Length: ";
		cin >> length;
		cin.ignore();

		//Input double from the user
		cout << "Diameter: ";
		cin >> diameter;
		cin.ignore();
		double radius = diameter/2;
		cout << endl;

		// volume calculation 
		double volume = Pi*pow(radius,2)*length;
		cout << "Forumula for volume: Pi * " << radius << "squared * " << length << " = " << volume << " cubic inches." << endl;
		cout << endl;
		cout << "The density of " << stringmetal << " is " << density << " lbs/cubic inch." << endl;
		cout << endl;
		// mass/weight calculation
		double mass = density * volume;
		cout << "Formula for mass: " << density << " * " << volume << " = " << mass << " lbs." << endl;
		cout << endl;
		
		cout << "*****************************  Summary  ********************************" << endl << endl;
		cout << "You have a " << stringmetal << " cylinder with a length of " << length << " inches and " << endl;
		cout << "a diameter of " << diameter << " inches. The volume of the cylinder is " << volume << " cubic inches " << endl;
		cout << "and the mass is " << mass << " lbs." << endl;
		cout << "Do you have another cylinder? (y/n): ";
		cin >> answer;
		cin.ignore();
		cout << endl;

	} while (answer == 'y' || answer == 'Y');

	cout << "Good-Bye" << endl;
	cout << endl;
	return 0;
}
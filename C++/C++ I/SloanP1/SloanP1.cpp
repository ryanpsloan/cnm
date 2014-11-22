// CIS 1275 - Feridoon Ghanbari
// Ryan Sloan 
// rsloan2@cnm.edu
// SloanP1.cpp

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
	//header output
	cout << "Ryan Sloan" << endl;
	cout << "Program I" << endl;
	cout << "Objective: To utilize cout, cin & perform mathmatical computations." << endl;
	cout << endl;
	
	//declared variables
	double length, width, height;
	double wallArea1A, wallArea1B, wallArea2A, wallArea2B;
	double ceilingArea;
	double totalWallArea;
	double windowSpaceArea;
	double paintArea;
	double sqftPerGallon;
	double numberOfGallons;

	//collecting the input from the user
	cout << "So you're painting your room and need a little help.\n";
	cout << "Okay, first let's calculate the Total Wall Area. \nPlease enter the following measurements in feet i.e. '10.00':\n";
	cout << "First enter the Height of the ceiling in feet. ";
	cin >> height;
	cout << "Next enter the Length of the room in feet. ";
	cin >> length;
	cout << "Finally, enter the Width of the room in feet. ";
	cin >> width;
	cout << endl;

	//calculates the area of each wall
	wallArea1A = length * height;
	wallArea1B = length * height;
	wallArea2A = width * height;
	wallArea2B = width * height;
	
	//adds the wall areas together for a total
	totalWallArea = wallArea1A + wallArea2A + wallArea1B + wallArea2B;
	
	cout.setf(ios::fixed | ios::showpoint);
	cout.precision(2);
	cout << "The Total Wall Area is " << totalWallArea << " squarefeet.\n";
	cout << "\nNow let's subtract out the Door and Window Area.\n";
	cout << "Enter the total window area as a percentage, i.e. '0.20' ";
	cin >> windowSpaceArea;
	//calculates the noPaint area and subtracts it from the total for paintArea
	paintArea = totalWallArea - (totalWallArea * windowSpaceArea);
	cout << "The Paintable Wall Area is " << paintArea << " squarefeet. ";
	cout << endl;
	char answer;
	//inquires if you plan on painting the ceiling.
	cout << "\nDo you plan on painting the ceiling? (y/n) ";
	cin >> answer;
	if (answer == 'y' || answer == 'Y')
	{
		//if yes calculates and adds ceiling area to paintArea
		ceilingArea = length * width;
		paintArea += ceilingArea;
		cout << "Ok then, the ceiling area is " << ceilingArea << " squarefeet." << endl;
		cout << "That means that the total area you will paint is " << paintArea << " squarefeet. " << endl;
	}
	else
	{	
		//otherwise it just states the wall area
		cout << "Ok then, the area you will paint is " << paintArea << " squarefeet. " << endl;
	}
	
	//gets input from the user 
	cout << "\nHow many squarefeet does a gallon of paint cover? ";
	cin >> sqftPerGallon;
	//calculates the number of gallons to paint the area.
	numberOfGallons = paintArea/sqftPerGallon;
	cout << "The number of gallons it will take to paint your room is " << ceil(numberOfGallons) << " Gallons.\n";
	cout << endl;

	cout << "See Ya Later!\n";
	cout << endl;
}
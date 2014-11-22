// CIS1275 - Feridoon Ghanbari
// Ryan Sloan - rsloan2@cnm.edu
// SloanQ3/Ribbon.cpp

#include <iostream>
#include <iomanip>


using namespace std;

void Header()
{
	cout << "Ryan Sloan" << endl;
	cout << "Multi-file Programs" << endl;
	cout << "SloanQ3" << endl;
	cout << endl;

}

double CalcRibbon(double length, double width, double height)
{
	double ribbonLength = (2*length) + (4*height) + (2*width) + 24; //24 extra inches for the bow
	return ribbonLength;
}

void WriteRibbonReport(double ribbonLength, double length, double width, double height)
{
	cout << fixed << showpoint; // setting decimal precision
	cout.precision(2);
	cout << "For a box with dimensions " << length << " x " << width << " x " << height << endl;
	cout << "The length of a ribbon needed to wrap the package is " << ribbonLength << " inches long." << endl;

}
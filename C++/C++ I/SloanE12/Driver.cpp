//This program allows the user to determine the volume of a cylinder. 
//Pointers and references are both used here.

/*Please  make a new folder named LastNameE12 and place this project inside it.
As usual, drop the folder in the appropriate place on the I-Drive.
Please print all three files and staple them together, with the Driver (this file) on the top. 
Make sure you put your name at the top of ALL three files

Your assignment is to fill in the variables that are missing.  These are the
pointers and references.  They are  from the driver, the function headers, 
the function prototypes, and in the function bodies also.

This program will compile and run great when you have finished.  Don't bother
messing with anything else.*/

#include <iostream>
#include <string>
#include "Functions.h"
using namespace std;

int main()
{
	double radius, height, volume, surfaceArea;
	string go_again = "yes";

	cout << "\n  Cylinder Volume and Surface Area Calculations \n";

	while(go_again == "yes")
	{
		AskRandHCyl(radius, height);  //pass radius and height by pointer here
		CalcVolAndSA(radius, height, volume, surfaceArea); //pass surfaceArea and
										//volume by reference here
	
		cout.setf(ios::fixed);
		cout.precision(4);
		cout << "\n The radius is " << radius;
		cout << "\n The height is " << height;
		cout << "\n\n The volume of a cylinder is:  " << volume;
		cout << "\n The surface area of this cylinder is:  " << surfaceArea;

		cout << "\n\n Would you like to go again? yes/no  ";
		cin  >> go_again;
		
	}
	cout << "\n Goodbye!\n\n";	
	return 0;

}




	
//Ryan Sloan
//Quiz2
//ryansdeal@hotmail.com
//Driver.cpp

#include <string>
#include <iostream>
#include "DriversLic.h"
#include "Date.h"

using namespace std;

int main()
{
	cout << "****** Ryan Sloan ****** \n*Quiz 2 \n*A Class that has an object \n" << endl;

	DriversLic dL;
	char loopCondition = 'y';
	do
	{
		string name;
		int m,d,y;
		cout << "=======================================================================" << endl;
		cout << " Welcome to the NM MVD, the MOST efficient organization in the world.  " << endl;
		cout << "=======================================================================" << endl;
		cout << "To begin, please enter the driver's name. " << endl;
		cout << ">> ";
		getline(cin, name);
		cout << "Next, enter the driver's birthdate (ie. MM DD YYYY)" << endl;
		cout << ">> ";
		cin >> m >> d >> y;
		Date birth(m,d,y,name);
		dL.SetUserInfo(name, birth);
		cout << dL.GetLicenseString();
		cout << "Renew another license? y/n" << endl;
		cin >> loopCondition;

	}while(loopCondition == 'y');

	cout << "Goodbye and Farewell" << endl;


	return 0;
}
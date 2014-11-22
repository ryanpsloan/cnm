//Ryan Sloan
//Quiz2
//ryansdeal@hotmail.com
//DriversLic.h

#ifndef _DRIVERSLIC_H
#define _DRIVERSLIC_H

#include "Date.h"
#include <string>

using namespace std;

class DriversLic
{
private:
	string name;
	Date issue, exp, birth;
	void CalcExpDate();

public:
	DriversLic();
	void SetUserInfo(string name, Date &birth);
	string GetLicenseString();
};



#endif
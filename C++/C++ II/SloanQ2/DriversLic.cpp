//Ryan Sloan
//Quiz2
//ryansdeal@hotmail.com
//DriversLic.cpp


#include <string>
#include <sstream>
#include"DriversLic.h"

using namespace std;

DriversLic::DriversLic()
{
	
}

void DriversLic::SetUserInfo(string name, Date &birth)
{
	this->name = name;
	this->birth = birth;
	CalcExpDate();
}

void DriversLic::CalcExpDate()
{
	int age = issue.GetYear() - birth.GetYear();
	int month = birth.GetMonth() + 1;
	int	day = 1;
	int year = 0;
	if (month == 13)
	{
		month = 1;
		year++;
	}
	
	year += issue.GetYear();
	
	if (age >= 16 && age <= 21)
	{
		year += 2;
		exp.SetDate(month,day,year, "Expires");
	}
	else if(age >= 22 && age <= 62)
	{
		year += 4;
		exp.SetDate(month,day,year, "Expires");
	}
	else if(age > 62)
	{
		year += 1;
		exp.SetDate(month,day,year, "Expires");
	}
}

string DriversLic::GetLicenseString()
{
	string FormattedString;
	stringstream ss;
	ss << "The Date of Birth provided is: " << birth.GetFormattedDate() << endl;
	ss << "The Date of Issue for the license is: " << issue.GetFormattedDate() << endl;
	ss << "The Date of Expiration for the license is: " << exp.GetFormattedDate() << endl;
	FormattedString = ss.str();
	return FormattedString;
}
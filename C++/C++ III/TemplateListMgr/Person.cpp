//Ryan Sloan
//CIS2277
//Person.cpp
#include <iostream>
#include <fstream>
#include <istream>
#include <sstream>
#include <string>
#include "Person.h"
#include "Date.h"

using namespace std;

void Person::calcAge()
{
	Date today;
	
	if (bday.GetMonth() > today.GetMonth())
	{
		int b,t;
		b = bday.GetDayOfYear();
		t = today.GetDayOfYear();
		int days = b - t;
		int years = 365*(today.GetYear() - bday.GetYear());
		double result = (years - days)/365;
		age = static_cast<int>(result);
	}
	else
	{
		int b, t;
		b = bday.GetDayOfYear();
		t = today.GetDayOfYear();
		int days = t - b;
		days += 365*(today.GetYear() - bday.GetYear());
		double result = days/365;
		age = static_cast<int>(result);
	}
	
}
	
	
Person::Person()
{
	Date today;
	name = "";
	age = 0;
	bday = today;
	string s = "Birthday";
	bday.SetDesc(s);

};
	
Person::Person(string p, Date d)
{
	name = p;
	bday = d;
	calcAge();

};
	
Person::Person(string p, int m, int d, int y)
{
	
	string s = "Birthday ";
	name = p;
	bday.SetDate(m,d,y,s);
	calcAge();

};
	

void Person::setBirthday(int m, int d, int y)
{
	string s = "Birthday ";
	bday.SetDate(m,d,y,s);
	calcAge();
	

};

//overloaded operators for alphabetic order based on name
bool Person::operator < (Person p)
{
	if (name < p.name)
		return true;
	else
		return false;

};

bool Person::operator > (Person p)
{
	if (name > p.name)
		return true;
	else
		return false;
};

ostream& operator <<(ostream& os, Person p)
{
	return os << p.getFullDesc();
}
//returns name and age in years
string Person::getNameAge()
{
	stringstream ss;
	ss << name << " " << "Age: " << age;
	
	return ss.str();
};

//returns 1 line description, include name, age, bday
string Person::getFullDesc()
{
	stringstream ss;
	ss << name << " " << "Age: " << age << " " << bday.GetFormattedDate();

	return ss.str();
};





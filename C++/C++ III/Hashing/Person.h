//Barbara Johnston's Person.h for Program 1
//Person.h

//This class represents a class for a generic person.

#ifndef _PERSON_H
#define _PERSON_H

#include <string>
using namespace std;
#include "Date.h"
class Person
{
private:
	string name;
	int age;
	Date bday;
	void calcAge();

public:
	Person();
	Person(string p, Date d);
	Person(string p, int m, int d, int y);
	void setName(string n){name = n; }
	void setBirthday(Date d){ bday = d; calcAge(); }
	void setBirthday(int m, int d, int y);

	//overloaded operators for alphabetic order based on name
	bool operator < (Person p);
	bool operator > (Person p);

	//returns just the name
	string getName(){return name; }

	//returns name and age in years
	string getNameAge();

	//returns 1 line description, include name, age, bday
	string getFullDesc();

	//returns date bday
	Date getDate() {return bday;}
	//returns age
	int getAge() { return age;}
};

#endif

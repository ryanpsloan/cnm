//Barbara Johnston's Person.h for Program 1
//Person.h

//This class represents a class for a generic person.
#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include "Date.h"

using namespace std;

#ifndef _PERSON_H
#define _PERSON_H

class Person 
{
protected:
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
	friend ostream& operator <<(ostream& os, Person p);
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

//PersonGen.h
//This is the Person Generator class definition.
//CIS2277, Program 2

#ifndef  _PERSONGEN_H
#define  _PERSONGEN_H

#include <string>
#include <vector>
#include <fstream>
#include "Person.h"


class PersonGen
{
	private:
	vector<string> maleNames;
	vector<string> femaleNames;
	vector<string> lastNames;
	vector<Person> personVector;
	
	int month, day, year;
	int lowYear;
	int highYear;
	int count;
	string name;
	bool bmaleOn;
	bool bfileOpen;
	
	ifstream openFile;

	void generateName();
	void generateMonth();
	void generateDay();
	void generateYear(int low, int high);
	void fillVectors();
	void readFile();
	
	public:
	PersonGen();	
	PersonGen(int youngAge, int oldAge);	
	Person getPerson();		
	Person* getNewPerson();	
	bool   createFile(string filename, int numOfPersons); 
	bool  useFile(string filename);	
	
}; 
#endif

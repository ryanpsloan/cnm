#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <sstream>
#include "PersonGen.h"
#include "Person.h"
using namespace std;

PersonGen::PersonGen()
{
	srand(static_cast<unsigned int> (time (0)));
	fillVectors();
	bmaleOn = true;
	lowYear = 5;
	highYear = 85;
	bfileOpen = false;
	
		
}

PersonGen::PersonGen(int sY, int mA)
{
	srand(static_cast<unsigned int> (time (0)));
	fillVectors();
	bmaleOn = true;
	lowYear = sY;
	highYear = mA;
	bfileOpen = false;
	
	//enter values for 
}

void PersonGen::readFile()
{
	
	string tempString;
	string monthSS, daySS, yearSS, nameSS;
	getline(openFile, tempString);
	while (!openFile.eof()) {
		stringstream ss;
		getline(openFile, tempString);
		ss << tempString;
		getline(ss, nameSS, '|');
		getline(ss, monthSS, '|');
		getline(ss, daySS, '|');
		getline(ss, yearSS);
		month = atoi(monthSS.c_str());
		day = atoi(daySS.c_str());
		year = atoi(yearSS.c_str());
		name = nameSS;
		
		Date date;
		string desc = "Birthday ";
		date.SetDate(month, day, year, desc);
		Person p(name, date);
		personVector.push_back(p);
	}
	openFile.close();
	count = 0;
}

Person PersonGen::getPerson()
{
	if(bfileOpen)
	{
			Person p = personVector.at(count);
			count++;
			if(count == personVector.size())
			{
				bfileOpen = false;
			}
			return p;
		
		
	}
	else
	{
		Date date;
		generateName();
		generateYear(lowYear, highYear);
		generateMonth();
		generateDay();
	
		string desc = "Birthday ";
		date.SetDate(month, day, year, desc);
		Person p(name, date);
	
		return p;
	}
}

Person* PersonGen::getNewPerson()
{
	
	if(bfileOpen)
	{
		Person * p = new Person();
		*p = personVector.at(count);
		Person * y = p;
		count++;
		if (count == personVector.size())
		{
			bfileOpen = false;
		}
		
		return y;
				
	}
	else
	{
		Date date;
		generateName();
		generateYear(lowYear, highYear);
		generateMonth();
		generateDay();
	
		string desc = "Birthday ";
		date.SetDate(month, day, year, desc);
		Person* y = new Person(name, date);
	
		return y;
	}
}

bool PersonGen::createFile(string fileName, int numOfPersons)
{
	
	ofstream outputFile;
	outputFile.open(fileName, ios::app);

	if(!outputFile)
	{
		return false;
	}

	outputFile << numOfPersons << endl;
	if(bfileOpen)
	{
		for (int i = 0; i < numOfPersons; ++i)
		{
			Person p = personVector.at(count);
			outputFile << p.getFullDesc() << endl;
			count++;
			if (count == personVector.size())
			{
				bfileOpen = false;
				if ( i < numOfPersons)
				{
					for (int j = i; j < numOfPersons; ++j)
					{
						generateName();
						generateYear(5,85);
						generateMonth();
						generateDay();
					
						outputFile << name << " | " << month << " | " << day << " | " << year << endl;
					}
					outputFile.close();
					return true;
				}
			}
		}	
		outputFile.close();
		return true;
	}	
	else 
	{	
		for(int i = 0; i < numOfPersons; i++ )
		{
			generateName();
			generateYear(5,85);
			generateMonth();
			generateDay();
		
			outputFile << name << " | " << month << " | " << day << " | " << year << endl;
		}
		outputFile.close();
		return true;
	}
}

bool PersonGen::useFile(string fileName)	
{
	openFile.open(fileName);
	if(!openFile)
	{
		return false;
	}
	else
	{
		bfileOpen = true;
		readFile();
		return true;
	}
	
}

void PersonGen::fillVectors()
{
	ifstream openLast, openMale, openFemale;
	openLast.open("Last.txt");
	if(!openLast)
	{
		exit(0);
	}
	openMale.open("FirstMale.txt");
	if(!openMale)
	{
		exit(0);
	}
	openFemale.open("FirstFemale.txt");
	if(!openFemale)
	{
		exit(0);
	}
	string tempString;
	for (int i = 0; i < 300; ++i)
	{
		getline(openLast, tempString);
		lastNames.push_back(tempString);
		getline(openMale, tempString);
		maleNames.push_back(tempString);
		getline(openFemale,tempString);
		femaleNames.push_back(tempString);
	}
	
	openLast.close();
	openMale.close();
	openFemale.close();
	
}


void PersonGen::generateName()
{
	int randomNum = rand() % 300;
	name = lastNames.at(randomNum);
	name += ", ";
	if(bmaleOn)
	{
		randomNum = rand() % 300;
		name += maleNames.at(randomNum);
		bmaleOn = false;
		
	}
	else
	{
		randomNum = rand() % 300;
		name += femaleNames.at(randomNum);
		bmaleOn = true;
		
	}
	
}



void PersonGen::generateMonth()
{
	month = rand() % 12 + 1;
}

void PersonGen::generateDay()
{
	if (month == 1 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		int randomNum = rand();
		day = (randomNum % 31) + 1;
	}
	else if (month == 2){
		if (year % 4 == 0 && year % 100 != 0)
		{
			int randomNum = rand();
			day = (randomNum % 29) + 1;
		}
		else
		{
			int randomNum = rand();
			day = (randomNum % 28) + 1;
		}
	}
	else if (month == 3 || month == 4 || month == 6 || month == 9 || month == 11){
		int randomNum = rand();
		day = (randomNum % 30) + 1;
	}
	
	
	
}
void PersonGen::generateYear(int low, int high)
{
	Date date;
	int randomNum = rand(); 
	int genNum = (randomNum % high);
	if(genNum < low)
	{
		year = (date.GetYear() - (genNum + low));
	}
	else
	{
		year = (date.GetYear() - genNum);
	}
	
}
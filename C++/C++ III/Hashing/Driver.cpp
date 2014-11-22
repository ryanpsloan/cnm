#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "Person.h"
#include "Date.h"
#include "PersonGen.h"
#include "ListMgr.h"
#include "PersonNode.h"
#include "SearchableListMgr.h"
#include "HashTable.h"


using namespace std;

#define FILEOFPERSONS "BJ_Persons2000.txt"
#define TOFIND "BJ_42PersonsToFind.txt"
#define TOTALPER 2000
#define FILENAME "Sloan_P7_Log.txt"
#define NUMTOFIND 42

int main()
{
	stringstream log;
	log << "Ryan Sloan - SloanP7 - Hash Table Log\n\n"; 
	//log << "FileName for PG1: " << FILEOFPERSONS << endl;
	//log << "FileName for PG2: " << TOFIND << endl << endl;

	log << "Creating new Pointer to Person and Pointer to Person Generator..." << endl << endl;
	Person *pPerA;
	PersonGen PG1;
	
	log << "Opening File: " << FILEOFPERSONS << endl;
	bool bFileOpen = PG1.useFile(FILEOFPERSONS);
	if(bFileOpen)
	{
		cout << "Successfully Using File: " << FILEOFPERSONS << endl;
		log << "Successfully Using File: " << FILEOFPERSONS << endl << endl;
	}
	else
	{
		cout << "Unable to Open File: " << FILEOFPERSONS << endl;
		log << "Unable to Open File: " << FILEOFPERSONS << endl << endl;
	
	}
	
	log << "Declaring Hash Table of 100 Buckets..." << endl << endl;
	HashTable hash;
	
	const int total = 100;
	int distribution[total];
	
	log << "Creating " << TOTALPER << " Persons..." << endl;
	for (int i = 0; i < TOTALPER; ++i) 
	{
		pPerA = PG1.getNewPerson();
		hash.hashFunction(pPerA);
	}

	log << "Hashing " << TOTALPER << " Persons..." << endl << endl;
	
	log << "Analyzing Distribution..." << endl;
	hash.analyzeTable(distribution, total);
	cout << "Table      " << " Number of Nodes per SLM " << "     " <<  " % of " << TOTALPER << " total Hashed Persons"<< endl;
	log << "Table      " << " Number of Nodes per SLM " << "     " <<  " % of " << TOTALPER << " total Hashed Persons"<< endl;
	for (int i = 0; i < total; ++i)
	{
		cout << "Table " << (i + 1) << " |             " << distribution[i] << "                    " << distribution[i]/2000.00 << "% "<< endl;
		log << "Table " << (i + 1) << " |              " << distribution[i] << "                   " << distribution[i]/2000.00 << "% "<< endl;
	}
	cout << "-------------------------------------" << endl << endl;
	log << "-------------------------------------" << endl << endl;
	
	string name = "SLOAN, RYAN";
	int m = 0;
	int d = 0;
	int y = 0;
	
	log << "Creating Second Person Generator..." << endl;
	PersonGen PG2;
	log << "Opening File: " << TOFIND << endl;
	bFileOpen = PG2.useFile(TOFIND);	//USING NAMES TO SEARCH FOR
	if(bFileOpen)
	{
		cout << "    Successfully Using File: " << TOFIND << endl;
		log << "    Successfully Using File: " << TOFIND << endl;
	}
	else
	{
		cout << "    Unable to Open File: " << TOFIND << endl << endl;
		log << "    Unable to Open File: " << TOFIND << endl << endl;
	
	}
	log << "Reading in Names to Find..." << endl;
	
	//getValue() in a for loop, first assignment of ppPer
	for(int j = 0; j < NUMTOFIND; ++j) 
	{
		Person* ptr = PG2.getNewPerson();
		name = ptr->getName();
		m = ptr->getDate().GetMonth();
		d = ptr->getDate().GetDay();
		y = ptr->getDate().GetYear();
		
		hash.getValue(name, m, d, y, pPerA);
		if(pPerA == NULL) {

			log << name << "-> NOT FOUND" << endl;
			cout << name << "-> NOT FOUND" << endl;
		}
		else
		{
			log << "FOUND: ";
			log << pPerA->getFullDesc() << "\n";
			cout << "FOUND: ";
			cout << pPerA->getFullDesc() << "\n";	
		}
	}
	log << "END OF FILE" << endl;

	//cout << "ENTER A NAME TO SEARCH FOR ie SLOAN, RYAN: ";
	//getline(cin, name);
	
	//cout << "ENTER A BIRTHDATE ie 10/10/2010: ";
	//cin >> m >> slash >> d >> slash >> y;
	//cin.ignore();
	log << "Setting up Log File: " << FILENAME << endl;
	ofstream outputLog;
	outputLog.open(FILENAME);
	if(outputLog)
	{
		log << "Writing to File" << endl;
	}
	outputLog << log.str();
	outputLog.close();
	
	return 0;
}



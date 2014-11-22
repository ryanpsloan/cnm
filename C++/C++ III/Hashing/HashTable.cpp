#include <iostream>

#include "HashTable.h"
#include "Date.h"
#include "Person.h"
#include "PersonGen.h"
#include "PersonNode.h"
using namespace std;

#define NUMOFBUCKETS 100

HashTable::HashTable()
{
	table = new SearchableListMgr[NUMOFBUCKETS];
}//constructor

void HashTable::hashFunction(Person *p)
{
	int key = 0;
	string name = p->getName();
	string firstName = name.substr((name.find(" ") + 1), name.back());
	string lastName = name.substr(0, name.find(","));
	for (size_t i = 0; i < lastName.length(); ++i)
	{
		char a = lastName.at(i);
		key += (int) a;
	}
	for (size_t i = 0; i < firstName.length(); ++i)
	{
		char b = firstName.at(i);
		key += (int) b;
	}
	//-----------------------------------------
	Date locDate = p->getDate();
	int mm = locDate.GetMonth();
	int dd = locDate.GetDay();
	int yy = locDate.GetYear();
	key += mm;
	key += dd;
	key += yy;
	//-------------------------------------------
	
	int indeX = key % NUMOFBUCKETS;
	table[indeX].push_back(p);
		
}	//hash function for storing a Person
									//key into an index

	//finds and returns the Person pointer that matches exactly
void HashTable::getValue(string name, int mm, int dd, int yy, Person* &pPerB)
{	
	Person* pP = NULL;
	int key = 0;
	string lastName = name.substr(0, name.find(","));
	string firstName = name.substr(name.find(" ") + 1);
	for (size_t i = 0; i < lastName.length(); ++i)
	{
		char a = lastName.at(i);
		key += (int) a;
	}	
	for (size_t i = 0; i < firstName.length(); ++i)
	{
		char b = firstName.at(i);
		key += (int) b;
	}
	//-----------------------------------------
	key += mm;
	key += dd;
	key += yy;
		
	//-------------------------------------------
		
	int indeX = key % NUMOFBUCKETS;
	bool bPresent = table[indeX].isPresent(name, mm, dd, yy, pP);
	pPerB = pP;
	if(bPresent)
	{
		return;
	}
	
}

	//analyze how well the table is balanced
void HashTable::analyzeTable(int distribution[], int total)
{
	
	for(int i= 0; i < total; ++i)
	{
		distribution[i] = table[i].size();
	}
}

	//destructor
HashTable::~HashTable()
{
	delete[] table;
}
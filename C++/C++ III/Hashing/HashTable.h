#include <string>
#include "SearchableListMgr.h"
#include "Person.h"
using namespace std;

class HashTable
{
private:
	SearchableListMgr *table;	//pointer for an array of ListMgrs (Linked Lists)

		//in Constructor do table = new SearchableListMgr[100];
		//OR
		//could just use SearchableListMgr table[100]; here

public:
	HashTable();					//constructor

	void hashFunction(Person *p);	//hash function for storing a Person
									//key into an index

	//finds and returns the Person pointer that matches exactly
	void getValue(string name, int mm, int dd, int yy, Person* &pPer);

	
	//analyze how well the table is balanced
	void analyzeTable(int distribution[], int total);	

	//destructor
	~HashTable();
};

// IN ORDER TO DETERMINE THE INDEX:
///////////////////////////////////
/* 
	int key = 0;
	//I assign the Person's name into a string
	string locName = p->getName();
	//then I take the person's last name
	string lastName = locName.substr(0, locName.find(","));
	//and add all the letters together
	for (size_t i = 0; i < lastName.length(); ++i)
	{
		char a = lastName.at(i);
		key += (int) a;
	}	
	//then I get the birthday information
	Date locDate = p->getDate();
	//assign it to ints
	int mm = locDate.GetMonth();
	int dd = locDate.GetDay();
	int yy = locDate.GetYear();
	//and add them all together
	key += mm;
	key += dd;
	key += yy;

	//Next I add in the age
	int age = p.getAge();
	key += age;
	
	////////////////////////////////////////////////////////
	// Then I modulus the sum by 100 to determine a number between 0 and 99 which is the index number.
	int indeX = key % 100;
	
	



Example 1
SLOAN, RYAN 34 08/10/1979
int a = 34;
int b = 8;
int c = 10;
int d = 1979;
int m = (int) 'S';
int n = (int) 'L';
int o = (int) 'O';
int p = (int) 'A';
int q = (int) 'N';
int equation = (a + b) + (c + d) + (m + n) + (o + p) + q; //equation = 2412;
int index = equation % 100; //index = 12;

Example 2
POTTER, HARRY 23 06/23/1990
	int a = 23;
	int b = 6;
	int c = 23;
	int d = 1990;
	int m = (int) 'P';
	int n = (int) 'O';
	int o = (int) 'T';
	int p = (int) 'T';
	int q = (int) 'E';
	int r = (int) 'R';
	int equation = (a + b) + (c + d) + (m + n) + (o + p) + (q + r); //equation = 2520;
	int index = equation % 100; //index = 20;
	
	//the use of modulus (% 100) ensures that the value generated for the index will be between 0-99.
	//this alleviates the concern for calculating an index thats out of range.

*/
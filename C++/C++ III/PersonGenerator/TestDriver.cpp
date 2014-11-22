//Ryan Sloan
//TestDriver.cpp - Program 2
//

#include <iostream>
#include <string>
#include "PersonGen.h"

using namespace std;

int main()
{
	PersonGen pGen;
	cout << "Using File" << endl;
	bool fileEngaged = pGen.useFile("P5LinkedListPeopleNov6.txt");
	if(fileEngaged)
	{
		cout << "File Ready" << endl;
	}
	else
	{
		cout << "Unable to Open File" << endl;
	}
	for(int i = 0; i < 20; ++i)
	{
		cout << pGen.getPerson().getFullDesc() << endl;
		
	}
	cout << "-----------------------------------------" << endl;
	for(int i = 0; i < 20; ++i)
	{
		cout << pGen.getNewPerson()->getFullDesc() << endl;
	
	}
	string fileName;
	cout << "Enter a filename i.e. PersonList.txt" << endl;
	cin >> fileName;
	cin.ignore();
	
	int num;
	cout << "Enter the number of persons to create: ";
	cin >> num;
	cin.ignore();

	cout << "Creating " << num << " persons in file: " << fileName << endl;
	PersonGen pg;
	
	bool test = pg.createFile(fileName, num);
	if(test){
		 cout << "File Created" << endl << endl;
	}
	else {
		cout << "No File Created" << endl << endl;
	}
	


	cout << "Creating a Person using getPerson():" << endl;
	Person bob;
	bob = pg.getPerson();
	cout << bob.getFullDesc() << endl << endl << endl;
		
	cout << "Creating a point to a Person using getNewPerson()" << endl;
	Person * bobsSister;
	bobsSister = pg.getNewPerson();
	cout << bobsSister->getFullDesc() << endl << endl << endl;
	


	int year, age;
	cout << "What age range would you like to test?" << endl;
	cout << "Enter a starting year and a maximum age with a space: " << endl;
	cin >> year >> age;
	cin.ignore();

	cout << "Calling the overloaded construtor with the values " << year << " ," << age << endl;
	PersonGen oPG(year, age);
	cout << oPG.getPerson().getFullDesc() << endl;
	cout << oPG.getPerson().getFullDesc() << endl;
	cout << oPG.getPerson().getFullDesc() << endl;
	cout << oPG.getPerson().getFullDesc() << endl;
	cout << oPG.getPerson().getFullDesc() << endl;
	cout << oPG.getPerson().getFullDesc() << endl;
	cout << oPG.getPerson().getFullDesc() << endl;
	cout << oPG.getPerson().getFullDesc() << endl;
	
	
	
	return 0;
}
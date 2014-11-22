

#include <iostream>
#include <string>
#include <sstream>
#include "Person.h"
#include "PersonGen.h"
#include "TemplateDataNode.h"
#include "DataClass.h"
#include "TemplateListMgr.h"
#include "ScriptReader.h"
using namespace std;

//#define FILENAME "P5TestScript.txt"
#define outputFileName "RyanSloanLogP5.txt"

int main()
{
	TemplateListMgr<int> intTLM;
	TemplateListMgr<string> stringTLM;
	TemplateListMgr<Person> personTLM;
	PersonGen pGen;
	for(int i = 0; i < 5; ++i)
	{
		Person * pPer = pGen.getNewPerson();
		personTLM.push_back(pPer);
		string tempStr = pPer->getName();
		stringTLM.push_back(&tempStr);
		int integer = i * 5;
		intTLM.push_back(&integer);
	}
	
	personTLM.show();
	stringTLM.show();
	intTLM.show();

	system("pause");
	
	//ScriptReader scripty(FILENAME);
	char condition1 = 'n', condition2 = 'n', condition3 = 'n';
	char declaration = 'Y';
	stringstream ss;
	int choice;
	
	do
	{
		cout << "Which List Would You Like to Interact With?" << endl;
		cout << "1__int List" << endl;
		cout << "2. string List" << endl;
		cout << "3- Person List" << endl;
		cout << "==>";
		cin >> choice;
		if (choice == 1) {
			do {
				int input, pos, num;
				string name;
				cout << "\n\n1. " << "Show list\n";
				cout << "2. " << "Add to front of list\n";
				cout << "3. " << "Add to back of list\n";
				cout << "4. " << "Remove from front\n";
				cout << "5. " << "Remove from back\n";
				cout << "6. " << "Remove selected item\n";
				cout << "7. " << "Front\n";
				cout << "8. " << "Back\n";
				cout << "9. " << "Erase\n";
				cout << "10." << "Clear\n";
				cout << "11." << "Size\n";
				cout << "12." << "Quit the program\n";
				cout << "==> ";
				cin >> input;
				cin.ignore();
				//input = scripty.getNextInt();
				ss << "\n\nEntry: " << input << endl;;

				if(input == 1)
				{
					ss << "\nShow the List" << endl;
					intTLM.show();
					ss << intTLM.showString() << endl;
				}
				else if (input == 2)
				{
					int i = rand();
					int *pI = &i;
					intTLM.push_front(pI);
					intTLM.show();
					ss << "\nPush_Front: " << *pI << endl;
					ss << "\n\nThe Current List: \n" << intTLM.showString() << endl;
				}
				else if (input == 3)
				{
					int i = rand();
					int *pI = &i;
					intTLM.push_back(pI);
					intTLM.show();
					ss << "\nPush_Back: " << *pI << endl;
					ss << "\n\nThe Current List: \n" << intTLM.showString() << endl;
				}		
				else if(input == 4)
				{
					if (!intTLM.empty()) {
						ss << "\nPop_Front: " << intTLM.front() << endl;
						intTLM.pop_front();
						intTLM.show();
						ss << "\n\nThe Current List: \n" << intTLM.showString() << endl;
				
					}
					else
					{
						ss << "\n\nPop_Front: " << "The List is Empty" << endl;
						cout << "\nThe List is Empty" << endl;
					}
				}
				else if(input == 5)
				{
					if (!intTLM.empty()) {
						ss << "\nPop_Back: " << intTLM.back() << endl;
						intTLM.pop_back();
						intTLM.show();
						ss << "\n\nThe Current List: \n" << intTLM.showString() << endl;
				
					}
					else
					{
						ss << "\nPop_Back: " << "The List is Empty" << endl;
						cout << "\nThe List is Empty" << endl;
					}
				}
				else if(input == 6)
				{
					if(!intTLM.empty()) {
						cout << "\nEnter a number to search and remove: ";
						cin >> num;
						cin.ignore();
						//num = scripty.getNextInt();
						cout << "\n" << num << endl;
						intTLM.remove(num);
						intTLM.show();
						ss << "\nRemove: " << num << endl;
						ss << "\n\nThe Current List: \n" << intTLM.showString() << endl;
					}
				}
				else if (input == 7)
				{
					if (intTLM.front() != NULL) {
						cout << intTLM.front() << endl;
						ss << "\nGet Front: " << intTLM.front();
						ss << "\n\nThe Current List: \n" << intTLM.showString() << endl;
				
					}
					else
					{
						cout << "\nThere is no one on the list" << endl;
						ss << "\nGet Front: " << "There is no one on the list" << endl;
						ss << "\n\nThe Current List: \n" << intTLM.showString() << endl;
					}
				}	
				else if (input == 8)
				{
					if (intTLM.back() != NULL) {
						cout << intTLM.back() << endl;
						ss << "\nGet Back: " << intTLM.back();
						ss << "\n\nThe Current List: \n" << intTLM.showString() << endl;
					}
					else
					{
						cout << "\nThere is no one on the list" << endl;
						ss << "\n\nGet Back: " << "There is no one on the list" << endl;
						ss << "\n\nThe Current List: \n" << intTLM.showString() << endl;
					}

				}
				else if (input == 9)
				{
					if(!intTLM.empty())
					{
						intTLM.show();
						cout << "\nEnter the position number you want to remove: ";
						cin >> pos;
						cin.ignore();
						//pos = scripty.getNextInt();
						ss << "\nErase Position: " << pos << endl;
						intTLM.erase(pos);
						intTLM.show();			
						ss << "\n\nThe Current List: \n" << intTLM.showString() << endl;
					}
				}
				else if (input == 10)
				{
					intTLM.clear();
					intTLM.show();
					ss << "\nClear" << endl;
					ss << "\n\nThe Current List: \n" << intTLM.showString() << endl;
				
				}
				else if (input == 11)
				{
					cout << "\nSize: " << intTLM.size() << endl;
					ss << "\nSize: " << intTLM.size() << endl;
					intTLM.show();
					ss << "\n\nThe Current List: \n" << intTLM.showString() << endl;
				}
				else if (input == 12)
				{
					ss << "\n\nExiting... " << endl;
					cout << "\n\nExiting... " << endl;
					condition1 = 'y';
				}
			}while(condition1 == 'n');		
		}
		else if (choice == 2) {
			do {
				int input, pos;
				string name, var;
				cout << "\n\n1. " << "Show list\n";
				cout << "2. " << "Add to front of list\n";
				cout << "3. " << "Add to back of list\n";
				cout << "4. " << "Remove from front\n";
				cout << "5. " << "Remove from back\n";
				cout << "6. " << "Remove selected item\n";
				cout << "7. " << "Front\n";
				cout << "8. " << "Back\n";
				cout << "9. " << "Erase\n";
				cout << "10." << "Clear\n";
				cout << "11." << "Size\n";
				cout << "12." << "Quit the program\n";
				cout << "==> ";
				cin >> input;
				cin.ignore();
				//input = scripty.getNextInt();
				ss << "\n\nEntry: " << input << endl;;

				if(input == 1)
				{
					ss << "\nShow the List" << endl;
					stringTLM.show();
					ss << stringTLM.showString() << endl;
				}
				else if (input == 2)
				{
					string s = "Push_Front";
					string *pS = &s;
					stringTLM.push_front(pS);
					stringTLM.show();
					ss << "\nPush_Front: " << *pS << endl;
					ss << "\n\nThe Current List: \n" << stringTLM.showString() << endl;
				}
				else if (input == 3)
				{
					string s = "Push_Back";
					string *pS = &s;
					stringTLM.push_back(pS);
					stringTLM.show();
					ss << "\nPush_Back: " << *pS << endl;
					ss << "\n\nThe Current List: \n" << stringTLM.showString() << endl;
				}		
				else if(input == 4)
				{
					if (!stringTLM.empty()) {
						ss << "\nPop_Front: " << stringTLM.front() << endl;
						stringTLM.pop_front();
						stringTLM.show();
						ss << "\n\nThe Current List: \n" << stringTLM.showString() << endl;
				
					}
					else
					{
						ss << "\n\nPop_Front: " << "The List is Empty" << endl;
						cout << "\nThe List is Empty" << endl;
					}
				}
				else if(input == 5)
				{
					if (!stringTLM.empty()) {
						ss << "\nPop_Back: " << stringTLM.back() << endl;
						stringTLM.pop_back();
						stringTLM.show();
						ss << "\n\nThe Current List: \n" << stringTLM.showString() << endl;
				
					}
					else
					{
						ss << "\nPop_Back: " << "The List is Empty" << endl;
						cout << "\nThe List is Empty" << endl;
					}
				}
				else if(input == 6)
				{
					if(!stringTLM.empty()) {
						cout << "\nEnter a string to search and remove: ";
						getline(cin, var);
						//var = scripty.getNextString();
						cout << "\n" << var << endl;
						stringTLM.remove(var);
						stringTLM.show();
						ss << "\nRemove: " << var << endl;
						ss << "\n\nThe Current List: \n" << stringTLM.showString() << endl;
					}
				}
				else if (input == 7)
				{
					if (stringTLM.size() > 0) {
						cout << stringTLM.front() << endl;
						ss << "\nGet Front: " << stringTLM.front();
						ss << "\n\nThe Current List: \n" << stringTLM.showString() << endl;
				
					}
					else
					{
						cout << "\nThere is no one on the list" << endl;
						ss << "\nGet Front: " << "There is no one on the list" << endl;
						ss << "\n\nThe Current List: \n" << stringTLM.showString() << endl;
					}
				}	
				else if (input == 8)
				{
					if (stringTLM.size() != 0) {
						cout << stringTLM.back() << endl;
						ss << "\nGet Back: " << stringTLM.back();
						ss << "\n\nThe Current List: \n" << stringTLM.showString() << endl;
					}
					else
					{
						cout << "\nThere is no one on the list" << endl;
						ss << "\n\nGet Back: " << "There is no one on the list" << endl;
						ss << "\n\nThe Current List: \n" << stringTLM.showString() << endl;
					}

				}
				else if (input == 9)
				{
					if(!stringTLM.empty())
					{
						stringTLM.show();
						cout << "\nEnter the position number you want to remove: ";
						cin >> pos;
						cin.ignore();
						//pos = scripty.getNextInt();
						ss << "\nErase Position: " << pos << endl;
						stringTLM.erase(pos);
						stringTLM.show();			
						ss << "\n\nThe Current List: \n" << stringTLM.showString() << endl;
					}
				}
				else if (input == 10)
				{
					stringTLM.clear();
					stringTLM.show();
					ss << "\nClear" << endl;
					ss << "\n\nThe Current List: \n" << stringTLM.showString() << endl;
				
				}
				else if (input == 11)
				{
					cout << "\nSize: " << stringTLM.size() << endl;
					ss << "\nSize: " << stringTLM.size() << endl;
					stringTLM.show();
					ss << "\n\nThe Current List: \n" << stringTLM.showString() << endl;
				}
				else if (input == 12)
				{
					ss << "\n\nExiting... " << endl;
					cout << "\n\nExiting... " << endl;
					condition2 = 'y';
				}
			}while(condition2 == 'n');		
		}
		else if (choice == 3) {
			do {
				int input, pos;
				string name;
				
				cout << "\n\n1. " << "Show list\n";
				cout << "2. " << "Add to front of list\n";
				cout << "3. " << "Add to back of list\n";
				cout << "4. " << "Remove from front\n";
				cout << "5. " << "Remove from back\n";
				cout << "6. " << "Remove selected item\n";
				cout << "7. " << "Front\n";
				cout << "8. " << "Back\n";
				cout << "9. " << "Erase\n";
				cout << "10." << "Clear\n";
				cout << "11." << "Size\n";
				cout << "12." << "Quit the program\n";
				cout << "==> ";
				cin >> input;
				cin.ignore();
				//input = scripty.getNextInt();
				ss << "\n\nEntry: " << input << endl;;

				if(input == 1)
				{
					ss << "\nShow the List" << endl;
					personTLM.show();
					ss << personTLM.showString() << endl;
				}
				else if (input == 2)
				{
					Person * newPer = pGen.getNewPerson();
					personTLM.push_front(newPer);
					personTLM.showPerson();
					ss << "\nPush_Front: " << newPer->getFullDesc() << endl;
					ss << "\n\nThe Current List: \n" << personTLM.showString() << endl;
				}
				else if (input == 3)
				{
					Person * newPer = pGen.getNewPerson();
					personTLM.push_back(newPer);
					personTLM.showPerson();
					ss << "\nPush_Back: " << newPer->getFullDesc() << endl;
					ss << "\n\nThe Current List: \n" << personTLM.showString() << endl;
				}		
				else if(input == 4)
				{
					if (!personTLM.empty()) {
						ss << "\nPop_Front: " << personTLM.front().getFullDesc() << endl;
						personTLM.pop_front();
						personTLM.showPerson();
						ss << "\n\nThe Current List: \n" << personTLM.showString() << endl;
				
					}
					else
					{
						ss << "\n\nPop_Front: " << "The List is Empty" << endl;
						cout << "\nThe List is Empty" << endl;
					}
				}
				else if(input == 5)
				{
					if (!personTLM.empty()) {
						ss << "\nPop_Back: " << personTLM.back().getFullDesc() << endl;
						personTLM.pop_back();
						personTLM.showPerson();
						ss << "\n\nThe Current List: \n" << personTLM.showString() << endl;
				
					}
					else
					{
						ss << "\nPop_Back: " << "The List is Empty" << endl;
						cout << "\nThe List is Empty" << endl;
					}
				}
				else if(input == 6)
				{
					if(!personTLM.empty()) {
						cout << "\nEnter a Person's name to search and remove ie SLOAN, RYAN : ";
						getline(cin, name);
						//name = scripty.getNextString();
						Person p;
						p.setName(name);
						cout << "\n" << name << endl;
						personTLM.removePerson(p);
						personTLM.showPerson();
						ss << "\nRemove: " << name << endl;
						ss << "\n\nThe Current List: \n" << personTLM.showString() << endl;
					}
				}
				else if (input == 7)
				{
					if (personTLM.size() > 0) {
						cout << personTLM.front().getFullDesc() << endl;
						ss << "\nGet Front: " << personTLM.front().getFullDesc();
						ss << "\n\nThe Current List: \n" << personTLM.showString() << endl;
				
					}
					else
					{
						cout << "\nThere is no one on the list" << endl;
						ss << "\nGet Front: " << "There is no one on the list" << endl;
						ss << "\n\nThe Current List: \n" << personTLM.showString() << endl;
					}
				}	
				else if (input == 8)
				{
					if (personTLM.size() != 0) {
						cout << personTLM.back().getFullDesc() << endl;
						ss << "\nGet Back: " << personTLM.back().getFullDesc();
						ss << "\n\nThe Current List: \n" << personTLM.showString() << endl;
					}
					else
					{
						cout << "\nThere is no one on the list" << endl;
						ss << "\n\nGet Back: " << "There is no one on the list" << endl;
						ss << "\n\nThe Current List: \n" << personTLM.showString() << endl;
					}

				}
				else if (input == 9)
				{
					if(!personTLM.empty())
					{
						personTLM.showPerson();
						cout << "\nEnter the position number you want to remove: ";
						cin >> pos;
						cin.ignore();
						//pos = scripty.getNextInt();
						ss << "\nErase Position: " << pos << endl;
						personTLM.erase(pos);
						personTLM.showPerson();			
						ss << "\n\nThe Current List: \n" << personTLM.showString() << endl;
					}
				}
				else if (input == 10)
				{
					personTLM.clear();
					personTLM.showPerson();
					ss << "\nClear" << endl;
					ss << "\n\nThe Current List: \n" << personTLM.showString() << endl;
				
				}
				else if (input == 11)
				{
					cout << "\nSize: " << personTLM.size() << endl;
					ss << "\nSize: " << personTLM.size() << endl;
					personTLM.showPerson();
					ss << "\n\nThe Current List: \n" << personTLM.showString() << endl;
				}
				else if (input == 12)
				{
					ss << "\n\nExiting... " << endl;
					cout << "\n\nExiting... " << endl;
					condition3 = 'y';
				}
			}while(condition3 == 'n');		
		}
	cout << "Would you like to access another list manager? Y/N :";
	cin >> declaration;
	cin.ignore();
	} while (declaration == 'Y');
	
	ofstream outputFile;
	
	// Open the file for writing
	outputFile.open(outputFileName);

	// Check that we've open the file
	if(!outputFile)
	{
		cout << "\nWhoops! Can't open log file " << outputFileName;
		
	}
	else
	{
		// Write to the file
		outputFile << "Ryan Sloan " << endl;
		outputFile << "Linked List Script Log " << endl;
		outputFile << ss.str();
		// close the file
		outputFile.close();
	}
		






return 0;
}
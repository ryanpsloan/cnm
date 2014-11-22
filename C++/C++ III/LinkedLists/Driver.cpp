#include "ListMgr.h"
#include "PersonNode.h"
#include "SloanPersonGen\PersonGen.h"
#include "ScriptReader.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#define FILENAME "P5TestScript.txt"
#define rFILENAME "P5LinkedListPeopleNov6.txt"
#define outputFileName "RyanSloanLogP5.txt"

int main()
{
	Person * newPer;
	ListMgr ryan;
	PersonGen del;
	del.useFile(rFILENAME);
	ScriptReader scripty(FILENAME);
	char condition = 'n';
	stringstream ss;
	
	do
	{
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
		input = scripty.getNextInt();
		cout << input;
		ss << "\n\nEntry: " << input << endl;;

		if(input == 1)
		{
			ss << "\nShow the List" << endl;
			ryan.show();
			ss << ryan.showString() << endl;
		}
		else if (input == 2)
		{
			newPer = del.getNewPerson();
			ryan.push_front(newPer);
			ryan.show();
			ss << "\nPush_Front: " << newPer->getName() << endl;
			ss << "\n\nThe Current List: \n" << ryan.showString() << endl;
		}
		else if (input == 3)
		{
			newPer = del.getNewPerson();
			ryan.push_back(newPer);
			ryan.show();
			ss << "\nPush_Back: " << newPer->getName() << endl;
			ss << "\n\nThe Current List: \n" << ryan.showString() << endl;
		}		
		else if(input == 4)
		{
			if (!ryan.empty()) {
				ss << "\nPop_Front: " << ryan.front()->getName() << endl;
				ryan.pop_front();
				ryan.show();
				ss << "\n\nThe Current List: \n" << ryan.showString() << endl;
				
			}
			else
			{
				ss << "\n\nPop_Front: " << "The List is Empty" << endl;
				cout << "\nThe List is Empty" << endl;
			}
		}
		else if(input == 5)
		{
			if (!ryan.empty()) {
				ss << "\nPop_Back: " << ryan.back()->getName() << endl;
				ryan.pop_back();
				ryan.show();
				ss << "\n\nThe Current List: \n" << ryan.showString() << endl;
				
			}
			else
			{
				ss << "\nPop_Back: " << "The List is Empty" << endl;
				cout << "\nThe List is Empty" << endl;
			}
		}
		else if(input == 6)
		{
			if(!ryan.empty()) {
				cout << "\nEnter a name to search and remove: ";
				name = scripty.getNextString();
				cout << "\n" << name << endl;
				ryan.remove(name);
				ryan.show();
				ss << "\nRemove: " << name << endl;
				ss << "\n\nThe Current List: \n" << ryan.showString() << endl;
			}
		}
		else if (input == 7)
		{
			if (ryan.front() != NULL) {
				cout << ryan.front()->getName() << endl;
				ss << "\nGet Front: " << ryan.front()->getName();
				ss << "\n\nThe Current List: \n" << ryan.showString() << endl;
				
			}
			else
			{
				cout << "\nThere is no one on the list" << endl;
				ss << "\nGet Front: " << "There is no one on the list" << endl;
				ss << "\n\nThe Current List: \n" << ryan.showString() << endl;
			}
		}	
		else if (input == 8)
		{
			if (ryan.back() != NULL) {
				cout << ryan.back()->getName() << endl;
				ss << "\nGet Back: " << ryan.back()->getName();
				ss << "\n\nThe Current List: \n" << ryan.showString() << endl;
			}
			else
			{
				cout << "\nThere is no one on the list" << endl;
				ss << "\n\nGet Back: " << "There is no one on the list" << endl;
				ss << "\n\nThe Current List: \n" << ryan.showString() << endl;
			}

		}
		else if (input == 9)
		{
			if(!ryan.empty())
			{
				cout << "\nEnter the position number you want to remove: ";
				pos = scripty.getNextInt();
				ss << "\nErase Position: " << pos << endl;
				ryan.erase(pos);
				ryan.show();			
				ss << "\n\nThe Current List: \n" << ryan.showString() << endl;
			}
		}
		else if (input == 10)
		{
			ryan.clear();
			ryan.show();
			ss << "\nClear" << endl;
			ss << "\n\nThe Current List: \n" << ryan.showString() << endl;
			
		}
		else if (input == 11)
		{
			cout << "\nSize: " << ryan.size() << endl;
			ss << "\nSize: " << ryan.size() << endl;
			ryan.show();
			ss << "\n\nThe Current List: \n" << ryan.showString() << endl;
		}
		else if (input == 12)
		{
			ss << "\n\nExiting... " << endl;
			cout << "\n\nExiting... " << endl;
			condition = 'y';
		}
	}while(condition == 'n');

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
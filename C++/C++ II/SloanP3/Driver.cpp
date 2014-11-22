// Ryan Sloan
// ryansdeal@hotmail.com
// Driver.cpp

#include<iostream>
#include<string>
#include<vector>
#include"NameSearch.h"
#include"P3_TemplateSort.h"
#include"Functions.h"

using namespace std;

int main()
{
	Header();
	vector<string> firstName;
	vector<string> lastName;
	NameSearch name;
	int choice;
	string filename;
	cout << "1. Enter the file to be read? Or" << endl;
	cout << "2. Have the program read P3_Names10K.txt?" << endl;
	cout << "Enter 1 or 2 >> ";
	cin >> choice;
	cin.ignore();
	switch(choice)
	{
	case 1:
		cout << "Enter the filename >> ";
		getline(cin,filename);
		name.setFileName(filename);
		break;
	case 2:
		filename = "P3_Names10K.txt";
		name.setFileName(filename);
		break;
	default:
		cout << "That was not a valid entry" << endl;
	}
	bool bFileOpen = name.isOpen();
	if (bFileOpen)
	{
		cout << "File read successfully" << endl;
		cout << "Read " << name.getTotal() << " names" << endl;
	}
	int loop;
	do
	{
		cout << "Please choose a menu item: \n";
		cout << "\t1. Search for a first name \n";
		cout << "\t2. Search for a last name \n";
		cout << "\t3. Number of Items in the array \n";
		cout << "\t4. Exit the program \n";
		cout << "\t>> ";
		cin >> loop;
		cin.ignore();
		cout << endl;
		string sName = " ";
		bool found;
		switch(loop)
		{
		case 1:
			cout << "Enter the name >> ";
			getline(cin, sName);
			cout << "************" << "Searching for the First name: " << sName << "**********\n\n";
			found = name.findFirstNames(firstName, sName);
			if (found)
			{
				cout << "Results Found!" << endl;
				for (unsigned int i = 0; i < firstName.size(); ++i)
				{
					cout << firstName[i] << endl;
				}
				cout << endl;
			}
			else
			{
				cout << "No Results Found." << endl;
				cout << endl;
			}
			firstName.clear();
			break;
		case 2:
			cout << "Enter the name >> ";
			getline(cin, sName);
			cout << "***********" << "Searching for the Last name: " << sName << "************\n\n";
			found = name.findLastNames(lastName, sName);
			if (found)
			{
				cout << "Results Found!" << endl;
				for (unsigned int i = 0; i < lastName.size(); ++i)
				{
					cout << lastName[i] << endl;
				}
				cout << endl;
			}
			else
			{
				cout << "No Results Found." << endl;
				cout << endl;
			}
			lastName.clear();
			break;
		case 3:
			cout << "The total items in the array is " << name.getTotal() << endl << endl;
			break;
		case 4:
			cout << "Goodbye and Farewell \n\n";
			break;
		default:
			cout << "That is not a valid entry." << endl;
		}

	}while(loop != 4);

	return 0;
}
#include <iostream>
#include <string>
#include "Person.h"
#include "Date.h"

using namespace std;

int main()
{	
	cout << "The Person Class\n\n";
	Person person;
	cout << "Person created with a default constructor" << endl;
	cout << person.getFullDesc() << endl;
	
	string name;
	int month, day, year;
	
	cout << "Enter the Person's Name: Last name,First name no spaces \n";
	cin >> name;
	cin.ignore();
	person.setName(name);
	cout << "Enter the Person's Birthday\n";
	cout << "\nMonth: ";
	cin >> month;
	cin.ignore();
	cout << "\nDay: ";
	cin >> day;
	cin.ignore();
	cout << "\nYear: ";
	cin >> year;
	cin.ignore();
	cout << "Setting the birthday using integers..." << endl;
	person.setBirthday(month,day,year);
	cout << month << " / " << day << " / " << year;
	cout << "\n\n";
	cout << "Setting the birtday using date object..." << endl;
	Date dateObj;
	dateObj.SetDate(month,day,year,"");
	person.setBirthday(dateObj);
	cout << "Date " << dateObj.GetFormattedDate() << endl;
	cout << "**********************************" << endl;
	
	
	cout << "You entered: " << person.getNameAge() << endl;

	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
	string test = "Smith,James";
	cout << endl;
	cout << "Enter a test name:  Last,First no spaces\n";
	cin >> test;
	cin.ignore();
	
	
	cout << "\nThe comparison name is " << test << "\n\n";
	if (name > test)
		cout << name << " > " << test << " is true\n";
	else
		cout << name << " > " << test << " is false\n";
	if (name < test)
		cout << name << " < " << test << " is true\n";
	else
		cout << name << " < " << test << " is false\n";
	if (name == test)
		cout << name << "==" << test << " is true\n";
	else
		cout << name << "==" << test << " is false\n";
	cout << "++++++++++++++++++++++++++++++++++++" << endl;
	
	
	cout << endl;
	cout << "GetName: " << person.getName() << endl << endl;
	cout << "GetFullDescription: \n" << person.getFullDesc() << endl;
	cout << "GetNameAge: " << person.getNameAge() << endl;
	cout << endl;
	cout << "*************************************************" << endl;
	int m,d,y;
	string v_name;
	cout << endl;
	cout << "Testing Constructors. Enter a name: Last,First no spaces" << endl;
	cin >> v_name;
	cout << "\n";
	cout << "Enter a date of birth: " << endl;
	cout << "Month: ";
	cin >> m;
	cin.ignore();
	cout << "Day: ";
	cin >> d;
	cin.ignore();
	cout << "Year: ";
	cin >> y;
	cin.ignore();
	cout << endl;

	cout << "Creating a Person with a date object" << endl;
	Date dateObj2;
	dateObj2.SetDate(m,d,y,"Birthday:");
	Person person2(v_name, dateObj2);
	cout << person2.getFullDesc() << endl;
	
	cout << "Creating a Person with integers" << endl;
	Person person3(v_name,m,d,y);
	cout << person3.getFullDesc() << endl;

	return 0;
}
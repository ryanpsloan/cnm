//NameSearch.h
//This file is provided to CIS2275 students for Program 3
//DO NOT MODIFY THIS FILE unless instructed.
// You will write the NameSearch.cpp file.
//NOTE: There are NO cout << statements in the NameSearch.cpp!

#ifndef  _NAMESEARCH_H
#define  _NAMESEARCH_H

#include <string>
#include <vector>
using namespace std;

class NameSearch
{
private:
	string names[10000];	//holds names read from file

	int total;		/*total number of names read from file, 
					class will read up to 10,000, 
					stops reading after 10,000th.*/
					
		/*NOTE: do not assume you'll have 10,000 in the file
		Your program should work with 10 items in file.
		Test program with files with <10,000, 10,000 and >10,000*/

	bool bOpen;	//true if file read successfully
					//false if file not read successfully

	void ReadFile();	//reads the file, fills names array and sorts data
						//assigns total & bOpen
						
	void sort();		//uses the sorter provided to you to sort the names array

	string name;		//user's requested name to look for in the list
	string filename;	//the name of the file that is read

public:

	//Two constructors, be sure to initialize data appropriately
	NameSearch();			//no file, does not try to read anything		
	NameSearch(string fName);	//is passed desired file, calls readFile()

	void setFileName(string fName);	//is passed desired file
										//calls readFile()

	bool isOpen();		/*returns bOpen flag.  The programmer *should* check 
						this before attempting to search for a name. The finds
						are designed to anticipate no data just in case*/
	
	/* find functions are passed a reference to a vector and a string. Each looks
	for the name, and fill the vectors with the full names containing that name.
	The name searching algorithm is performed in the find functions.
	Programming note: if name is not found, the find returns a false and the vector 
	contains no names.*/

	bool findFirstNames(vector<string> &vsFirst, string name);
	bool findLastNames(vector<string> &vsLast, string name);

	int getTotal();	//returns the total number read from the file.
					//if the file hasn't been read or was not read successfully, 
					//returns a -1
	
};

#endif
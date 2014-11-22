// Ryan Sloan
// rsloan2@cnm.edu
// NameSearch.cpp

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include "NameSearch.h"
#include "P3_TemplateSort.h"
#include "Functions.h"

using namespace std;

void Header()
{
	cout << "Ryan Sloan \nProgram 3 \nThe NameSearch Class \n" << endl;
}

NameSearch::NameSearch()	//default constructor
{
	for(int i = 0; i < 10000; ++i)
		{
			names[i] = " ";
		}
	total = 0;
	
}

NameSearch::NameSearch(string fName)	//is passed desired file, calls readFile()
{
	filename = fName;
	
	for(int i = 0; i < 10000; ++i)
		{
			names[i] = " ";
		}
	total = 0;
	

}

void NameSearch::ReadFile() // opens file and reads data into an array
{
	ifstream openFile;

	openFile.open(filename);

	if(!openFile)
	{
		bOpen = false;
		total = -1;
	}
	// Read the file
	int i = 0;
	while( !openFile.eof() )
	{
		getline(openFile, names[i]);
		total++; //counts the number of lines 
		i++;
		 
	}

	// Finsihed reading the file, close the file.
	openFile.close();
	sort();
	bOpen = true;
}

void NameSearch::setFileName(string fName)
{
	filename = fName;
	ReadFile();
}

bool NameSearch::isOpen()
{
	return bOpen;
}

bool NameSearch::findFirstNames(vector<string> &vsFirst, string sName)
{
	name = "";
	vsFirst.clear();
	for (unsigned int h = 0; h < sName.length(); ++h)
	{
		name += toupper(sName[h]);
	}
	for (int i = 0; i < total; ++i)
	{
		int pos = names[i].find(' ');
		int final = names[i].find(name,pos);
		if (final >= 0)
		{
			vsFirst.push_back(names[i]);
		}
	}
	if (vsFirst.size() > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool NameSearch::findLastNames(vector<string> &vsLast, string sName)
{
	name = "";
	vsLast.clear();
	for (unsigned int h = 0; h < sName.length(); ++h)
	{
		name += toupper(sName[h]);
	}
	for (int i = 0; i < total; ++i)
	{
		int pos = names[i].find(' ');
		int final = names[i].rfind(name,pos);
		if (final >= 0)
		{
			vsLast.push_back(names[i]);
		}
	}
	if (vsLast.size() > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

int NameSearch::getTotal()
{
	return total;
}

void NameSearch::sort()
{
	TemplateSort<string> sort;
	sort.shellSort(names,total);

}
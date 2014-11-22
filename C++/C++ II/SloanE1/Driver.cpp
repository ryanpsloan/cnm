//Ryan Sloan
//CIS2275 - C++ II
//Exercise 1
//SloanE1.cpp

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

//Prototypes
void Header();
string GetString();
string Trim(string input);
string Count(string input);
string Upper(string input);
string Reversed(string input);
void Output(string input, string count, string uppercase, string reversed);

int main()
{
	Header();
	//Function gets a multiword string and trims it
	string input = GetString();
	//gets the number of words and length and returns a string
	string count = Count(input);
	//sets the entire string to uppercase
	string uppercase = Upper(input);
	//reverses the string
	string reversed = Reversed(input);
	//sends the gathered data to output
	Output(input, count, uppercase, reversed);
	return 0;
}

void Header()
{
	cout << "Ryan Sloan" << endl;
	cout << "Fun with C++ Standard Strings" << endl;
	cout << "Utlizing String functions" << endl;
	cout << endl;
}

string GetString()
{
	string input = "";
	cout << "Enter a phrase describing yourself: ";
	getline(cin,input);
							//trims the string
	string trimmedInput = Trim(input);
	return trimmedInput;
}

string Trim(string input)
{
	char delimiter = ' ';
	//Got this off of cplusplus.com - trims final spaces
	string trimmed = input.substr(0, input.find_last_not_of(delimiter) + 1);
	//trims leading spaces
	string final = trimmed.substr(trimmed.find_first_not_of(delimiter));

	return final;
}

string Count(string input)
{
	stringstream ss;
	int length = input.length();
	input += " "; //adding a space after the length measurement so the last word will be counted
	int words = 0;
	char c;
    for (int i = 0; i < input.length(); ++i)
	{
		//measuring each character until reach a space, then increment words.
		c = input.at(i);
		if (isspace(c)) //once a space is recognized, words is incremented
			words++;
	}
	//putting together a string out of the work the function has done
	ss << "The phrase you input has " << length << " characters, and " << words << " words.";
	return ss.str();
}

string Upper(string input)
{
	string upper = "";
	//loop converts the string character by character index by index
	for (int i = 0; i < input.length(); i++)
	{
		char p = toupper(input.at(i));//raises the letter to UPPERCASE
		upper += p; 
	}
	return upper;
}

string Reversed(string input)
{	
	//create a reverse iterator
	string::reverse_iterator rit;
	string reversed;
	//set its position at the end of the string
	for (rit = input.rbegin(); rit != input.rend(); ++rit)
		 reversed += *rit; //add character by character as the iterator moves backwards through the string
	return reversed;
}

void Output(string input, string count, string uppercase, string reversed)
{
	//Outputting the data from the other functions
	cout << "The phrase you entered was: " << input << endl;
	cout << count << endl;
	cout << "Here is the phrase in uppercase: " << uppercase << endl;
	cout << "Here is the phrase reversed: " << reversed << endl;
}
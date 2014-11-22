// CIS1275 - Feridoon Ghanbari
// Ryan Sloan - rsloan2@cnm.edu
// SloanE10/Driver.cpp

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void Header();
void askForLetterAndSeriesLength(char *pletter, int *plength);
bool isValidLetter(char letter);
string buildSeries(char letter, int length);

int main()
{
	Header();
	string answer = "yes";
	do
	{
		char letter = 'A';
		int length = 0;
		askForLetterAndSeriesLength(&letter, &length);
		bool valid = false;
		valid = isValidLetter(letter);
		if (valid)
		{
			string output = buildSeries(letter, length);
			cout << output << endl;
			cout << endl;
		}
		else
		{
			cout << "The Letter you Entered is Invalid." << endl;
			cout << endl;
		}
		cout << "Do Another? yes/no ";
		getline(cin, answer);
		cout << endl;

	} while(answer == "yes");
	cout << "Goodbye" << endl;
	cout << endl;

	return 0;
}

void Header()
{
	cout << "Ryan Sloan" << endl;
	cout << "Exercise 10" << endl;
	cout << "Objective: Chars, ASCII, StringStream, Pointers" << endl;
	cout << endl;
}

void askForLetterAndSeriesLength(char *pletter, int *plength)
{
	cout << "Enter a Letter to begin the Series (a-z or A-Z): ";
	cin >> *pletter;
	cin.ignore();
	cout << endl;
	cout << "Enter the Length of the Series (i.e. 10): ";
	cin >> *plength;
	cin.ignore();
	cout << endl;
}

bool isValidLetter(char letter)
{
	if (letter >= 'a' && letter <= 'z')
	{
		return true;
	}
	else if (letter >= 'A' && letter <= 'Z')
	{
		return true;
	}
	else
	{
		return false;
	}
}

string buildSeries(char letter, int length)
{
	stringstream ss;
	for (int i = 0; i < length; ++i)
	{
		ss << letter << " ";
		if (letter == 'z')
		{
			letter = '`';
		}
		if (letter == 'Z')
		{
			letter = '@';
		}
		letter++;
	}
	return ss.str();
}
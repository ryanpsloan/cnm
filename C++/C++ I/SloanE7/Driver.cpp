// CIS1275 - Feridoon Ghanbari
// Ryan Sloan, rsloan2@cnm.edu
// SloanE7/Driver.cpp

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Header();
string AskForFruitString();
string FruitFinder(string userString);

int main()
{
	string answer;
	string userString = "";
	Header();
	do
	{
		userString = AskForFruitString();
		cout << FruitFinder(userString) << endl;
		cout << "Would you like to play again? yes/no  ";
		getline(cin,answer);
		cout << endl;
	} while (answer == "yes");
	return 0;
}

void Header()
{
	cout << "Ryan Sloan" << endl;
	cout << "Exercise 7 - Fruitfinder" << endl;
	cout << "Working with Functions and Strings" << endl;
	cout << endl;
}

string AskForFruitString()
{
	string userString;
	cout << "Enter a sentence that contains the name of a fruit." << endl;
	getline(cin, userString);
	return userString;
}

string FruitFinder(string userString)
{
	bool bLoop = false;
	vector<string> fruits;
	fruits.push_back("orange");
	fruits.push_back("banana");
	fruits.push_back("apple");
	fruits.push_back("kiwi");
	fruits.push_back("raspberry");
	fruits.push_back("grape");
	fruits.push_back("guava");
	fruits.push_back("cranberry");
	fruits.push_back("lemon");
	fruits.push_back("grapefruit");
	fruits.push_back("blackberry");
	fruits.push_back("blueberry");
	fruits.push_back("apricot");
	fruits.push_back("lime");
	fruits.push_back("melon");
	fruits.push_back("mango");
	fruits.push_back("nectarine");
	fruits.push_back("peach");
	fruits.push_back("pear");
	fruits.push_back("plum");
	fruits.push_back("pineapple");
	fruits.push_back("strawberry");
	fruits.push_back("pomegranate");
	fruits.push_back("papaya");
	fruits.push_back("coconut");
	fruits.push_back("cherry");
	fruits.push_back("jackfruit");
	 
	//How would you write this program to handle two fruit names in a string like 'strawberry kiwi smoothie'?
	
	for (unsigned int i = 0; i < fruits.size() && bLoop == false; ++i)
	{
		
		if(userString.find(fruits.at(i)) != string::npos)
		{
				int startpos = userString.find(fruits.at(i));
				int endpos = fruits.at(i).size();
				userString.insert(startpos, "Broccoli");
				int eraseposA = userString.find("Broccoli") + 8;
				int eraseposB = fruits.at(i).size();
				userString.erase(eraseposA, eraseposB);
				bLoop = true;
			
		}
	}
	
	if (bLoop)
	return userString;
	else
	return "You must not like fruit.";


}



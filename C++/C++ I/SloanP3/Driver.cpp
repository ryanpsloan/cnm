//CIS1275 - Feridoon Ghanbari
// Program 3 - Control Statements
// Ryan Sloan, rsloan2@cnm.edu
// Guess the color
// SloanP3/Driver.cpp

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

int main()
{
	//seeding the random number generator
	srand(static_cast<unsigned>(time(0)));
	
	//header
	cout << "Ryan Sloan" << endl;
	cout << "Program 3 - Guess the Color" << endl;
	cout << "Objective: Using Vectors and Random Numbers" << endl;
	cout << endl;
	
	//declaring vectors
	vector<string> hints;
	vector<string> colors;
	
	//filling the vectors
	hints.push_back("A Clown's Nose: ");
	colors.push_back("red");
	hints.push_back("The Sun: ");
	colors.push_back("orange");
	hints.push_back("A Lemon: ");
	colors.push_back("yellow");
	hints.push_back("A Praying Mantis: ");
	colors.push_back("green");
	hints.push_back("An Eggplant: ");
	colors.push_back("purple");
	hints.push_back("The Ocean: ");
	colors.push_back("blue");
	
	//declare and initialize variables
	string answer = "yes";
	
	
	//Intro
	cout << "Welcome to Guess the Color." << endl;
	cout << "I'll provide you a hint, try to guess the color." << endl;
	cout << "You get three tries per color." << endl;
	cout << "Enter your responses in lowercase." << endl;
	cout << endl;
	
	//Game loop
	do
	{
		//declare variables inside the loop
		string color = "";
		int index = 0;
		int count = 0;
		//generate a random number to determine which index to access
		index = rand() % 6;
		//play loop for three guesses
		while (count < 3)
		{
			//output the hint
			cout << hints.at(index);
			//get inputted answer
			getline(cin, color);
			//add 1 try to the counter
			++count;
			//evaluate the guess against the vector
			if (color == colors.at(index))
			{
				//if true
				cout << "That's correct." << endl;
				break;
			}
			//if false
			else
			{	//based on the count
				if (count <= 2)
				{
					cout << "That was incorrect. Try again." << endl;
				}
				else
				{
					cout << "You are out of tries." << endl;
					cout << "The color was " << colors.at(index) << "." << endl;
				}
			}
		}
		//update the variable to continue or discontinue the game loop
		cout << endl;
		cout << "Would you like to play again? yes/no ";
		getline(cin, answer);
		cout << endl;
	
	
	} while(answer == "yes");
	
	cout << "Thanks for playing Guess the Color!" << endl;
	
	
	
	
	
	return 0;
}
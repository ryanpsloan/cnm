// Ryan Sloan
// rsloan2@cnm.edu
// Dog.h

#ifndef _DOG_H
#define _DOG_H

#include<string>
using namespace std;

void Header();

class Dog
{
	//private variables
private:
	string name;
	double weight;
	int age;
	string gender;
	string breed;

	//public constructors and methods
public:
Dog();
Dog(string name, double weight, int age, string gender, string breed);
void SetData(string name, double weight, int age, string gender, string breed);
string GetFormattedString();

};




#endif;
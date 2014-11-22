// Ryan Sloan
// rsloan2@cnm.edu
// Dog.cpp

#include"Dog.h"
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

void Header()
{
	//output the info as a header
	cout << "Ryan Sloan\n" << "Quiz 1\n" << "Writing a Class\n" << endl;
}

Dog :: Dog()
{
	//setting the class variables to default
	name = "Zelda";
	weight = 75.0;
	age = 3;
	gender = "Female";
	breed = "Labrador Retriever";
}

Dog :: Dog(string name, double weight, int age, string gender, string breed)
{
	//This constructor allows you to define the variables as you construct the object
	this->name = name;
	this->weight = weight;
	this->age = age;
	this->gender = gender;
	this->breed = breed;
}

void Dog::SetData(string name, double weight, int age, string gender, string breed)
{
	//this method gives the option to change the default values to new ones
	this->name = name;
	this->weight = weight;
	this->age = age;
	this->gender = gender;
	this->breed = breed;
}

string Dog::GetFormattedString()
{
	//creating and outputting a formatted string
	stringstream ss;
	ss << "Hi! I'm " << name << ". I'm " << age << " years old. I weigh " << weight << " pounds." << endl;
	ss << "I'm a " << breed << " and am also " << gender << ".";
	return ss.str();

}
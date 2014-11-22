//Ryan Sloan, rsloan2@cnm.edu
// Quiz 5
//windchill.h

// function prototypes

#include <iostream>
#include <string>
using namespace std;

#ifndef _WINDCHILL_H
#define _WINDCHILL_H

void header();
double askfortemperature();
double askforwindspeed();
//error: parameter values must be prefixed with a datatype in the prototype
int validatetempws(double temp, double windsp);
double calcwindchill(double temp, double windsp);
int determinefrostbitetimes(double temp, double windsp);

#endif
// CIS1275 - Feridoon Ghanbari
// Ryan Sloan - rsloan2@cnm.edu
// SloanP5/Whiskey.h

#include<iostream>
#include<string>

using namespace std;

#ifndef _WHISKEY_H
#define _WHISKEY_H

void Header();
void AskName(string &name);
void AskForBarrels(int &diameter, int &height, int &numOfBarrels);
double CalcNetWhiskeyVol(int &diameter, int &height, int &numOfBarrels);
double DetermineVol(double &volumeLiters, double &volumeFinal, int &numOfBottles, int &numOfCases, double &remainingBottles);
 
#endif
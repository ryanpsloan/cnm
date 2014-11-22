// CIS1275 - Feridoon Ghanbari
// Ryan Sloan - rsloan2@cnm.edu
// SloanP6/Parking.h

#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<ctime>
#include<sstream>

using namespace std;

void Header();
void AskTimeIn(int &hour, char &colon, int &minute);
void ObtainTimeOut(int &outHour, int &outMin, int &month, int &day, int &year);
bool ValidateTime(int inHour, int inMinute, int outHour, int outMin);
double CalculateFee(int &inHour, int &inMinute, int &outHour, int &outMin, int &totalHr, int &totalMin);
void WriteReceipt(int &inHour, int &inMinute, int &outHour, int &outMin, int &totalHr, int &totalMin, int month, int day, int year, double fee);
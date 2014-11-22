// CIS2275
// Ryan Sloan
// rsloan2@cnm.edu
// SloanP1.cpp

#include <string>
using namespace std;

//Prints Header
void PrintHeader();
//Asks for Name
string AskForName();
//Asks for Loan Info
void AskForLoanInfo(double &principal,double &interest,int &years,string name);
//Calculates Mortgage Data
void MortCalc(double principal, double interest, int years, double* ppymt, double* ptloan, double* ptint);
//Calculates Mortgage Data and returns a string
string MortCalc(double principal, double interest, int years);
//Writes data to File
bool WriteFile(string name, string result, string &filename);
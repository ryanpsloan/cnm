#include "stdafx.h"
#include "Enigma.h"
#include <string>
using namespace std;

#ifndef _PRIMESHIFT_H
#define _PRIMESHIFT_H

class PrimeShift : public Enigma
{
private:
	int primeNumber;
    
	int calculateIndex (int primes[], int character);
	void encode();
	void decode();
public:
	void setMessage(string m, int k);
	void setCodedMessage(string cm, int k);
	PrimeShift();
};

#endif
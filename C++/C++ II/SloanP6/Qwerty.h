#include "stdafx.h"
#include "Enigma.h"
#include <string>
using namespace std;

#ifndef _QWERTY_H
#define _QWERTY_H

class Qwerty : public Enigma
{
private:
	void encode();
	void decode();
public:
	Qwerty();
	void setMessage(string m, int k);
	void setCodedMessage(string cm, int k);


};

#endif
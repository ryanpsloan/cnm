#include "stdafx.h"
#include "Enigma.h"
#include <string>
using namespace std;

#ifndef _SHIFTY_H
#define _SHIFTY_H

class Shifty : public Enigma
{
private:
	void encode();
	void decode();
public:
	Shifty();
	void setMessage(string m, int k);
	void setCodedMessage(string cm, int k);

};

#endif

#include "stdafx.h"
#include <string>
using namespace std;

#ifndef _ENIGMA_H
#define _ENIGMA_H

class Enigma
{
protected:
	string message;
	int key;
	string codedMessage;
	void Encode(string message, int key);
	void Decode(string codedMessage, int key);
	
public:
	virtual void setMessage(string message, int key);
	virtual void setCodedMessage(string codedMessage, int key);
	string getCodedMessage(){return codedMessage;}
	string getDecodedMessage(){return message;}
	int getKey(){return key;}
	virtual void setKey(int k);

};
#endif
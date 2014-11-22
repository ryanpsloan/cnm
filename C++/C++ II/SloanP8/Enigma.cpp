#include "stdafx.h"
#include "Enigma.h"
#include <string>
using namespace std;

void Enigma::Encode(string message, int key)
{
	string encodedMsg = "";
	for(unsigned int i = 0; i < message.size(); ++i)
	{
		char msg = message[i];
		int addKey = msg + key;
		if(addKey > 126)
		{
			addKey -= 126;
			addKey += 32;
		}
		char conv = static_cast<char>(addKey);
		encodedMsg += conv;
	}
	codedMessage = encodedMsg;

}
void Enigma::Decode(string cMsg, int k)
{
	string decodedMessage = "";
	codedMessage = cMsg;	
	key = k;
	for (unsigned int j = 0; j < codedMessage.size(); ++j)
	{
		char l = codedMessage[j];
		int subKey = l - key;
		if(subKey < 32)
		{
			subKey += 126;
			subKey -= 32;
		}
		char conv = (char)subKey;
		decodedMessage += conv;
	}
	message = decodedMessage;
}

void Enigma::setMessage(string msg, int k)
{
	message = msg;
	key = k;
	Encode(message,k);
	
}

void Enigma::setCodedMessage(string cMsg, int k)
{
	codedMessage = cMsg;
	key = k;
	Decode(codedMessage,k);
	
}

void Enigma::setKey(int k)
{
	key = k;
}
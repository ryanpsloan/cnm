#include "stdafx.h"
#include "Qwerty.h"
#include <string>
using namespace std;

Qwerty::Qwerty()
{
	
}

void Qwerty::setMessage(string m, int k)
{
	Enigma::setMessage(m,k);
	encode();
}

void Qwerty::setCodedMessage(string cm, int k)
{
	codedMessage = cm;
	key = k;
	decode();
	Enigma::Decode(message,key);
}

void Qwerty::encode()
{
	string newString = "";
	string tempString = codedMessage;
	for (int i = 0; i < tempString.length(); ++i)
	{
		char a = tempString[i];
		if (a == 'a')
			a = 'z';
		else if (a == 'A')
			a = 'Z';
		else if (a == 'b')
			a = 't';
		else if (a == 'B')
			a = 'T';
		else if (a == 'c')
			a = 'e';
		else if (a == 'C')
			a = 'E';
		else if (a == 'd')
			a = 'c';
		else if (a == 'D')
			a = 'C';
		else if (a == 'e')
			a = 'd';
		else if (a == 'E')
			a = 'D';
		else if (a == 'f')
			a = 'v';
		else if (a == 'F')
			a = 'V';
		else if (a == 'g')
			a = 'b';
		else if (a == 'G')
			a = 'B';
		else if (a == 'h')
			a = 'n';
		else if (a == 'H')
			a = 'N';
		else if (a == 'i')
			a = 'k';
		else if (a == 'I')
			a = 'K';
		else if (a == 'j')
			a = 'm';
		else if (a == 'J')
			a = 'M';
		else if (a == 'k')
			a = 'i';
		else if (a == 'K')
			a = 'I';
		else if (a == 'l')
			a = 'o';
		else if (a == 'L')
			a = 'O';
		else if (a == 'm')
			a = 'u';
		else if (a == 'M')
			a = 'U';
		else if (a == 'n')
			a = 'y';
		else if (a == 'N')
			a = 'Y';
		else if (a == 'o')
			a = 'l';
		else if (a == 'O')
			a = 'L';
		else if (a == 'q')
			a = 'a';
		else if (a == 'Q')
			a = 'A';
		else if (a == 'r')
			a = 'f';
		else if (a == 'R')
			a = 'F';
		else if (a == 's')
			a = 'x';
		else if (a == 'S')
			a = 'X';
		else if (a == 't')
			a = 'g';
		else if (a == 'T')
			a = 'G';
		else if (a == 'u')
			a = 'j';
		else if (a == 'U')
			a = 'J';
		else if (a == 'v')
			a = 'r';
		else if (a == 'V')
			a = 'R';
		else if (a == 'w')
			a = 's';
		else if (a == 'W')
			a = 'S';
		else if (a == 'x')
			a = 'w';
		else if (a == 'X')
			a = 'W';
		else if (a == 'y')
			a = 'h';
		else if (a == 'Y')
			a = 'H';
		else if (a == 'z')
			a = 'q';
		else if (a == 'Z')
			a = 'Q';
		
		newString += a;
	}
	codedMessage = newString;
}

void Qwerty::decode()
{
	string newString = "";
	string tempString = codedMessage;
	for (int i = 0; i < tempString.length(); ++i)
	{
		char a = tempString[i];
		if (a == 'a')
			a = 'q';
		else if (a == 'A')
			a = 'Q';
		else if (a == 'b')
			a = 'g';
		else if (a == 'B')
			a = 'G';
		else if (a == 'c')
			a = 'd';
		else if (a == 'C')
			a = 'D';
		else if (a == 'd')
			a = 'e';
		else if (a == 'D')
			a = 'E';
		else if (a == 'e')
			a = 'c';
		else if (a == 'E')
			a = 'C';
		else if (a == 'f')
			a = 'r';
		else if (a == 'F')
			a = 'R';
		else if (a == 'g')
			a = 't';
		else if (a == 'G')
			a = 'T';
		else if (a == 'h')
			a = 'y';
		else if (a == 'H')
			a = 'Y';
		else if (a == 'i')
			a = 'k';
		else if (a == 'I')
			a = 'K';
		else if (a == 'j')
			a = 'u';
		else if (a == 'J')
			a = 'U';
		else if (a == 'k')
			a = 'i';
		else if (a == 'K')
			a = 'I';
		else if (a == 'l')
			a = 'o';
		else if (a == 'L')
			a = 'O';
		else if (a == 'm')
			a = 'j';
		else if (a == 'M')
			a = 'J';
		else if (a == 'n')
			a = 'h';
		else if (a == 'N')
			a = 'H';
		else if (a == 'o')
			a = 'l';
		else if (a == 'O')
			a = 'L';
		else if (a == 'q')
			a = 'z';
		else if (a == 'Q')
			a = 'Z';
		else if (a == 'r')
			a = 'v';
		else if (a == 'R')
			a = 'V';
		else if (a == 's')
			a = 'w';
		else if (a == 'S')
			a = 'W';
		else if (a == 't')
			a = 'b';
		else if (a == 'T')
			a = 'B';
		else if (a == 'u')
			a = 'm';
		else if (a == 'U')
			a = 'M';
		else if (a == 'v')
			a = 'f';
		else if (a == 'V')
			a = 'F';
		else if (a == 'w')
			a = 'x';
		else if (a == 'W')
			a = 'X';
		else if (a == 'x')
			a = 's';
		else if (a == 'X')
			a = 'S';
		else if (a == 'y')
			a = 'n';
		else if (a == 'Y')
			a = 'N';
		else if (a == 'z')
			a = 'a';
		else if (a == 'Z')
			a = 'A';
		
		newString += a;
	}
	message = newString;
}

#include "stdafx.h"
#include "Shifty.h"
#include "Enigma.h"
#include <sstream>
using namespace std;

Shifty::Shifty()
{
	

}

void Shifty::setMessage(string m, int k)
{
	Enigma::setMessage(m,k);
	encode();
}

void Shifty::setCodedMessage(string cm, int k)
{
	codedMessage = cm;
	key = k;
	decode();
	
}

void Shifty::encode()
    {
        string tempString = codedMessage;
        string finalString = "";
        char character = 'a';
        for (unsigned int i = 0; i < tempString.length(); ++i)
        {
            int r[3];
            int ascii = tempString[i];
            int remainder = 1000 - ascii;
            r[0] = remainder / 100;
            int temp = remainder - (r[0] * 100);
            r[1] = temp/10;
            r[2] = temp - r[1] * 10;
            
            for (int k = 0; k < 3; ++k)
            {
                if (r[k] == 1)
                {
                    character = '!';
                }
                else if (r[k] == 2)
                {
                    character = '@';
                }
                else if (r[k] == 3)
                {
                    character = '#';
                }
                else if (r[k] == 4)
                {
                    character = '$';
                }
                else if (r[k] == 5)
                {
                    character = '%';
                }
                else if (r[k] == 6)
                {
                    character = '^';
                }
                else if (r[k] == 7)
                {
                    character = '&';
                }
                else if (r[k] == 8)
                {
                    character = '*';
                }
                else if (r[k] == 9)
                {
                    character = '(';
                }
                else if (r[k] == 0)
                {
                    character = ')';
                }
                finalString += character;
            }
            
        }
        codedMessage = finalString;
    }

void Shifty::decode()
    {
        string tempString = codedMessage;
       
        stringstream ss;
        char character = 'a';
        for (unsigned int i = 0; i < tempString.length(); ++i)
        {
                character = tempString[i];
                if (character == '!')
                {
                    ss << 1;
                }
                else if (character == '@')
                {
                    ss << 2;
                
                }
                else if (character == '#')
                {
                    ss << 3;
                }
                else if (character == '$')
                {
                    ss << 4;
                }
                else if (character == '%') 
                {
                    ss << 5;
                }
                else if (character == '^')
                {
                    ss << 6;
                }
                else if (character == '&')
                {
                    ss << 7;
				}
                else if (character == '*')
                {
                    ss << 8;
                }
                else if (character == '(')
                {
                    ss << 9;
                }
                else if (character == ')')
                {
                    ss << 0;
                }
                
            }
            string createdString = ss.str();
           
            stringstream ss2;
            int total = 0;
           
            string aString;    
            int firstPosition = 0, secondPosition = 0, thirdPosition = 0; 
            for (unsigned int o = 0; o < createdString.length(); ++o)
            {      aString = createdString[o];
                   int character2 = stoi(aString);
                    
                    if (o % 3 == 0)
                    {
                        firstPosition = character2 * 100;
                        
                    }
                    else if (o % 3 == 1)
                    {
                        secondPosition = character2 * 10;
                        
                    }
                    else if (o %3 == 2){
                        
                        thirdPosition = character2;
                        
                    }
                    
                    if (o % 3 == 2)                
                    {
                        total = firstPosition + secondPosition + thirdPosition;
                        total = 1000 - total;
                        if (total < 70) {
                            total += 95 ;
                        }
                        ss2 << total;
                        
                    }
                    
                       
            
            
            }
     codedMessage = ss2.str(); 
    
    }    
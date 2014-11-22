#include "stdafx.h"
#include "PrimeShift.h"
#include "Enigma.h"
#include <string>
;using namespace std;

PrimeShift::PrimeShift()
{
	
}

void PrimeShift::setMessage(string m, int k)
{
	Enigma::setMessage(m,k);
	encode();
}

void PrimeShift::setCodedMessage(string cm, int k)
{
	codedMessage = cm;
	key = k;
	decode();
	Enigma::Decode(message,key);
}

void PrimeShift::encode()
    {
		int primes[33] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137};
        string tempString = codedMessage;
       
        string newString = "";
        for (unsigned int i = 0; i < tempString.length(); i++)
        {   
           
            int character = tempString[i];
            int returnPrime = calculateIndex(primes, character);
            if (returnPrime != -1)
            {
                int primeIndex = calculateIndex(primes, key);
                if (primeIndex != -1){
                    
                    
                    if (primes[primeIndex + 1] >= 127 )
                    {
                        primeIndex -= 19;
                        
                    }
                    primeNumber = primes[primeIndex + 1];
                    newString += primeNumber;
                }
                else if (key % 2 == 0){
                    if (primes[primeIndex + 2] >= 127 )
                    {
                        primeIndex -= 19;
                        
                    }
                    primeNumber = primes[primeIndex + 2];
                    newString += primeNumber;
                }
                else if (primeIndex != -1)
                {
                    primeNumber = primes[primeIndex + 3];
                    newString += primeNumber;
                        
                }
                 
            }
            else
            {
                newString += tempString[i];
            }
            
        }
        codedMessage = newString;
    
    }

int PrimeShift::calculateIndex (int primes[], int character)
    {       
            int index = 1;
            for (unsigned int k = 0; k < 33; ++k)
            {
                if (character == primes[k])
                {
                    index = k;
                    break;
                }
                else
                {
                    index = -1;
                }
            }
    
            return index;
    }

void PrimeShift::decode()
    {
		int primes[33] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137};
        string newString = "";
        string tempString = codedMessage;
        for (unsigned int i = 0; i < tempString.length(); i++)
        {   
            int character = tempString[i];
            int returnPrime = calculateIndex(primes, character);
            if (returnPrime != -1)
            {
                int primeIndex = calculateIndex(primes, key);
                if (primeIndex != -1)
                {
                    if (primes[primeIndex - 1] <= 31 )
                    {
                        primeIndex += 19;
                        
                    }
                    primeNumber = primes[primeIndex - 1];
                    newString += primeNumber;
                }
                else if (primeIndex != -1 && key % 2 == 0)
                {
                    if (primes[primeIndex - 2] <= 31 )
                    {
                        primeIndex += 19;
                        
                    }
                    primeNumber = primes[primeIndex - 2];
                    newString += primeNumber;
                }
                else if (primeIndex != -1)
                {
                    if (primes[primeIndex] <= 31 )
                    {
                        primeIndex += 19;
                        
                    }
                    primeNumber = primes[primeIndex - 3];
                    newString += primeNumber;
                        
                }
                 
            }
            else
            {
                newString += tempString[i];
            }
            
        }
        message = newString;
        
    }  
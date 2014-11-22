/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package sloan.p7.enigma;

/**
 *
 * @author rsloan2
 */
public class PrimeShift extends Enigma {
    
    private int primeNumber;
    int [] primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137};
    

    @Override
    public void setMessage(String s, int k)
    {
        super.setMessage(s, k);
        encode();
    }
    
    @Override
    public void setMessage(String s)
    {
        super.setMessage(s);
        encode();
    }
 
    private void encode()
    {
        String tempString = codedMessage;
       
        String newString = "";
        for (int i = 0; i < tempString.length(); i++)
        {   
           
            int character = tempString.charAt(i);
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
                else if (primeIndex != -1 && key % 2 == 0){
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
                newString += tempString.charAt(i);
            }
            
        }
        codedMessage = newString;
    
    }
    
    private int calculateIndex (int[] primes, int character)
    {       
            int index = 1;
            for (int k = 0; k < primes.length; ++k)
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
    
    @Override
    public void setCodedMessage(String codeMsg, int k)
    {
        codedMessage = codeMsg;
        key = k;
        decode();
        super.setCodedMessage(message, k);
        
    }
    
    private void decode()
    {
        String newString = "";
        String tempString = codedMessage;
        for (int i = 0; i < tempString.length(); i++)
        {   
            int character = tempString.charAt(i);
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
                newString += tempString.charAt(i);
            }
            
        }
        message = newString;
        
    }   
    
     
}

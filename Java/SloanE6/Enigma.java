/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package sloan.e7.enigma;

import java.util.Random;

/**
 *
 * @author O
 */
public class Enigma {
    
    String message;
    String codedMessage;
    int key;
    
    public Enigma(){
        message = "Default Message";
        codedMessage = "DEFAULT";
        key = 1;
    }
    
    public void setMessage(String s, int k)
    { 
        message = s;
        key = k;
        if (key > 50 || key < 0)
        {
            key = 1;
        }
        encode();
       
    }
    
    public void setMessage(String s)
    {
        
        message = s;
        Random random = new Random();
        random.setSeed(System.currentTimeMillis());
        key = random.nextInt(50) + 1;
        encode();
        
    }
    
    public void setCodedMessage(String encodedMsg, int k)
    {
        codedMessage = encodedMsg;
        key = k;
        decode();
        
    }
    
    public String getCodedMessage()
    {
        return codedMessage;
        
    }
    
    public String getDecodedMessage()
    {
        return message;
    }
    
    public int getKey()
    {
        return key;
    }
    
    private void encode()
    {
        String encodedMessage = "";
    
        for(int i = 0; i < message.length(); ++i)
        {
            char l = message.charAt(i);
            int addKey = l + key;
            if (addKey > 126)
            {
                addKey -= 127;
                addKey += 32;
                
            }
            char m = (char)addKey;
            encodedMessage += m;
        }
        codedMessage = encodedMessage;
    }
    
    private void decode()
    {
        String decodedMessage = "";
        for(int j = 0; j < codedMessage.length(); ++j)
        {
            char n = codedMessage.charAt(j);
            int subKey = n - key;
            if(subKey < 32)
            {
                subKey += 127;
                subKey -= 32;
            }
            char o = (char)subKey;
            decodedMessage += o;
        }
        message = decodedMessage;
    }
}
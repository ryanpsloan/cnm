/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package sloan.p7.enigma;

/**
 *
 * @author rsloan2
 */
public class Reverse extends Enigma {
        
    
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
        String reversedString;
        StringBuilder sBuilder = new StringBuilder(codedMessage);
        sBuilder.reverse();
        reversedString = sBuilder.toString();
        String caseChange = "";
        for (int i = 0; i < reversedString.length(); ++i)
        {
            char ascii = reversedString.charAt(i);
            if (ascii > 64 && ascii < 91)
            {
                ascii += 32;
                
            }
            else if (ascii > 96 && ascii < 123 )
            {
                ascii -= 32;
                
            }
            caseChange += ascii;
        }
        codedMessage = caseChange;
    }
    
    public void decode()
    {
        String string;
        StringBuilder sBuilder = new StringBuilder(codedMessage);
        sBuilder.reverse();
        string = sBuilder.toString();
        String caseChange = "";
        for (int i = 0; i < string.length(); ++i)
        {
            char ascii = string.charAt(i);
            if (ascii > 64 && ascii < 91)
            {
                ascii += 32;
            }
            else if (ascii > 96 && ascii < 123)
            {
                ascii -= 32;
            }
            caseChange += ascii;
        }
        message = caseChange;
    }
    
    @Override
    public void setCodedMessage(String codeMsg, int k)
    {
        codedMessage = codeMsg;
        key = k;
        decode();
        super.setCodedMessage(message, k);
    }
}

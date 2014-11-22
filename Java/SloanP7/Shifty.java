/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package sloan.p7.enigma;

/**
 *
 * @author rsloan2
 */
public class Shifty extends Enigma {
    
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
    
    @Override
    public void setCodedMessage(String codeMsg,int k)
    {
        codedMessage = codeMsg;
        key = k;
        decode();
        
    }
    
    
    private void encode()
    {
        String tempString = codedMessage;
        String finalString = "";
        char character = 'a';
        for (int i = 0; i < tempString.length(); ++i)
        {
            int r[] = new int[3];
            int ascii = tempString.charAt(i);
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
    
    private void decode()
    {
        String tempString = codedMessage;
        //String intString = "";
        StringBuilder sBuilder = new StringBuilder();
        char character = 'a';
        for (int i = 0; i < tempString.length(); ++i)
        {
                character = tempString.charAt(i);
                if (character == '!')
                {
                    sBuilder.append(1);
                }
                else if (character == '@')
                {
                    sBuilder.append(2);
                
                }
                else if (character == '#')
                {
                    sBuilder.append(3);
                }
                else if (character == '$')
                {
                    sBuilder.append(4);
                }
                else if (character == '%') 
                {
                    sBuilder.append(5);
                }
                else if (character == '^')
                {
                    sBuilder.append(6);
                }
                else if (character == '&')
                {
                    sBuilder.append(7);
                }
                else if (character == '*')
                {
                    sBuilder.append(8);
                }
                else if (character == '(')
                {
                    sBuilder.append(9);
                }
                else if (character == ')')
                {
                    sBuilder.append(0);
                }
                System.out.println(sBuilder.toString());
            }
            String createdString = sBuilder.toString();
           // int r[] = new int[createdString.length()];
            StringBuilder sBuilder2 = new StringBuilder();
            int total = 0;
           // sBuilder.
            String aString;    
            int firstPosition = 0, secondPosition = 0, thirdPosition = 0; 
            for (int o = 0; o < createdString.length(); ++o)
            {      aString = createdString.charAt(o) + "";
                   int character2 = Integer.parseInt(aString);
                    
                   System.out.println(character2);
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
                        sBuilder2.append(total);
                        System.out.println(sBuilder2.toString());
                    }
                    
                       
            
            
            }
     codedMessage = sBuilder2.toString(); 
    
    }    
           
        
}


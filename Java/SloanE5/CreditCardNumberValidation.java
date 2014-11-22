import javax.swing.JOptionPane;
import java.util.*;
import java.lang.*;

public class CreditCardNumberValidation
{
	public static void main(String[] args)
	{
		String cardNumber = JOptionPane.showInputDialog(null,"Enter a long integer 13 to 16 digits long","Credit Card Validation");
		if(isValid(cardNumber))
		{
			JOptionPane.showMessageDialog(null, cardNumber + "\n" + "The entered number is valid");
		}
		else
		{
			JOptionPane.showMessageDialog(null, cardNumber + "\n" + "The entered number is not valid");
		}
		
	
	}
	
	public static boolean isValid(String cardNumber)
	{
		long longNumber = Long.parseLong(cardNumber);
		return 	(getSize(longNumber)>=13 && getSize(longNumber) <= 16) && 
				(prefixMatched(longNumber,4) || prefixMatched(longNumber,5) || prefixMatched(longNumber,6) || prefixMatched(longNumber, 37)) &&
				((sumOfDoubleEvenPlace(longNumber) + sumOfOddPlace(longNumber)) % 10 == 0);
	}
	
	public static int sumOfDoubleEvenPlace(long longNumber)
	{
		int result = 0;
		longNumber = longNumber / 10;
		while(longNumber != 0){
			result += getDigit((int)(longNumber % 10) * 2);
			longNumber = longNumber / 100;
		}
		return result;
	}
	
	public static int getDigit(int convertedNumber)
	{
		return convertedNumber % 10 + (convertedNumber/10);
	}
	
	public static int sumOfOddPlace(long longNumber)
	{
		int result = 0;
		while (longNumber != 0)
		{
			result += (int)(longNumber % 10);
			longNumber = longNumber/100;
		}
		return result;
	}
	
	public static boolean prefixMatched(long longNumber, int d)
	{
		return getPrefix(longNumber, getSize(d)) == d;
	}
	
	public static int getSize(long longNumber)
	{
		int numberOfDigits = 0;
		while (longNumber != 0)
		{
			numberOfDigits++;
			longNumber = longNumber / 10;
		}
		return numberOfDigits;
	}
	
	public static long getPrefix(long longNumber, int k)
	{
		long result = longNumber;
		for(int i = 0; i < getSize(longNumber) - k; ++i)
		{
			result /= 10;
		}
		
		return result;
	}
	
}
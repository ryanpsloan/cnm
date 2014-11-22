// Ryan Sloan
// CIS2235 - Java
// Exercise 1
// PrimeNumber.java

import javax.swing.JOptionPane;

public class PrimeNumber
{
	public static void main(String[] args)
	{
		JOptionPane.showMessageDialog(null,"Ryan Sloan \nCIS2235 \nExercise 1 \nPrimeNumber.java");
		final int NUMBER_OF_PRIMES = 50; //Number of Primes to display
		final int NUMBER_OF_PRIMES_PER_LINE = 10; // Display 10 per line
		int count = 0;// Count the number of prime numbers
		int number = 2; // A number to be tested for primeness
		String numberString = " ";
		
		// Repeatedly find prime numbers
		while (count < NUMBER_OF_PRIMES)
		{
			//Assume the number is prime
			boolean isPrime = true; // Is the current number prime?
			
			//Test whether number is prime
			for (int divisor = 2; divisor <= number/2; divisor++)
			{
				if (number % divisor == 0) //If true number is not prime
				{
					isPrime = false; // Set isPrime to false
					break; // Exit the for loop
				}
			}
		
		
			//display the prime number and increase the count
			if(isPrime)
			{
				
				count++; //Increase the count
				if (count % NUMBER_OF_PRIMES_PER_LINE == 0)
				{			
					// Display the number and advance to the new line
					numberString += number + "\n";
				}
				else
				{
					numberString += number + " ";
				}
			}
			// Check if the next number is prime
			number++;
		}
		JOptionPane.showMessageDialog(null, "The first 50 prime numbers are \n" + numberString);
	}
}
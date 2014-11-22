// Ryan Sloan
// CIS2235 - Java
// Exercise 1
// ComputeChange.java

import javax.swing.JOptionPane;
import java.util.Scanner;

public class ComputeChange
{
	public static void main(String[] args)
	{
		JOptionPane.showMessageDialog(null,"Ryan Sloan \nCIS2235 \nExercise 1 \nComputeChange.java");
		
		// Create a Scanner
		Scanner input = new Scanner(System.in);
		
		int option = JOptionPane.YES_OPTION;
		while (option == JOptionPane.YES_OPTION)
		{
		
			// Retrieve the amount
			String amountString = JOptionPane.showInputDialog("Enter an amount, for example, 11.56 ");
	
			// Convert to double
			double amount = Double.parseDouble(amountString);
		
			int remainingAmount = (int)(amount * 100);
		
			// Find the number of dollars
			int numberOfOneDollars = remainingAmount / 100;
			remainingAmount = remainingAmount % 100;
		
			// Find the number of remaining quarters
			int numberOfQuarters = remainingAmount / 25;
			remainingAmount = remainingAmount % 25;
		
			// Find the number of remaining dimes
			int numberOfDimes = remainingAmount / 10;
			remainingAmount = remainingAmount % 10;
		
			// Find the number of remaining nickles
			int numberOfNickles = remainingAmount / 5;
			remainingAmount = remainingAmount % 5;
		
			// Find the number of remaining pennies
			int numberOfPennies = remainingAmount;
		
			String total = "Your amount " + amount + " consists of \n" +
					   "\t" + numberOfOneDollars + " dollars\n" +
					   "\t" + numberOfQuarters +   " quarters\n" +
					   "\t" + numberOfDimes	+ " dimes\n" +
					   "\t" + numberOfNickles + " nickles\n" +
					   "\t" + numberOfPennies + " pennies\n";
		
			//Display results
			JOptionPane.showMessageDialog(null, total);
			option = JOptionPane.showConfirmDialog(null, "Try Another?");
		}
		JOptionPane.showMessageDialog(null, "Goodbye");
	}
}
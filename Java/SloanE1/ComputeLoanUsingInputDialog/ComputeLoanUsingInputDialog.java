//Ryan Sloan
//CIS 2235 - Java I
//Exercise 1
//ComputeLoanUsingInputDialogue.java

import javax.swing.JOptionPane;

public class ComputeLoanUsingInputDialog
{
	public static void main(String[] args)
	{
		JOptionPane.showMessageDialog(null,"\nRyan Sloan \nCIS2235 \nExercise 1 \nComputeLoanUsingInputDialog.java");
	
		// Enter annual interst rate
		String annualInterestRateString = JOptionPane.showInputDialog("Enter annual interest rate, for example 8.25:");
		
		// Convert string to double
		double annualInterestRate = Double.parseDouble(annualInterestRateString);
		
		// Obtain monthly interest rate
		double monthlyInterestRate = annualInterestRate / 1200;
		
		// Enter number of years
		String numberOfYearsString = JOptionPane.showInputDialog("Enter number of years as an integer, for example 5:");
		
		// Convert string to int
		int numberOfYears = Integer.parseInt(numberOfYearsString);
		
		// Enter loan amount
		String loanString = JOptionPane.showInputDialog("Enter loan amount, for example, 120000.95:");
		
		// Convert string to double
		double loanAmount = Double.parseDouble(loanString);
	
		// Calculate payment
		double monthlyPayment = loanAmount * monthlyInterestRate / (1 - 1 / Math.pow(1 + monthlyInterestRate, numberOfYears * 12));
		double totalPayment = (monthlyPayment * numberOfYears * 12);
		
		// Format to keep two digits after the decimal point
		monthlyPayment = (int)(monthlyPayment *100) / 100.0;
		totalPayment = (int)(totalPayment *100) / 100.0;
		
		// Display results
		String output = "The montly payment is $" + monthlyPayment + "\nThe total payment is $" + totalPayment;
		JOptionPane.showMessageDialog(null, output);
	
	
	
	
	}
}
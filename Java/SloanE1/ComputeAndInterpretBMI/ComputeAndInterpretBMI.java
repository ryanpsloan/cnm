// Ryan Sloan
// CIS2235 - Java
// Exercise 1
// ComputeAndInterpretBMI.java

import javax.swing.JOptionPane;
import java.util.Scanner;

public class ComputeAndInterpretBMI
{
	public static void main(String[] args)
	{
		JOptionPane.showMessageDialog(null, "Ryan Sloan \nCIS2235 \nExercise 1 \nComputeAndInterpretBMI.java");
		
		// Prompt the user to enter weight in pounds
		String weightString = JOptionPane.showInputDialog("Enter weight in pounds: ");
		double weight = Double.parseDouble(weightString);
		
		// Prompt the user to enter height in inches
		String heightString = JOptionPane.showInputDialog("Enter height in inches: ");
		double height = Double.parseDouble(heightString);
		
		final double KILOGRAMS_PER_POUND = 0.45359237; //CONSTANT
		final double METERS_PER_INCH = 0.0254; //CONSTANT
		
		// Compute BMI
		double weightInKilograms = weight * KILOGRAMS_PER_POUND;
		double heightInMeters = height * METERS_PER_INCH;
		double bmi = weightInKilograms / (heightInMeters * heightInMeters);
		
		String string = "BMI is " + bmi;
		
		//Display result
		JOptionPane.showMessageDialog(null, string);
		if (bmi < 18.5)
		JOptionPane.showMessageDialog(null, "Underweight");
		else if (bmi < 25)
		JOptionPane.showMessageDialog(null, "Normal");
		else if (bmi < 30)
		JOptionPane.showMessageDialog(null, "Overweight");
		else
		JOptionPane.showMessageDialog(null, "Obese");
		
	}
}
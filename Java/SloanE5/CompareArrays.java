import javax.swing.JOptionPane;
import java.util.*;
import java.lang.String;

public class CompareArrays
{
	public static void main(String[] args)
	{
		JOptionPane.showMessageDialog(null,"Ryan Sloan \nCIS 2235 \nComparing Arrays E5");
		String firstList = JOptionPane.showInputDialog(null, "Enter the number of elements followed by a list of Integers separated by spaces", "List One");
		StringTokenizer st1 = new StringTokenizer(firstList);
		String stringElements1 = st1.nextToken();
		int numOfElements1 = Integer.parseInt(stringElements1);
		int[] list1 = new int[numOfElements1];
		for (int i = 0; i < numOfElements1; ++i)
		{
			String dataString = st1.nextToken();
			int enteredInteger = Integer.parseInt(dataString);
			list1[i] = enteredInteger;
		}
		
		String secondList = JOptionPane.showInputDialog(null, "Enter the number of elements followed by a list of Integers separated by spaces", "List Two");
		StringTokenizer st2 = new StringTokenizer(secondList);
		String stringElements2 = st2.nextToken();
		int numOfElements2 = Integer.parseInt(stringElements2);
		int[] list2 = new int[numOfElements2];
		for (int j = 0; j < numOfElements2; ++j)
		{
			String dataString2 = st2.nextToken();
			int enteredInteger2 = Integer.parseInt(dataString2);
			list2[j] = enteredInteger2;
		}
		JOptionPane.showMessageDialog(null, "The two lists have been inputted into arrays and I will now compare the arrays to see if they are equal.");
		boolean equal = equals(list1, list2);
		if (equal) {
			JOptionPane.showMessageDialog(null, firstList + "\n" + secondList);
			JOptionPane.showMessageDialog(null,"The arrays are equal");
		}
		else {
			JOptionPane.showMessageDialog(null, firstList + "\n" + secondList);
			JOptionPane.showMessageDialog(null,"The arrays are not equal");
		}
		
	}
	
	public static boolean equals(int[] list1, int[] list2)
	{
		if(java.util.Arrays.equals(list1, list2))
			return true;
		else
			return false;
	}
}
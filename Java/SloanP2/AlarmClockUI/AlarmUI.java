// Ryan Sloan
// rsloan2@cnm.edu
// AlarmUI.java

import javax.swing.JOptionPane;
import java.lang.String;
import java.util.*;

public class AlarmUI
{
	private AlarmCalc calc;
	
	
	public AlarmUI()
	{
		calc = new AlarmCalc();
	}
	
	public void run()
	{
		//Header
		JOptionPane.showMessageDialog(null, "Ryan Sloan \nProgram 2 \nAlarmClock User Interface \n");
		int option = JOptionPane.YES_OPTION;
		while (option == JOptionPane.YES_OPTION)
		{
			//AskforInput
			String input = JOptionPane.showInputDialog(null, "Enter a time and date after now but before 12/31/14 11:59 \n" +
													"Enter the Year, Month, Day, Hour, Minute, AM/PM (use commas and numbers)");
			JOptionPane.showMessageDialog(null, "The current time is: " + calc.getCurrentDate());												
			calc.setInputData(input);
			JOptionPane.showMessageDialog(null, "You entered: " + calc.getAlarmDate());
			String results = calc.getResults();
			JOptionPane.showMessageDialog(null, results);
			option = JOptionPane.showConfirmDialog(null, "Calculate Another Alarm Time?");
		}
		JOptionPane.showMessageDialog(null, "Goodbye and Farewell");
	}
}

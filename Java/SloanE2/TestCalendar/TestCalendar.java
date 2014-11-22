// Ryan Sloan
// rsloan2@cnm.edu
// CIS 2235 - Java I
// TestCalendar.java

import java.util.*;
import javax.swing.JOptionPane;

public class TestCalendar
{
	public static void main(String[] args)
	{
		//Introduction Message
		JOptionPane.showMessageDialog(null, "Ryan Sloan \n" + "CIS2235 Java I \n" + "Exercise 2 - Using the Calendar and Date Classes");
		
		//Current Date Time Message
		JOptionPane.showMessageDialog(null, "Date Object: " + new Date());
		
		//current date calender object
		Calendar calendar = new GregorianCalendar();
		
		//conversion from 0 to AM and 1 to PM
		/*String amPm = "AM";
		if(calendar.get(Calendar.AM_PM) == 1)
		{
			amPm = "PM";
		}*/
		
		//show calendar object output
		JOptionPane.showMessageDialog(null, "Calendar object: " + calendar.getTime() );
		//I discovered that I could use .getTime() to display the object's content but I left the remaining code to show you
		//the steps I originally took to display the object data including the conversion
		
		//+ (calendar.get(Calendar.MONTH) + 1) + "/" + calendar.get(Calendar.DATE) + "/" + 
		//calendar.get(Calendar.YEAR) + " " + calendar.get(Calendar.HOUR) + ":" + calendar.get(Calendar.MINUTE) + " " + amPm + "\n" );
		
		//creating a birthdate calendar object		
		Calendar birthdate = new GregorianCalendar(1979, (Calendar.AUGUST), 10, 2, 1);
				
		//conversion
		/*String amPm2 = "AM";
		if(birthdate.get(Calendar.AM_PM) == 1)
		{
			amPm2 = "PM";
		}*/
		
		//show birthdate object output
		JOptionPane.showMessageDialog(null, "Ryan's Birthday: " + birthdate.getTime() );
		//+ birthdate.get(Calendar.MONTH) + "/" + birthdate.get(Calendar.DATE) + "/" + birthdate.get(Calendar.YEAR) + " "  
		//birthdate.get(Calendar.HOUR) + ":0" + birthdate.get(Calendar.MINUTE) + " " + amPm2 + "\n");
		
		//setting Calendar object fields to my birthday
		calendar.set(Calendar.YEAR,1979);
		calendar.set(Calendar.MONTH, (Calendar.AUGUST));
		calendar.set(Calendar.DATE,10);
		calendar.set(Calendar.HOUR_OF_DAY,2);
		calendar.set(Calendar.MINUTE,1);
		JOptionPane.showMessageDialog(null,"Setting Calender Object to My Birthdate.");
		
		//conversion		
		/*String amPm3 = "AM";
		if(calendar.get(Calendar.AM_PM) == 1)
		{
			amPm3 = "PM";
		}*/
		
		//output
		JOptionPane.showMessageDialog(null, "The calendar object set to my birthdate: " + calendar.getTime() );
		//+ calendar.get(Calendar.MONTH) + "/" + calendar.get(Calendar.DATE) + "/" + calendar.get(Calendar.YEAR) + " "  
		//calendar.get(Calendar.HOUR) + ":0" + calendar.get(Calendar.MINUTE) + " " + amPm3 + "\n");
		
		//http://docs.oracle.com/javase/7/docs/api/
	}
}
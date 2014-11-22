// Ryan Sloan
// rsloan2@cnm.edu
// file: AlarmClock.java
// Program 1 The Alarm Clock
// CIS2235

import javax.swing.JOptionPane;
import java.util.*;
public class AlarmClock {
	public static void main(String[] args) {
	
		JOptionPane.showMessageDialog(null, "Ryan Sloan \n" + "CIS2235 \n" + "Program 1 - Alarm Clock \n");
		int option = JOptionPane.YES_OPTION;
		
		while (option == JOptionPane.YES_OPTION) {
		
			String input = JOptionPane.showInputDialog(null, "Enter a time and date after now but before 12/31/14 11:59 \n" +
															 "Enter the Year, Month, Day, Hour, Minute, AM/PM (use commas and numbers)");
			StringTokenizer st = new StringTokenizer(input, ",");
			String year = st.nextToken();
			String month = st.nextToken();
			String day = st.nextToken();
			String hour = st.nextToken();
			String min = st.nextToken();
			String amPm = st.nextToken();
			int yr = Integer.parseInt(year.trim());
			if (yr <= 2012 || yr >= 2015){
				JOptionPane.showMessageDialog(null,"You have entered an date that is out of range.");
			}
			else{
				int mth = Integer.parseInt(month.trim());
				mth -= 1;
				int dy = Integer.parseInt(day.trim());
				int hr = Integer.parseInt(hour.trim());
				int mn = Integer.parseInt(min.trim());
				String amPmtrim = amPm.trim();
				if( hr == 12 && amPmtrim.equals("AM"))
					hr = 0;
				else if(hr == 12 && amPmtrim.equals("PM"))
					hr = 12;
				else if(hr !=(12) && amPmtrim.equals("PM"))
					hr += 12;
				Calendar alarmDate = new GregorianCalendar(yr, mth, dy, hr, mn);
				Calendar currentDate = new GregorianCalendar();
				JOptionPane.showMessageDialog(null, "You entered: " + alarmDate.getTime());
				
				int totalHours, totalDays, totalMin, days, hours, minutes;
				int currentYear = currentDate.get(Calendar.YEAR);
				int alarmYear = alarmDate.get(Calendar.YEAR);
				int difference = alarmYear - currentYear;
				
				boolean isLeap;
				if (currentYear % 4 == 0 && alarmYear % 100 != 0)
					isLeap = true;
				else if (currentYear % 400 == 0)
					isLeap = true;
				else
					isLeap = false;
				if (difference > 0){
					int today = currentDate.get(Calendar.DAY_OF_YEAR);
					int alarmDay = alarmDate.get(Calendar.DAY_OF_YEAR);
					int daysToAlarm = (365 - today) + alarmDay;
					if(isLeap)
						daysToAlarm++;
					if(daysToAlarm > 0)
						daysToAlarm--;
					int currentHour = currentDate.get(Calendar.HOUR_OF_DAY);
					int alarmHour = alarmDate.get(Calendar.HOUR_OF_DAY);
					int currentMin = currentDate.get(Calendar.MINUTE);
					int alarmMin = alarmDate.get(Calendar.MINUTE);
					currentMin += (currentHour * 60);
					alarmMin += (alarmHour * 60);
					int newTime = (24 * 60) - currentMin;
					int timetoAlarm = newTime + alarmMin;
 					hours = timetoAlarm / 60;
					days = daysToAlarm;
					minutes = timetoAlarm % 60;
				}	
				else {
					int today = currentDate.get(Calendar.DAY_OF_YEAR);
					int alarmDay = alarmDate.get(Calendar.DAY_OF_YEAR);
					int daysToAlarm = alarmDay - today;
					if(daysToAlarm > 0)
						daysToAlarm--;
					int currentHour = currentDate.get(Calendar.HOUR_OF_DAY);
					int alarmHour = alarmDate.get(Calendar.HOUR_OF_DAY);
					int currentMin = currentDate.get(Calendar.MINUTE);
					int alarmMin = alarmDate.get(Calendar.MINUTE);
					currentMin += (currentHour * 60);
					alarmMin += (alarmHour * 60);
					int newTime = (24 * 60) - currentMin;
					int timetoAlarm = newTime + alarmMin;
					hours = timetoAlarm / 60;
					if(currentHour == alarmHour && today == alarmDay)
						hours -= 24;
					days = daysToAlarm;
					minutes = timetoAlarm % 60;
				}
				if (difference > 0) {
					if (days > 365)
						days -= 365;
					
					JOptionPane.showMessageDialog(null, "The remaining time until " + alarmDate.getTime() + "\n is: " + 
													difference + " Year(s)" + days + " Day(s), " + 
													hours + " Hour(s), " + minutes + " Minute(s)" );
				}
				else{									
					JOptionPane.showMessageDialog(null, "The remaining time until " + alarmDate.getTime() + "\n is: " + 
													days + " Day(s), " + hours + " Hour(s), " + minutes + " Minute(s)" );
				}
			}
			option = JOptionPane.showConfirmDialog(null, "Continue?");
		}
	}
}
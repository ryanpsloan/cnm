// Ryan Sloan
// CIS2235 - Program 3
// AlarmCalc.java

import java.util.*;
import java.lang.String;
import javax.swing.*;
import java.lang.*;

public class AlarmCalc
{
	//calendar objects
	Calendar currentDate;
	Calendar alarmDate;
	//class variables
	int yr;
	int mth;
	int dy;
	int hr;
	int mn;
	String amPmtrim;
	String report;
	
	public AlarmCalc()
	{
		
		/*yr = 2013; //currentDate.get(Calendar.YEAR);
		mth = 1; // currentDate.get(Calendar.MONTH);
		dy = 31; //currentDate.get(Calendar.DAY_OF_MONTH);
		hr = 11; //currentDate.get(Calendar.HOUR_OF_DAY);
		mn = 11; //currentDate.get(Calendar.MINUTE);*/
		currentDate = new GregorianCalendar();
	}
	
	public Date getCurrentDate()
	{
		return currentDate.getTime();
	}
	
	public Date getAlarmDate()
	{
		return alarmDate.getTime();
	}
	
	public void setInputData(String date, String time, String AMPM) 
			throws ArithmeticException, NumberFormatException, IllegalArgumentException, NoSuchElementException
	{
			currentDate = new GregorianCalendar();
			StringTokenizer stDate = new StringTokenizer(date, "/");
			String month = stDate.nextToken();
			String day = stDate.nextToken();
			String year = stDate.nextToken();
			
			StringTokenizer stTime = new StringTokenizer(time, ":");
			String hour = stTime.nextToken();
			String min = stTime.nextToken();
			
			String amPm = AMPM;
			
			
			mth = Integer.parseInt(month.trim());
			mth -= 1;
			dy = Integer.parseInt(day.trim());
			yr = Integer.parseInt(year.trim());
			hr = Integer.parseInt(hour.trim());
			mn = Integer.parseInt(min.trim());
			amPmtrim = amPm.trim();
		
		
			
			if( hr == 12 && amPmtrim.equals("AM"))
				hr = 24;
			else if(hr == 12 && amPmtrim.equals("PM"))
				hr = 12;
			else if(hr !=(12) && amPmtrim.equals("PM"))
				hr += 12;
			alarmDate = new GregorianCalendar(yr, mth, dy, hr, mn);
			
			if (alarmDate.get(Calendar.YEAR) < currentDate.get(Calendar.YEAR)) {
				throw new ArithmeticException("You entered a date prior to the current date/time.");
			}
			else if (alarmDate.get(Calendar.YEAR) == currentDate.get(Calendar.YEAR)) {
				if (alarmDate.get(Calendar.DAY_OF_YEAR) < currentDate.get(Calendar.DAY_OF_YEAR)) {
					throw new ArithmeticException("You entered a date prior to the current date/time.");
				}
			
				else if (alarmDate.get(Calendar.DAY_OF_YEAR) == currentDate.get(Calendar.DAY_OF_YEAR)) {
					if (alarmDate.get(Calendar.HOUR_OF_DAY) < currentDate.get(Calendar.HOUR_OF_DAY)){
						throw new ArithmeticException("You entered a date prior to the current date/time.");
					}
								
					else if (alarmDate.get(Calendar.HOUR_OF_DAY) == currentDate.get(Calendar.HOUR_OF_DAY)){ 
						if (alarmDate.get(Calendar.MINUTE) < currentDate.get(Calendar.MINUTE)){
							throw new ArithmeticException("You entered a date prior to the current date/time.");
						}
					}
				}	
			}
			calculate();
	}
	
	private void calculate() throws IllegalArgumentException
	{			
			int totalDays = 0;
			int totalHours = 0;
			int totalMinutes = 0;
			int remainingHours = 0;
			int remainingMinutes = 0;
			int year;
			
			if (alarmDate.get(Calendar.YEAR) > 2014)
				throw new IllegalArgumentException("You can't enter a Year greater than 2014.");
			year = alarmDate.get(Calendar.YEAR) - currentDate.get(Calendar.YEAR);
			if (year > 0)
				totalDays = (365 - currentDate.get(Calendar.DAY_OF_YEAR)) + alarmDate.get(Calendar.DAY_OF_YEAR);
			else
				totalDays = alarmDate.get(Calendar.DAY_OF_YEAR) - currentDate.get(Calendar.DAY_OF_YEAR);
			if (currentDate.get(Calendar.MINUTE) > alarmDate.get(Calendar.MINUTE) && currentDate.get(Calendar.HOUR_OF_DAY) > alarmDate.get(Calendar.HOUR_OF_DAY))
			{
				int tempMin = alarmDate.get(Calendar.MINUTE);
				int tempHour = alarmDate.get(Calendar.HOUR_OF_DAY);
				tempHour--;
				tempMin += 60;
				totalMinutes = tempMin - currentDate.get(Calendar.MINUTE);
				if (totalDays > 0)
				{
					totalDays--;
					tempHour += 24;
				}
				totalHours = tempHour - currentDate.get(Calendar.HOUR_OF_DAY);
			}
			else if (currentDate.get(Calendar.MINUTE) > alarmDate.get(Calendar.MINUTE) && currentDate.get(Calendar.HOUR_OF_DAY) < alarmDate.get(Calendar.HOUR_OF_DAY))
			{
				int tempMin = alarmDate.get(Calendar.MINUTE);
				int tempHour = alarmDate.get(Calendar.HOUR_OF_DAY);
				tempHour--;
				tempMin += 60;
				totalMinutes = tempMin - currentDate.get(Calendar.MINUTE);
				totalHours = tempHour - currentDate.get(Calendar.HOUR_OF_DAY);
			}
			else if (currentDate.get(Calendar.MINUTE) < alarmDate.get(Calendar.MINUTE) && currentDate.get(Calendar.HOUR_OF_DAY) < alarmDate.get(Calendar.HOUR_OF_DAY))
			{
				totalMinutes = alarmDate.get(Calendar.MINUTE) - currentDate.get(Calendar.MINUTE);
				totalHours = alarmDate.get(Calendar.HOUR_OF_DAY) - currentDate.get(Calendar.HOUR_OF_DAY);
			}
			else if (currentDate.get(Calendar.MINUTE) < alarmDate.get(Calendar.MINUTE) && currentDate.get(Calendar.HOUR_OF_DAY) > alarmDate.get(Calendar.HOUR_OF_DAY))
			{
				int tempHour = alarmDate.get(Calendar.HOUR_OF_DAY);
				totalMinutes = alarmDate.get(Calendar.MINUTE) - currentDate.get(Calendar.MINUTE);
				if (totalDays > 0)
				{
					totalDays--;
					tempHour += 24;
				}
				totalHours = tempHour - currentDate.get(Calendar.HOUR_OF_DAY);
			}
			else if (currentDate.get(Calendar.MINUTE) == alarmDate.get(Calendar.MINUTE) && currentDate.get(Calendar.HOUR_OF_DAY) > alarmDate.get(Calendar.HOUR_OF_DAY))
			{
				totalMinutes = currentDate.get(Calendar.MINUTE) - alarmDate.get(Calendar.MINUTE);
				totalHours = currentDate.get(Calendar.HOUR_OF_DAY) - alarmDate.get(Calendar.HOUR_OF_DAY);
			}
			else if (currentDate.get(Calendar.MINUTE) == alarmDate.get(Calendar.MINUTE) && currentDate.get(Calendar.HOUR_OF_DAY) < alarmDate.get(Calendar.HOUR_OF_DAY))
			{
				totalMinutes = currentDate.get(Calendar.MINUTE) - alarmDate.get(Calendar.MINUTE);
				int tempHour = alarmDate.get(Calendar.HOUR_OF_DAY);
				if (totalDays > 0)
				{
					totalDays--;
					tempHour += 24;
				}
				totalHours = tempHour - currentDate.get(Calendar.HOUR_OF_DAY);
			}
			else if (currentDate.get(Calendar.MINUTE) == alarmDate.get(Calendar.MINUTE) && currentDate.get(Calendar.HOUR_OF_DAY) == alarmDate.get(Calendar.HOUR_OF_DAY))
			{
				totalMinutes = currentDate.get(Calendar.MINUTE) - alarmDate.get(Calendar.MINUTE);
				totalHours = currentDate.get(Calendar.HOUR_OF_DAY) - alarmDate.get(Calendar.HOUR_OF_DAY);
			}
			report = "The time until your alarm date is: \n" + totalDays + " Day(s), " + totalHours + " Hour(s), " + totalMinutes + " Minute(s)";
				
				
	}
	public String getResults()
	{
		return report;
	}
}
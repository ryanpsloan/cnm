// Ryan Sloan
// rsloan2@cnm.edu
// AlarmCalc.java

import java.util.*;
import java.lang.String;

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
		
		yr = 2013; //currentDate.get(Calendar.YEAR);
		mth = 0; // currentDate.get(Calendar.MONTH);
		dy = 31; //currentDate.get(Calendar.DAY_OF_MONTH);
		hr = 11; //currentDate.get(Calendar.HOUR_OF_DAY);
		mn = 51; //currentDate.get(Calendar.MINUTE);
		currentDate = new GregorianCalendar(yr,mth,dy,hr,mn);
	}
	
	public Date getCurrentDate()
	{
		return currentDate.getTime();
	}
	
	public Date getAlarmDate()
	{
		return alarmDate.getTime();
	}
	
	public void setInputData(String input)
	{
			StringTokenizer st = new StringTokenizer(input, ",");
			String year = st.nextToken();
			String month = st.nextToken();
			String day = st.nextToken();
			String hour = st.nextToken();
			String min = st.nextToken();
			String amPm = st.nextToken();
			yr = Integer.parseInt(year.trim());
			mth = Integer.parseInt(month.trim());
			mth -= 1;
			dy = Integer.parseInt(day.trim());
			hr = Integer.parseInt(hour.trim());
			mn = Integer.parseInt(min.trim());
			amPmtrim = amPm.trim();
			if( hr == 12 && amPmtrim.equals("AM"))
				hr = 0;
			else if(hr == 12 && amPmtrim.equals("PM"))
				hr = 12;
			else if(hr !=(12) && amPmtrim.equals("PM"))
				hr += 12;
			alarmDate = new GregorianCalendar(yr, mth, dy, hr, mn);
			calculate();
	}
	
	private void calculate()
	{			
			int totalDays = 0;
			int totalHours = 0;
			int totalMinutes = 0;
			int remainingHours = 0;
			int remainingMinutes = 0;
			int year;
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
				tempHour--;
				totalMinutes = alarmDate.get(Calendar.MINUTE) - currentDate.get(Calendar.MINUTE);
				if (totalDays > 0)
				{
					totalDays--;
					tempHour += 24;
				}
				totalHours = tempHour - currentDate.get(Calendar.HOUR_OF_DAY);
			}
				
			report = "The time until your alarm date is: \n" + totalDays + " Day(s), " + totalHours + " Hour(s), " + totalMinutes + " Minute(s)";
				
				
	}
	public String getResults()
	{
		return report;
	}
}

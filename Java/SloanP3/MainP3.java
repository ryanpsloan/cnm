// Ryan Sloan
// CIS2235 - Program 3
// MainP3.java

import javax.swing.JFrame;


public class MainP3
{
	AlarmFrame frame;
	
	public static void main(String[] args)
	{
		MainP3 beginHere = new MainP3();
	}
	
	public MainP3()
	{
		frame = new AlarmFrame();
		frame.setTitle("Alarm Clock Calculator - SloanP3");
		frame.setSize(600,400);
		frame.setLocationRelativeTo(null);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}
	
	
}
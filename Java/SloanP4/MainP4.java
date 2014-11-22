// Ryan Sloan
// ryansdeal@hotmail.com
// MainP4.java

import javax.swing.*;
import java.awt.*;
import java.util.*;

public class MainP4
{
	private ColorFrame cframe;
	
	public static void main(String[] args)
	{
		MainP4 app = new MainP4();
	}
	
	public MainP4()
	{
		cframe = new ColorFrame();
		cframe.setTitle("Color Builder - Ryan Sloan - Program 4");
		cframe.setSize(500,500);
		cframe.setLocation(200,100);
		cframe.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		cframe.setVisible(true);
	}
}
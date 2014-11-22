// Ryan Sloan
// ryansdeal@hotmail.com
// ColorBuilder.java
// Program 4

import javax.swing.*;
import java.awt.*;
import java.util.*;

public class ColorBuilder
{	
	private int red;
	private int green;
	private int blue;
	Color color;
	
	ColorBuilder()
	{
		red = 0;
		green = 0;
		blue = 0;
		color = new Color(red,green,blue);
	}
	ColorBuilder(int r, int g, int b)
	{
		red = r;
		green = g;
		blue = b;
		color = new Color(red,green,blue);
	}
	
	public void setRed(int r)
	{
		red = r;
		color = new Color(red, 0, 0);
	}
	
	public void setGreen(int g)
	{
		green = g;
		color = new Color(0,green,0);
	}
	
	public void setBlue(int b)
	{
		blue = b;
		color = new Color(0,0,blue);
	}

	public Color getTheColor(int r, int g, int b)
	{
		red = r;
		green = g;
		blue = b;
		color = new Color(red,green,blue);
		return color;
	}
	
	public Color getContrastColor()
	{
		int cRed = 255 - red;
		int cGreen = 255 - green;
		int cBlue = 255 - blue;
	
		color = new Color(cRed,cGreen,cBlue);
		return color;
		
	}
	
	@Override
	public String toString()
	{
		String colorString = "Red: " + red + "Green: " + green + "Blue: " + blue;
		return colorString;
	}
	
	public Color getRed()
	{
		color = new Color(red,0,0);
		return color;
	}
	
	public Color getGreen()
	{
		color = new Color(0,green,0);
		return color;
	}
	
	public Color getBlue()
	{
		color = new Color(0,0,blue);
		return color;
	}
	
	public Color getContrastRed()
	{
		int cRed = 255 - red;
		color = new Color(0,cRed,0);
		return color;
	}
	
	public Color getContrastGreen()
	{
		int cGreen = 255 - green;
		color = new Color(0,0,cGreen);
		return color;
	}
	
	public Color getContrastBlue()
	{
		int cBlue = 255 - blue;
		color = new Color(cBlue,0,0);
		return color;
	}
}
	
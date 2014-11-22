// Ryan Sloan
// ryansdeal@hotmail.com
// Rectangle2D.java

import javax.swing.*;
import java.util.*;

public class Rectangle2D {
	
	private double x, y;
	private double width, height;
	
	Rectangle2D() {
		x = 0;
		y = 0;
		width = 1;
		height = 1;
	}
	
	Rectangle2D(double xC, double yC, double wC, double hC) {
		x = xC;
		y = yC;
		width = wC;
		height = hC;
	}
	
	double getX() {
		return x;
	}
	
	double getY() {
		return y;
	}
	
	void setX(double xC) {
		x = xC;
	}
	void setY(double yC) {
		y = yC;
	}
	double getWidth() {
		return width;
	}
	double getHeight() {
		return height;
	}
	void setWidth(double wC) {
		width = wC;
	}
	void setHeight(double hC) {
		height = hC;
	}
	double getArea() {
		double area = width*height; 
		return area;
	}
	double getPerimeter() {
		double perimeter = (2*width) + (2*height);
		return perimeter;
	}
	boolean contains(double pX, double pY) {
		if (pX < 0 && pY > 0) {
			if (pX >= -(width/2) && pY <= (height/2)) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (pX < 0 && pY < 0){
			if (pX >= -(width/2) && pY >= -(height/2)) {
				return true;
			}
			else {
				return false;
			}
		}
		else if(pX > 0 && pY < 0) {
			if (pX <= width/2 && pY >= -(height/2)) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			if(pX <= width/2 && pY <= height/2){
				return true;
			}
			else {
				return false;
			}
		}
	}
	
	public static void main(String[] args)
	{
		Rectangle2D rectangleOne = new Rectangle2D(0,0,6,3);
		JOptionPane.showMessageDialog(null, "I've created a rectangle at 0,0 where width = 6 and height = 3");
		JOptionPane.showMessageDialog(null, "The Area of your rectangle is " + rectangleOne.getArea());
		JOptionPane.showMessageDialog(null, "The Perimeter of your rectangle is " + rectangleOne.getPerimeter());
		JOptionPane.showMessageDialog(null, "Let's determine if a given point is inside the rectangle.");
		String input = JOptionPane.showInputDialog(null, "Enter a set of x,y coordinates marking \n the center of the rectangle seperated by a comma:");
		StringTokenizer st = new StringTokenizer(input, ",");
		String xCoord = st.nextToken();
		String yCoord = st.nextToken();
		double x = Double.parseDouble(xCoord.trim());
		double y = Double.parseDouble(yCoord.trim());
		boolean contains = rectangleOne.contains(x,y);
		if(contains)
			JOptionPane.showMessageDialog(null, "The point " + input + " is inside of the rectangle's perimeter");
		else
			JOptionPane.showMessageDialog(null, "The point " + input + " is not inside of the rectangle's perimeter");
	}
}




	
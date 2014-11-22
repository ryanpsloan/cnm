// Ryan Sloan
// ryansdeal@hotmail.com
// ShowGridLayout.java

import javax.swing.*;
import java.awt.GridLayout;

public class ShowGridLayout extends JFrame {
	public ShowGridLayout() {
		setLayout(new GridLayout(3,2,10,10));
	
		add(new JButton("ONE"));
		add(new JButton("TWO"));
		add(new JButton("THREE"));
		add(new JButton("FOUR"));
		add(new JButton("FIVE"));
		add(new JButton("SIX"));
		
	}
	
	public static void main(String[] args) {
		ShowGridLayout frame = new ShowGridLayout();
		frame.setTitle("Exercise 12.3");
		frame.setSize(400,400);
		frame.setLocationRelativeTo(null);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}
	

}
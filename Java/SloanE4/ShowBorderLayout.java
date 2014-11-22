// Ryan Sloan
// ryansdeal@hotmail.com
// ShowBorderLayout.java

import javax.swing.*;
import java.awt.BorderLayout;
import java.awt.GridLayout;

public class ShowBorderLayout extends JFrame {
	public ShowBorderLayout() {
	JPanel p1 = new JPanel();
	JPanel p2 = new JPanel();
	p1.setLayout(new GridLayout( 1, 3, 5, 10));
	p2.setLayout(new GridLayout( 1, 3, 5, 10));
	p1.add(new JButton("1"));
	p1.add(new JButton("2"));
	p1.add(new JButton("3"));
	p2.add(new JButton("4"));
	p2.add(new JButton("5"));
	p2.add(new JButton("6"));
	setLayout(new BorderLayout(10,10));
	add(p1,BorderLayout.CENTER);
	add(p2,BorderLayout.SOUTH);
	}
		
	public static void main(String[] args) {
		ShowBorderLayout frame = new ShowBorderLayout();
		frame.setTitle("Exercise 12.2");
		frame.setSize(400,400);
		frame.setLocationRelativeTo(null);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}

}
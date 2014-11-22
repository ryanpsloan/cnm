// Ryan Sloan
// ryansdeal@hotmail.com
// FlowLayout.java

import javax.swing.*;
import java.awt.FlowLayout;

public class ShowFlowLayout extends JFrame {
	
		public ShowFlowLayout() {
		setLayout(new FlowLayout(FlowLayout.LEFT, 10, 20));
		
		JPanel p1 = new JPanel();
		JPanel p2 = new JPanel();
		p1.setLayout(new FlowLayout(FlowLayout.LEFT, 5 , 5));
		p2.setLayout(new FlowLayout(FlowLayout.LEFT, 5 , 5));
		
		p1.add(new JButton("Button 1"));
		p1.add(new JButton("Button 2"));
		p1.add(new JButton("Button 3"));
		p2.add(new JButton("Button 4"));
		p2.add(new JButton("Button 5"));
		p2.add(new JButton("Button 6"));
		add(p1);
		add(p2);
		
		}
		
	public static void main(String[] args) {
	ShowFlowLayout frame = new ShowFlowLayout();
	frame.setTitle("Exercise 12.1");
	frame.setSize(300,300);
	frame.setLocationRelativeTo(null);
	frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	frame.setVisible(true);
	}
}

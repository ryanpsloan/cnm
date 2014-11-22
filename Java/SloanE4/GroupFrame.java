// Ryan Sloan
// ryansdeal@hotmail.com
// GroupButtons.java

import javax.swing.*;
import java.awt.*;

public class GroupFrame extends JFrame {
	public GroupFrame()
	{
		setLayout(new FlowLayout());
		GroupButtons gbtn1 = new GroupButtons();
		GroupButtons gbtn2 = new GroupButtons();
		add(gbtn1);
		add(gbtn2);
	
	}
	public static void main(String[] args) {
		
		
		GroupFrame frame = new GroupFrame();
		frame.setTitle("Exercise 12.4");
		frame.setSize(300,300);
		frame.setLocationRelativeTo(null);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
		
	}


}

class GroupButtons extends JPanel{
	public GroupButtons() {
		setLayout(new GridLayout(1,3,5,5));
		add(new JButton("1"));
		add(new JButton("2"));
		add(new JButton("3"));
		}
}
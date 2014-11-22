// Ryan Sloan
// CIS2235 - Program 3
// AlarmFrame.java

import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JFrame;
import javax.swing.JTextArea;
import javax.swing.JComboBox;
import javax.swing.JButton;
import javax.swing.JOptionPane;
import java.awt.GridLayout;
import java.awt.event.ActionListener;
import java.awt.event.*;
import java.util.*;


public class AlarmFrame extends JFrame
{
		AlarmCalc ac;
		JLabel jlDate;
		JLabel jlTime;
		JLabel jlAmPm;
		JTextField jtfDate;
		JTextField jtfTime;
		JComboBox jcbAmPm;
		JTextArea jtaResults;
		JButton jbCalc;
		String[] amPm = {"AM","PM"};
		
		
	public AlarmFrame()
	{
		ac = new AlarmCalc();
		initComponents();
	}	
	
	private void initComponents()
	{
		setLayout(new GridLayout(4,2,5,5));
		jlDate = new JLabel("Enter the Alarm Date: MM/DD/YYYY");
		add(jlDate);
		jtfDate = new JTextField(12);
		add(jtfDate);
		jlTime = new JLabel("Enter the Alarm Time: HH:MM");
		add(jlTime);
		jtfTime = new JTextField(7);
		add(jtfTime);
		jlAmPm = new JLabel("Select: ");
		add(jlAmPm);
		jcbAmPm = new JComboBox(amPm);
		add(jcbAmPm);
		jtaResults = new JTextArea("");
		add(jtaResults);
		jbCalc = new JButton("Calculate");
		add(jbCalc);
		CalculateListenerClass listener1 = new CalculateListenerClass();
		jbCalc.addActionListener(listener1);
	}
	
	class CalculateListenerClass implements ActionListener {
			
			@Override
			public void actionPerformed(ActionEvent e){
				String date = jtfDate.getText();
				String time = jtfTime.getText();
				String amPm =(String)jcbAmPm.getSelectedItem();
				boolean bExc = false;
				try {
					ac.setInputData(date,time,amPm);
				}
				catch (NumberFormatException nfx)
				{
					JOptionPane.showMessageDialog(null, "You entered an illegal value.");
					jtfDate.setText("");
					jtfTime.setText("");
					bExc = true;
				}
				catch (ArithmeticException ax)
				{
					JOptionPane.showMessageDialog(null, "You entered a date prior to the current date/time.");
					jtfDate.setText("");
					bExc = true;
				}
				catch (IllegalArgumentException iax)
				{
					JOptionPane.showMessageDialog(null, "Enter a date between now and 12/31/2014.");
					jtfDate.setText("");
					bExc = true;
				}
				catch (NoSuchElementException nse)
				{
					JOptionPane.showMessageDialog(null, "You entered an invalid entry.");
					jtfDate.setText("");
					jtfTime.setText("");
					bExc = true;
					
				}
				String results = ac.getResults();
				jtaResults.setText(results);
				if (bExc)
				{
					jtaResults.setText("");
				}
			}
		
		
	}
}

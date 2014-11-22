// Ryan Sloan
// ryansdeal@hotmail.com
// ColorFrame.java

import javax.swing.*;
import javax.swing.event.*;
import java.awt.*;
import java.util.*;

public class ColorFrame extends JFrame
{
	private ColorBuilder cb;
	private int variables;
	private JLabel jlblRed;
	private JLabel jlblGreen;
	private JLabel jlblBlue;
	private JLabel jlblMixed;
	private JLabel jlblSpace;
	private JSlider jsldRed;
	private JSlider jsldGreen;
	private JSlider jsldBlue;
	
	public ColorFrame()
	{
		cb = new ColorBuilder();
		initComponents();
	}
	
	private void initComponents()
	{
		setLayout(new GridLayout(4,1));
		
		
				
		//Red Slider
		jsldRed = new JSlider(0,255,0);
		jsldRed.setPaintTicks(true);
		jsldRed.setPaintTrack(true);
		jsldRed.setMajorTickSpacing(5);
		jsldRed.setMinorTickSpacing(1);
		jsldRed.addChangeListener(new ChangeListener() {
			@Override
			public void stateChanged(ChangeEvent e){
				double value = jsldRed.getValue();
				cb.setRed((int)value);
				jlblRed.setBackground(cb.getRed());
				jlblRed.setForeground(cb.getContrastRed());
				jlblRed.setText("Red: " + jsldRed.getValue());
				jlblMixed.setBackground(cb.getTheColor(jsldRed.getValue(),jsldGreen.getValue(),jsldBlue.getValue()));
				jlblMixed.setForeground(cb.getContrastColor());
				jlblMixed.setText("Red: " + jsldRed.getValue() + " Green: " + jsldGreen.getValue() + " Blue: " + jsldBlue.getValue());
			}
		});
		
		//Green Slider
		jsldGreen = new JSlider(0,255,0);
		jsldGreen.setPaintTicks(true);
		jsldGreen.setPaintTrack(true);
		jsldGreen.setMajorTickSpacing(5);
		jsldGreen.setMinorTickSpacing(1);
		jsldGreen.addChangeListener(new ChangeListener() {
			@Override
			public void stateChanged(ChangeEvent e){
				double value = jsldGreen.getValue();
				cb.setGreen((int)value);
				jlblGreen.setBackground(cb.getGreen());
				jlblGreen.setForeground(cb.getContrastGreen());
				jlblGreen.setText("Green: " + jsldGreen.getValue());
				jlblMixed.setBackground(cb.getTheColor(jsldRed.getValue(),jsldGreen.getValue(),jsldBlue.getValue()));
				jlblMixed.setForeground(cb.getContrastColor());
				jlblMixed.setText("Red: " + jsldRed.getValue() + " Green: " + jsldGreen.getValue() + " Blue: " + jsldBlue.getValue());
			}
		});
		//Blue Slider
		jsldBlue = new JSlider(0,255,0);
		jsldBlue.setPaintTicks(true);
		jsldBlue.setPaintTrack(true);
		jsldBlue.setMajorTickSpacing(5);
		jsldBlue.setMinorTickSpacing(1);
		jsldBlue.addChangeListener(new ChangeListener() {
			@Override
			public void stateChanged(ChangeEvent e){
				double value = jsldBlue.getValue();
				cb.setBlue((int)value);
				jlblBlue.setBackground(cb.getBlue());
				jlblBlue.setForeground(cb.getContrastBlue());
				jlblBlue.setText("Blue: " + jsldBlue.getValue());
				jlblMixed.setBackground(cb.getTheColor(jsldRed.getValue(),jsldGreen.getValue(),jsldBlue.getValue()));
				jlblMixed.setForeground(cb.getContrastColor());
				jlblMixed.setText("Red: " + jsldRed.getValue() + " Green: " + jsldGreen.getValue() + " Blue: " + jsldBlue.getValue());
			}
		});
		
		//Mixed Panel and Label
		JPanel panelMix = new JPanel();
		panelMix.setLayout(new GridLayout(2,1));
		jlblSpace = new JLabel();
		jlblMixed = new JLabel();
		panelMix.add(jlblSpace);
		panelMix.add(jlblMixed);
		jlblMixed.setOpaque(true);
		jlblMixed.setText("Red: " + jsldRed.getValue() + " Green: " + jsldGreen.getValue() + " Blue: " + jsldBlue.getValue());
		jlblMixed.setBackground(cb.getTheColor(jsldRed.getValue(),jsldGreen.getValue(),jsldBlue.getValue()));
		jlblMixed.setForeground(cb.getContrastColor());
		
		//Red Panel and Label
		JPanel panelRed = new JPanel();
		panelRed.setLayout(new GridLayout(2,1));
		panelRed.add(jsldRed);
		jlblRed = new JLabel();
		jlblRed.setOpaque(true);
		jlblRed.setText("Red: " + jsldRed.getValue());
		jlblRed.setBackground(cb.getRed());
		jlblRed.setForeground(cb.getContrastRed());
		panelRed.add(jlblRed);
		
		//Green Panel and Label
		JPanel panelGreen = new JPanel();
		panelGreen.setLayout(new GridLayout(2,1));
		panelGreen.add(jsldGreen);
		jlblGreen = new JLabel();
		jlblGreen.setOpaque(true);
		jlblGreen.setText("Green: " + jsldGreen.getValue());
		jlblGreen.setBackground(cb.getGreen());
		jlblGreen.setForeground(cb.getContrastGreen());
		panelGreen.add(jlblGreen);
		
		//Blue Panel and Label
		JPanel panelBlue = new JPanel();
		panelBlue.setLayout(new GridLayout(2,1));
		panelBlue.add(jsldBlue);
		jlblBlue = new JLabel();
		jlblBlue.setOpaque(true);
		jlblBlue.setText("Blue: " + jsldBlue.getValue());
		jlblBlue.setBackground(cb.getBlue());
		jlblBlue.setForeground(cb.getContrastBlue());
		panelBlue.add(jlblBlue);
		
		//add panels
		add(panelRed);
		add(panelGreen);
		add(panelBlue);
		add(panelMix);
	}
}
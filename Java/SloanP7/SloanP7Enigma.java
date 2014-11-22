/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package sloan.p7.enigma;

import javax.swing.JFrame;

/**
 *
 * @author rsloan2
 */
public class SloanP7Enigma {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
       SloanP7Enigma app = new SloanP7Enigma();
    }
    
    public SloanP7Enigma()
    {
        NewJFrame frame = new NewJFrame();
        frame.setTitle("Ryan Sloan - Enigma - Program 7");
        frame.setSize(500,700);
        frame.setLocation(200,100);
	frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	frame.setVisible(true);
    }
}


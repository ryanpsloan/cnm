/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package sloan.p7.enigma;

import javax.swing.JFrame;

/**
 *
 * @author O
 */
public class SloanE6 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
       SloanE6 app = new SloanE6();
    }
    
    public SloanE6()
    {
        NewJFrame frame = new NewJFrame();
        frame.setTitle("Ryan Sloan - Enigma - Program 7");
        frame.setSize(500,300);
        frame.setLocation(200,100);
	frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	frame.setVisible(true);
    }
}



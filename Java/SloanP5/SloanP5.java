/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package sloanp5;

/**
 *
 * @author rsloan2
 */
import javax.swing.JFrame;

public class SloanP5 {
    NewJFrame frame;
 
    public static void main(String[] args) {
        // TODO code application logic here
        SloanP5 app = new SloanP5();
    
    }
    
    public SloanP5()
    {
       frame = new NewJFrame();
       frame.setTitle("Luminosity Candle Company");
       frame.setSize(500,500);
       frame.setLocationRelativeTo(null);
       frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
       frame.setVisible(true);
    }
}

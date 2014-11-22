/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package sloanp5;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import javax.swing.JOptionPane;

/**
 *
 * @author rsloan2
 */
public class Data {
    private String name;
    private String address;
    private int comboIndex;
    private String selection;
    private int brightness;
    private int quantity;
    private String wax;
    private String waxOutput;
    private String color;
    private boolean thermaWick;
    private boolean floating;
    private boolean flameless;
    private String summary;
    public Data()
    {
        name = "No Name Entered";
        address = "No Address Entered";
        comboIndex = 0;
        selection = "Pillar Candle(s)";
        brightness = 75;
        quantity = 1;
        wax = "scented";
        waxOutput = "Scented";
        color = "Red";
        thermaWick = false;
        floating = false;
        flameless = false;
    }
    
    public void setName(String input)
    {
        name = input;
    }
    
    public void setAddress(String data)
    {
        address = data;
    }
    
    public void setCombo(int index)
    {
        comboIndex = index;
        if(comboIndex == 0)
            selection = "Pillar Candle(s)";
        else if (comboIndex == 1)
            selection = "Taper Candle(s)";
        else if (comboIndex == 2)
            selection = "Jar Candle(s)";
        else if (comboIndex == 3)
            selection = "Votive Candle(s)";
    }
     
    public void setBrightness(int meter)
    {
        brightness = meter;
    }
    
    public void setQuantity(int q)
    {
        quantity = q;
    }
    
    public void setWax(String waxInput)
    {
        wax = waxInput;
        if (wax == "scented")
            waxOutput = "Scented Candle Wax ";
        else if (wax == "unscented")
            waxOutput = "Unscented Candle Wax ";
        else if (wax == "gel")
            waxOutput = "Gel ";
    }
    
    public void setColor(String colorInput)
    {
        color = colorInput;
    }
    
    public void setTherma(boolean checked)
    {
        if (checked == true)
            thermaWick = true;
        else 
            thermaWick = false;
    }
    
    public void setFloating(boolean checked)
    {
        if (checked == true)
            floating = true;
        else 
            floating = false;
    }
    public void setFlameless(boolean checked)
    {
        if (checked == true)
            flameless = true;
        else 
            flameless = false;
    }
    
    
    @Override public String toString()
    {
        summary = name + " Shipping Address: " + address + "\n" + quantity + " " + selection + " having a brightness index of " + brightness + "\nmade of " + waxOutput + " the color selected is " + color + "\n";
        if (thermaWick) 
            summary += "including Thermawick ";
        if(floating)
            summary += "made to float ";
        if (flameless)
            summary += "with flameless wicks";
        return summary + ".";
        
    }
    public void writeFile(File file)
    {
        
        try
        {
            FileWriter fstream = new FileWriter(file);
            BufferedWriter out = new BufferedWriter(fstream);
            out.write(summary.replaceAll("\n", System.getProperty("line.separator")));
            out.close();
        }
        catch(Exception e)
        {
            JOptionPane.showMessageDialog(null,"Error: " + e.getMessage());
        }
    }
    
}

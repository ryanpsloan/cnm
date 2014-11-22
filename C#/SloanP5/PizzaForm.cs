using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace SloanP5
{
    public partial class Form1 : Form
    {

        PizzaClass refPizza;
        List<string> choices;

        public Form1()
        {
            InitializeComponent();
            refPizza = new PizzaClass();
            choices = new List<string>();
        }

        public Form1(PizzaClass passPizza)
        {
            InitializeComponent();
            refPizza = new PizzaClass();
            choices = new List<string>();
            refPizza = passPizza;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //getting info from chkbxs
            //and filling list
            int count = 0;
            if (cbCheese.Checked)
            {
                choices.Add("Extra Cheese");
                count++;
            }
            if (cbPepperoni.Checked)
            {
                choices.Add("Pepperoni");
                count ++;
            }
            if (cbMushroom.Checked)
            {
                choices.Add("Mushrooms");
                count++;
            }
            if (cbOlives.Checked)
            {
                choices.Add("Black Olives");
                count++;
            }
            if (cbPineapple.Checked)
            {
                choices.Add("Pineapple");
                count++;
            }
            if (cbGreenChili.Checked)
            {
                choices.Add("Green Chili");
                count++;
            }
            //assigning to class using properties
            refPizza.TopNum = count;
            refPizza.toppingslist = choices;
            
            //Determining Size            
            int pSize = 0;
            if (rblarge.Checked)
                pSize = 14;
            else if (rbmedium.Checked)
                pSize = 12;
            else if (rbsmall.Checked)
                pSize = 10;
            //assigning to the class
            refPizza.Size = pSize;

            //assigning the index value of the combo box
            refPizza.Crust = cbbCrust.SelectedIndex;
            this.DialogResult = DialogResult.OK;
                     
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //Resets the form.
            textBox1.Clear();
            //reset radio buttons
            rbsmall.Checked = true;
            rbmedium.Checked = false;
            rblarge.Checked = false;
            //resets check boxes
            cbCheese.Checked = false;
            cbPepperoni.Checked = false;
            cbMushroom.Checked = false;
            cbOlives.Checked = false;
            cbPineapple.Checked = false;
            cbGreenChili.Checked = false;
            //resets combo box
            cbbCrust.Text = "Choose Crust Type";
            choices.Clear();
        }
    }
}

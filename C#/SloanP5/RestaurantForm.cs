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
    public partial class RestaurantForm : Form
    {
        PizzaClass passPizza;
        Restaurant restClass;
        public RestaurantForm()
        {
            InitializeComponent();
            restClass = new Restaurant();
            cboxsalad.Items.AddRange(restClass.Salads);
            cboxpasta.Items.AddRange(restClass.Pastas);
            cboxchicken.Items.AddRange(restClass.Chicken);
            cboxseafood.Items.AddRange(restClass.Seafood);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            restClass.SaladIndex = cboxsalad.SelectedIndex;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            restClass.PastaIndex = cboxpasta.SelectedIndex;
        }
        
        private void button3_Click(object sender, EventArgs e)
        {
            restClass.ChickenIndex = cboxchicken.SelectedIndex;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            restClass.SeafoodIndex = cboxseafood.SelectedIndex;
        }
        
        private void button5_Click(object sender, EventArgs e)
        {
            richTextBox1.Text = restClass.ToString();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            richTextBox1.Clear();
            checkBox1.Checked = false;
            checkBox2.Checked = false;
            checkBox3.Checked = false;
            checkBox4.Checked = false;
            checkBox5.Checked = false;
            checkBox6.Checked = false;
            checkBox7.Checked = false;
            checkBox8.Checked = false;
            restClass = new Restaurant();
            cboxchicken.Text = "Chicken";
            cboxpasta.Text = "Pasta";
            cboxsalad.Text = "Salad";
            cboxseafood.Text = "Seafood";
        }

        private void button7_Click(object sender, EventArgs e)
        {
            passPizza = new PizzaClass();
            Form1 pizzaform = new Form1(passPizza);
            DialogResult selopt = pizzaform.ShowDialog();
            if (selopt == DialogResult.OK)
            {
                restClass.Pizza = passPizza;
            }
        }

        private void BevAdd_Click(object sender, EventArgs e)
        {
            if (checkBox1.Checked == true)
                restClass.Bev(0);
            if (checkBox2.Checked == true)
                restClass.Bev(1);
            if (checkBox3.Checked == true)
                restClass.Bev(2);
            if (checkBox4.Checked == true)
                restClass.Bev(3);
            if (checkBox5.Checked == true)
                restClass.Bev(4);
            if (checkBox6.Checked == true)
                restClass.Bev(5);
            if (checkBox7.Checked == true)
                restClass.Bev(6);
            if (checkBox8.Checked == true)
                restClass.Bev(7);
        }

        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {

        }
    }
}

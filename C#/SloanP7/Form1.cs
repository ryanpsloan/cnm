using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace SloanP7
{
    public partial class Form1 : Form
    {
        private BankAcct bankAcct;
        private SilverBankAcct silver;
        private GoldBankAcct gold;
        private BankAcct[] accts;
        
        public Form1()
        {
            InitializeComponent();
            accts = new BankAcct[3];
            bankAcct= new BankAcct("Ryan Sloan", 12345, 500.00);
            silver = new SilverBankAcct(123456789, 6789, "Ryan Sloan", 12345, 1500.00);
            gold = new GoldBankAcct(.0283, 123456789, 6789, "Ryan Sloan", 12345, 25000.00);
            accts[0] = bankAcct;
            accts[1] = silver;
            accts[2] = gold;
        }

        private void AcctcomboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            
        }

        private void nametb_TextChanged(object sender, EventArgs e)
        {

        }

        private void accttb_TextChanged(object sender, EventArgs e)
        {

        }

        private void PINtb_TextChanged(object sender, EventArgs e)
        {

        }

        private void Amounttb_TextChanged(object sender, EventArgs e)
        {

        }

        private void Processbutton_Click(object sender, EventArgs e)
        {
            int index = AcctcomboBox1.SelectedIndex;
            index++;
            bool valid = MyValidationLibrary.Validator.IsPresent(nametb) &&
                         MyValidationLibrary.Validator.IsPresent(accttb) &&
                         MyValidationLibrary.Validator.IsPresent(PINtb) &&
                         MyValidationLibrary.Validator.IsInt(accttb) &&
                         MyValidationLibrary.Validator.IsInt(PINtb);
                         
            if (valid)
            {
                accts[index].CustomerName = nametb.Text;
                accts[index].AcctNumber = Convert.ToInt32(accttb.Text);
                if (index == 1 || index == 2)
                {
                    silver.AtmAcctNumber = Convert.ToInt32(accttb.Text) + Convert.ToInt32(PINtb.Text);
                    silver.PIN = Convert.ToInt32(PINtb.Text);
                }
            }   
            else
            {
                returntb.Text = "The form is not completely filled out.";
            }

            if (Depositrb.Checked)
            {
                bool validator = MyValidationLibrary.Validator.IsPresent(Amounttb) &&
                    MyValidationLibrary.Validator.IsDouble(Amounttb);
                if (validator)
                {
                    accts[index].Deposit(Convert.ToDouble(Amounttb.Text));
                    returntb.Text = "You deposited $" + Amounttb.Text +
                    " into account " + accttb.Text + " today. " + accts[index].ToString();
                }
            }
            if (Withdrawrb.Checked)
            {
                bool validation = MyValidationLibrary.Validator.IsPresent(Amounttb) && 
                    MyValidationLibrary.Validator.IsDouble(Amounttb);
                if (validation)
                {
                    bool bWithdrawl = accts[index].Withdraw(Convert.ToDouble(Amounttb.Text));
                    if (bWithdrawl)
                    {
                        returntb.Text = "You withdrew $" + Amounttb.Text +
                        " from account " + accttb.Text + " today. " + accts[index].ToString();
                    }
                    else
                    {
                        returntb.Text = "You are attempting to withdraw an amount greater than your balance. " +
                        "Your balance is " + accts[index].SvgsAcctBalance.ToString("C") + ".";
                    }
                }
            }
            if (Acctinforb.Checked)
            {
                if (index == 2)
                {
                    returntb.Text = accts[index].ToString() + " " + "You received " + gold.InterestPaid.ToString("C") + " in interest at a " + 100 * gold.InterestRate + "% interest rate.";
                }
                else
                {
                    returntb.Text = accts[index].ToString();
                }
            }

        }

        private void ClearButton_Click(object sender, EventArgs e)
        {
            AcctcomboBox1.ResetText();
            nametb.Clear();
            accttb.Clear();
            PINtb.Clear();
            Amounttb.Clear();
            returntb.Clear();
            Depositrb.Checked = false;
            Withdrawrb.Checked = false;
            Acctinforb.Checked = false;
            AcctcomboBox1.Text = "Select Your Account";
        }

        private void returntb_TextChanged(object sender, EventArgs e)
        {

        }

        private void Depositrb_CheckedChanged(object sender, EventArgs e)
        {
            
        }

        private void Withdrawrb_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void Acctinforb_CheckedChanged(object sender, EventArgs e)
        {

        }

        
    }
}

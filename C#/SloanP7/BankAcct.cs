// CIS1280 - Ivonne Nelson
// Ryan Sloan - rsloan2@cnm.edu
// C# Banking Center - Inheritance and Polymorphism
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SloanP7
{
    class BankAcct
    {
        private string customerName;
        private int acctNumber;
        private double svgsAcctBalance;
    
        public BankAcct()
        {
            customerName = "Customer";
            acctNumber = 12345;
            svgsAcctBalance = 0.00;
        }

        public BankAcct(string name, int acctNum, double svgsAcctBal)
        {
            customerName = name;
            acctNumber = acctNum;
            svgsAcctBalance = svgsAcctBal;
        }

        public string CustomerName
        {
            get
            { return customerName;}
            set
            { customerName = value;}
        }

        public int AcctNumber
        {
            get
            { return acctNumber; }
            set
            { acctNumber = value; }
        }

        public double SvgsAcctBalance
        {
            get
            { return svgsAcctBalance; }
            set
            { svgsAcctBalance = value; }
        }

        public virtual void Deposit(double depositAmt)
        {
            svgsAcctBalance += depositAmt;
        }

        public virtual bool Withdraw(double withdrawlAmt)
        {
            if (withdrawlAmt <= svgsAcctBalance)
            {
                svgsAcctBalance -= withdrawlAmt;
                return true;
            }
            else
            {
                return false;
            }
        }

        public override string ToString()
        {
            return "The balance of account " + acctNumber + " is " + svgsAcctBalance.ToString("C") + ". Thank You " + customerName;
        }
    
    
    }


}

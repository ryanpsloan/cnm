// CIS1280 - Ivonne Nelson
// Ryan Sloan - rsloan2@cnm.edu
// C# Banking Center - Inheritance and Polymorphismusing System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SloanP7
{
    class SilverBankAcct : BankAcct
    {
        private int atmAcctNumber;
        private int pin;

        public SilverBankAcct()
        {
            atmAcctNumber = 0;
            pin = 1234;
        }
        
        public SilverBankAcct(int atmNumber, int pin, string name, int acctNum, 
            double svgsAcctBal) : base(name, acctNum, svgsAcctBal)
        {
            atmAcctNumber = atmNumber;
            this.pin = pin;
        }
        
        public int AtmAcctNumber
        {
            get { return atmAcctNumber; }
            set { atmAcctNumber = value; }
        }

        public int PIN
        {
            get { return pin; }
            set { pin = value; }
        }
        
        public override void Deposit(double deposit)
        {
            if (SvgsAcctBalance < 1000)
                SvgsAcctBalance -= 1.00;
            SvgsAcctBalance += deposit;

        }

        public override bool Withdraw(double withdrawl)
        {
            if (withdrawl <= SvgsAcctBalance)
            {
                SvgsAcctBalance -= 2.50;
                SvgsAcctBalance -= withdrawl;
                return true;
            }
            else
            {
                return false;
            }
        }

        public override string ToString()
        {
            return "The balance of account " + AcctNumber + " is " + SvgsAcctBalance.ToString("C") + ". Thank you " + CustomerName;
        }
    }
}

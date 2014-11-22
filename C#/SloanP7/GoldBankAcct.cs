// CIS1280 - Ivonne Nelson
// Ryan Sloan - rsloan2@cnm.edu
// C# Banking Center - Inheritance and Polymorphismusing System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SloanP7
{
    class GoldBankAcct : SilverBankAcct
    {
        private double interestRate;
        private double interestPaid;

        public GoldBankAcct()
        {
            interestRate = .0258;
            Interest(interestRate);
        }

        public GoldBankAcct(double interestRt, int atmNumber, int pin, 
        string name, int acctNum, double svgsAcctBal) : base(atmNumber, 
        pin, name, acctNum, svgsAcctBal)
        {
            this.interestRate = interestRt;
            Interest(interestRate);
        }

        public double InterestRate
        {
            get { return interestRate; }
            set { interestRate = value; Interest(interestRate); }
        }

        public double InterestPaid
        {
            get { return interestPaid; }
        }

        private void Interest(double interestRate)
        {
            if (SvgsAcctBalance >= 5000)
            {
                interestPaid = (SvgsAcctBalance * interestRate);
                SvgsAcctBalance = SvgsAcctBalance + interestPaid;
            }
            
        }

        public override void Deposit(double deposit)
        {
            if (SvgsAcctBalance <= 20000)
            {
                SvgsAcctBalance -= 2.50;
            }
            SvgsAcctBalance += deposit;
        }

        public override bool Withdraw(double withdrawl)
        {
            if (SvgsAcctBalance < 20000)
            {
                SvgsAcctBalance -= 1.00;
            }
            if (withdrawl <= SvgsAcctBalance)
            {
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
            return "The balance of account " + AcctNumber + " is " + SvgsAcctBalance.ToString("C") + ". Thank you " + CustomerName + ".";
        }
    }
}

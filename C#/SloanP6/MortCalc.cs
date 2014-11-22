using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using ValidationLib;

namespace SloanP6
{
    class MortCalc
    {
        private double principal;
        private double interest;
        private int years;
        private double totalLoanCost;
        private double totalInterest;
        private double monthlyPayment;
        private int numOfPayments = 12;
       
        
        public MortCalc()
        {
            Principal = 0.00;
            Interest = 0.00;
            Years = 0;
            MonthlyPayment = 0.00;
            TotalInterest = 0.00;
            TotalLoanCost = 0.00;
        }

        public MortCalc(double princ, double inter, int yrs)
        {
            Principal = princ;
            Interest = inter;
            Years = yrs;
            MonthlyPayment = 0.00;
            TotalInterest = 0.00;
            TotalLoanCost = 0.00;
            Calculate();
        
        }

        public double Principal
        {
            get
            {
                return principal;
            }
            set
            {
                principal = value;
               
            }
        }

        public double Interest
        {
            get
            {
                return interest;
            }
            set
            {
                interest = value;
                
            }
        }

        public int Years
        {
            get
            {
                return years;
            }
            set
            {
                years = value;
                
            }
        }

        public double TotalLoanCost
        {
            get
            {
                return totalLoanCost;
            }
            set
            {
                totalLoanCost = value;
            }
        }

        public double TotalInterest
        {
            get
            {
                return totalInterest;
            }
            set
            {
                totalInterest = value;
            }
        }

        public virtual double MonthlyPayment
        {
            get
            {
                return monthlyPayment;

            }
            set
            {
                monthlyPayment = value;
            }
        }

        private void Calculate()
        {
            monthlyPayment = (principal * interest) / (numOfPayments * 
            (1 - Math.Pow((1 + (interest / numOfPayments)), 
            (-1 * numOfPayments * years))));
            totalLoanCost = monthlyPayment * (numOfPayments * years);
            totalInterest = totalLoanCost - principal;
            
        }
    }
}

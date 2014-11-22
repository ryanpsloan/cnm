using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using ValidationLib;

namespace SloanP6
{
    class MortCalcPlus : MortCalc
    {
        private double taxes;
        private double insurance;

        public MortCalcPlus()
        {
            taxes = 0.00;
            insurance = 0.00;
        }

        public MortCalcPlus(double princ, double inter, int yrs, double yrlytaxes, 
        double yrlyinsurance): base(princ, inter, yrs)
        {
            taxes = yrlytaxes;
            insurance = yrlyinsurance;
        }

        public double Taxes
        {
            get
            {
                return taxes;
            }
            set
            {
                taxes = value;
            }
        }

        public double Insurance
        {
            get
            {
                return insurance;
            }
            set
            {
                insurance = value;
            }
        }

        public override double MonthlyPayment
        {
            get
            {
                return base.MonthlyPayment + ((insurance + taxes) / 12);
            }
        }         
            
        
    }
}

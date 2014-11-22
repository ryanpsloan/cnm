using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SloanE7
{
    class CarInsurance
    {
        private int driversAge;
        private string stateOfResidence;
        private double premium;

        public int DriversAge
        {
            get
            {
                return driversAge;
            }
            set
            {
                driversAge = value;
            }
        }

        public string StateOfResidence
        {
            get
            {
                return stateOfResidence;
            }
            set 
            {
                stateOfResidence = value;
            }
        }

        public double PremiumCalc()
        {
            if (stateOfResidence == "IL")
            {
                premium += 100;
                premium += 3 * (100 - driversAge);
            }
            else if (stateOfResidence == "WI")
            {
                premium += 50;
                premium += 3 * (100 - driversAge);
            }
            return premium;
        }

    }
}

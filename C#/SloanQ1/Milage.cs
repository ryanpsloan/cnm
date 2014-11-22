using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SloanQ1
{
    class Milage
    {   
        //variables - private and double
        private double milesDriven;
        private double gallonsUsed;
        private double mpg;

        //properties 
        //public property to encapsulate milesDriven, get is not used
        //but is available if necessary
        public double MilesDriven 
        {
            get
            {
                return milesDriven;
            }
            set
            {
                milesDriven = value;
                Calculate();
            }
        }
        //public property to encapsulate gallonsUsed, get is not used
        //but is available if necessary
        public double GallonsUsed 
        {
            get
            {
                return gallonsUsed;
            }
            set
            {
                gallonsUsed = value;
                Calculate();
            }
        }
        //public property to return mpg value after calculation method is run, no set
        //as don't want the value of this variable set from anywhere but inside the class using Calculation()
        public double Mpg
        {
            get
            {
                return mpg;
            }
        }    
        
        //constructors
        //parameterless, must use the properties to assign inputted values to the the two variables
        public Milage()
        {
            milesDriven = 0;
            gallonsUsed = 0;
            
        }
        //overloaded, receives input and runs calculate method
        public Milage(double mDriven, double gUsed)
        {
            milesDriven = mDriven;
            gallonsUsed = gUsed;
            Calculate();
        }
        //private method to calculate mpg
        private void Calculate()
        {
            mpg = milesDriven / gallonsUsed;

        }
    }
}

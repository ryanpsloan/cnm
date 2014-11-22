// CIS1280 - Ivonne Nelson
// Ryan Sloan, rsloan2@cnm.edu
// SloanP4/Fraction.cs

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SloanP4
{
    class Fraction
    {
        //private fields
        private int wholeNum;
        private int numerator;
        private int denomenator;
        //public properties for accessing the fields
        public int WholeNum
        {
            get
            {
                return wholeNum;
            }
            set
            {
                wholeNum = value;
            }

        }

        public int Numerator
        {
            get
            {
                return numerator;
            }
            set
            {
                numerator = value;
            }
        }

        public int Denomenator
        {
            get
            {
                return denomenator;
            }
            set
            {
                //if value is zero the value of the denomenator is changed to 1.
                if (value == 0)
                    denomenator = 1;
                else
                    denomenator = value;
            }
        }

        //first constructor three parameters
        public Fraction(int whole, int numer, int denom)
        {
            wholeNum = whole;
            numerator = numer;
            denomenator = denom;
        }

        //second constructor
        public Fraction(int numer, int denom)
        {
            wholeNum = 0;
            numerator = numer;
            denomenator = denom;
        }

        // parameterless constructor
        public Fraction()
        {
            wholeNum = 0;
            numerator = 0;
            denomenator = 1;
        }

        //methods
        public void Reduce()
        {
            //if there is a whole number, multiply it times the denomenator and 
            //add it to the numerator then change wholeNum to 0 changing the form 
            //of the fraction to numerator/denomenator with no whole number
            if (wholeNum > 0)
            {
                numerator += wholeNum * denomenator;
                wholeNum = 0;
            }
            //loop through the values of numerator and denomenator using modulus
            //to determine a number both numbers are divisible by (i), then divide 
            //by that number
            for (int i = 100; i > 1; --i)
            {
                if (numerator % i == 0 && denomenator % i == 0)
                {
                    numerator /= i;
                    denomenator /= i;
                }
            }

        }
        //return the fraction to the form of whole number numerator/denomenator
        //divide numerator by denomenator and get wholeNum
        //subtract denomenator multiplied by wholeNum to get numerator value
        public void Divide()
        { 
            wholeNum = numerator / denomenator;
            numerator -= denomenator * wholeNum;
            if (numerator % denomenator == 0)
            {
                denomenator = 0;
            }


        }
        //Overloaded operator + if common denomenator adds numerators
        //if not common makes common by muliplying first and second denomenator 
        //and cross multiplying num1 and denom2 and num2 and denom1
        //runs reduce and divide to reduce fraction to lowest form and change 
        //its form back to leading whole number 
        public static Fraction operator +(Fraction first, Fraction second)
        {
            Fraction newfraction = new Fraction();
            if (first.denomenator == second.denomenator)
            {
                newfraction.denomenator = first.denomenator;
                newfraction.numerator = first.numerator + second.numerator;
            }
            if (first.denomenator != second.denomenator)
            {
                newfraction.denomenator = first.denomenator * second.denomenator;
                newfraction.numerator = (first.numerator * second.denomenator) + (second.numerator * first.denomenator);
            }
            newfraction.Reduce();
            newfraction.Divide();
            return newfraction;
            
        }
        //Overloaded operator * multiplies denom together and cross multiplies
        //original denominator and numerators
        public static Fraction operator *(Fraction first, Fraction second)
        {
            Fraction newfraction = new Fraction();
            newfraction.denomenator = (first.denomenator * second.denomenator);
            newfraction.numerator = (first.numerator * second.numerator);
            newfraction.Reduce();
            newfraction.Divide();
            return newfraction;
        }
        //ToString method override outputs the values generated in the overloaded
        //operators back to main function
        public override string ToString ()
        {
            if (wholeNum > 0 && denomenator > 1)
            {
                string fraction = wholeNum + " " + numerator + "/" + denomenator;
                return fraction;
            }
            else if (denomenator == 0)
            {
                string fraction1 = Convert.ToString(wholeNum);
                return fraction1;
            }
            else
            {
                return numerator + "/" + denomenator;
            }
        }

    }

}
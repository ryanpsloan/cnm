// CIS1280 - Ivonne Nelson
// Ryan Sloan, rsloan2@cnm.edu
// SloanP4/Program.cs
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SloanP4
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Ryan Sloan");
            Console.WriteLine("Fraction Calculator");
            Console.WriteLine("Objective: Using Objects");
            Console.WriteLine();
            string response;
            Console.WriteLine("Welcome to the fraction calculator.");
            do
            {
                Console.WriteLine("Enter your first fraction.");
                Fraction fraction = new Fraction();
                Console.Write("Enter the whole number, if any: ");
                fraction.WholeNum = Convert.ToInt32(Console.ReadLine());
                Console.Write("Enter the numerator:  ");
                fraction.Numerator = Convert.ToInt32(Console.ReadLine());
                Console.Write("Enter the denomenator:  ");
                fraction.Denomenator = Convert.ToInt32(Console.ReadLine());
                fraction.Reduce();
                Console.WriteLine("Your first fraction is {0}/{1}", fraction.Numerator, fraction.Denomenator);
                Console.WriteLine();
                Console.WriteLine("Now for your second fraction.");
                Fraction fraction2 = new Fraction();
                Console.Write("Enter the whole number, if any:  ");
                fraction2.WholeNum = Convert.ToInt32(Console.ReadLine());
                Console.Write("Enter the numerator:  ");
                fraction2.Numerator = Convert.ToInt32(Console.ReadLine());
                Console.Write("Enter the denomenator:  ");
                fraction2.Denomenator = Convert.ToInt32(Console.ReadLine());
                fraction2.Reduce();
                Console.WriteLine("Your second fraction is {0}/{1}", fraction2.Numerator, fraction2.Denomenator);
                Console.WriteLine();
                Console.Write("Would you like to add or multiply the fractions? +/*  ");
                string answer;
                answer = Console.ReadLine();
                Fraction fraction3 = new Fraction();
                if (answer == "+")
                {
                    fraction3 = fraction + fraction2;
                }
                if (answer == "*")
                {
                    fraction3 = fraction * fraction2;
                }
                Console.WriteLine("{0} is the result", fraction3.ToString());
                Console.WriteLine();
                Console.WriteLine("Would you like to work with another set of fractions? yes/no ");
                response = Console.ReadLine();
            } while (response == "yes");
        }
    }
}

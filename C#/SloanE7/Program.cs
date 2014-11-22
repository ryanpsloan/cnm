using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SloanE7
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Ryan Sloan");
            Console.WriteLine("Exercise 7");
            Console.WriteLine("Handling Exceptions");
            Console.WriteLine();
            
            CarInsurance ci = new CarInsurance();
            double premium;
            try
            {
                Console.Write("Enter Your Age: ");
                ci.DriversAge = Convert.ToInt32(Console.ReadLine());
                if (ci.DriversAge < 16 || ci.DriversAge > 80)
                {
                    throw(new ArgumentException());
                }
            }
            catch (ArgumentException ae)
            {
                Console.WriteLine("Your Age must be between 16 and 80.");
                Console.WriteLine(ae.Message);
            }
            catch (FormatException fe)
            {
                Console.WriteLine("You did not enter an integer.");
                Console.WriteLine(fe.Message);
            }
            try
            {
                Console.Write("Enter Your State of Residence: ");
                ci.StateOfResidence = Console.ReadLine();
                if (ci.StateOfResidence != "IL" && ci.StateOfResidence != "WI")
                {
                    throw (new ArgumentException());
                }
            }
            catch (ArgumentException ae2)
            { 
                Console.WriteLine("You MUST live within the state of Wisconsin or Illinois");
                Console.WriteLine(ae2.Message);
            }

            premium = ci.PremiumCalc();
            Console.WriteLine("Your Premium is ${0}", premium);

        }
    }
}

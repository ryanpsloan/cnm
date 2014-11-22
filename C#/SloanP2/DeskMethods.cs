// CIS1280
// Ryan Sloan - rsloan2@cnm.edu
// SloanP2/DeskMethods.cs

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SloanP2
{
    class DeskMethods
    {
        static void Main(string[] args)
        {
            //Declare Variables
            int numDrawers;
            string woodType;
            double deskCost;
            string answer;     

            //Intro
            Console.WriteLine("Ryan Sloan");
            Console.WriteLine("Desk Methods");
            Console.WriteLine("Objective: Using Methods");
            Console.WriteLine();
            
            //The first step is output to the user
            Console.WriteLine("**Welcome to Desk Methods**");
            Console.WriteLine();

            do // do loop to allow multiple orders
            {
                Console.WriteLine("Let's customize your desk.");
                numDrawers = Drawers(); //method 1 - this method call gets the number of drawers as an int
                woodType = Wood(); //method 2 - this method collects the wood type as a string
                deskCost = Calc(numDrawers,woodType); //method 3 - this method calculates the cost of the desk
                Display(numDrawers, woodType, deskCost); //method 4 - this method displays the results
                Console.Write("Would you like to place another order? ");
                answer = Console.ReadLine();
                Console.WriteLine();
            } while (answer == "Yes" || answer == "yes" || answer == "YES" || answer == "Y" || answer == "y");
            Console.WriteLine("Thank You for your order with Desk Methods.");
            Console.WriteLine("Goodbye");
            
        }

        static int Drawers()
        {
            int numDrawers;
            Console.Write("How many drawers do you want? ");
            numDrawers = Convert.ToInt32(Console.ReadLine());    
            return numDrawers;

        }

        static string Wood()
        {
            string woodType;
            Console.Write("What type of wood: Oak, Pine or Mahogany? ");
            woodType = Console.ReadLine();
            return woodType;
        }

        static double Calc(int numDrawers, string woodType)
        {
            double deskCost;
            if (woodType == "Pine" || woodType == "pine" || woodType == "PINE")
            {
                deskCost = 100.00;
            }
            else if (woodType == "Oak" || woodType == "oak" || woodType == "OAK")
            {
                deskCost = 140.00;
            }
            else
            {
                deskCost = 180.00;
            }

            deskCost += numDrawers * 30.00;
            
            return deskCost;
        }

        static void Display(int numDrawers, string woodType, double deskCost)
        {
            Console.WriteLine("");
            Console.WriteLine("You ordered a {0} desk with {1} drawer(s).", woodType, numDrawers);
            Console.WriteLine("The price for your desk is ${0}.", deskCost);
        }

        
    }
}

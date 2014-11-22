// CIS1280 - Ivonne Nelson
// Ryan Sloan, rsloan2@cnm.edu
// SloanQ1/Program.cs
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SloanQ1
{
    class Program
    {
        static void Main(string[] args)
        {   
            //variables
            double mDriven;
            double gUsed;
            string answer;
            //header
            Console.WriteLine("Ryan Sloan");
            Console.WriteLine("Quiz 1");
            Console.WriteLine();
            //Introduction
            Console.WriteLine("Welcome to the Milage Calculator, with a little");
            Console.WriteLine("input from you I will calculate Miles Per Gallon.");
            //Body of the calculation
            do
            {
                Console.WriteLine();
                Console.Write("Please enter the miles driven:  ");
                //catching the miles driven in variable mDriven
                mDriven = Convert.ToDouble(Console.ReadLine());
                Console.WriteLine();
                //catching the gallons used in gUsed
                Console.Write("Please enter the gallons of gasoline used:  ");
                gUsed = Convert.ToDouble(Console.ReadLine());
                Console.WriteLine();
                //Calling a new object, using overloaded parameter constructor to input the values into the class
                Milage milage = new Milage(mDriven, gUsed);
                //Could also call a parameterless constructor and then use property milage.MilesDriven = mDriven
                // and property milage.GallonsUsed = gUsed to input the value of the variables into the class
                   
                //Returning the result of the private mpg in the class from the property Mpg
                Console.WriteLine("The miles per gallon of your vehicle is {0} mpg.", milage.Mpg);
                Console.WriteLine();
                //set answer variable to yes or no to determine if program should repeat
                Console.Write("Would you like to do another calculation? yes/no:  ");
                answer = Console.ReadLine();
            } while (answer == "yes");
            Console.WriteLine();
            Console.WriteLine("Good-bye");
            Console.WriteLine();
        
        }
    }
}

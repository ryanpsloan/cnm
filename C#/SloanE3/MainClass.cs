// CIS 1280 - Ivonne Nelson
// Ryan Sloan
// rsloan2@hotmail.com
// SloanE3

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SloanE3
{
    class MainClass
    {
        static void Main(string[] args)
        {   
            //Header Info
            Console.WriteLine("Ryan Sloan");
            Console.WriteLine("A Better Pizza Class Exercise 3");
            Console.WriteLine("Objective: Using properties");
            Console.WriteLine();
            //The Object declaration
            Paisanos paisanos = new Paisanos();
            //The Menu
            Console.WriteLine("Welcome to Paisanos!!");
            Console.WriteLine("**Paisanos Menu**");
            Console.WriteLine(paisanos.sizestring());
            Console.WriteLine("***Toppings***");
            Console.WriteLine(paisanos.toppingstring());
            Console.WriteLine();
            //Customer input
            Console.Write("Would you like to place an order? ");
            string order = Console.ReadLine();
            while (order == "y" || order == "Y" || order == "yes" || order == "Yes")
            {
                
                Console.Write("What size do you want? ");
                paisanos.Size = Convert.ToInt32(Console.ReadLine()); //Customer can enter actual size or number. Value assigned to property Size
                double basiccost = paisanos.BasicPrice;
                Console.WriteLine("The total for a basic {0} inch pizza is ${1}.", paisanos.Size, basiccost); //outputting size &basic price
                Console.Write("Would you like to add toppings at a dollar per topping? ");
                string ordertop = Console.ReadLine();
                if (ordertop == "y" || ordertop == "Y" || ordertop == "yes" || ordertop == "Yes") //Give customer opportunity to add toppings
                {
                    paisanos.toppingslist.Clear();
                    Console.Write("How many toppings would you like? "); 
                    paisanos.TopNum = Convert.ToInt32(Console.ReadLine()); //Get number of toppings and assign to the property TopNum
                    for (int i = 0; i < paisanos.TopNum; ++i)   //Based on TopNum cycle a loop getting their toppings info
                    {
                        string first = (i + 1).ToString();
                        Console.Write("Topping #{0} is: ", first);
                        paisanos.toppingslist.Add(Console.ReadLine()); //Store the input in the class list
                    }
                }
                else
                {
                    paisanos.TopNum = 0;//if they choose no toppings
                }
                Console.WriteLine();
                double topcost = paisanos.TopCost; //calculate toppings cost with TopNum value
                double totalcost = basiccost + topcost; // add basic and toppings cost together
                Console.WriteLine("Your total for a {0} inch pizza with {1} toppings is ${2}. ",paisanos.Size, paisanos.TopNum, totalcost);//output it
                if (paisanos.TopNum > 0)
                {
                    Console.WriteLine("Your toppings are: ");
                    for (int i = 0; i < paisanos.TopNum; ++i)
                    {
                       Console.WriteLine("{0}  ", paisanos.toppingslist[i]);//output the toppings only if they ordered any.
                    }
                }
                Console.WriteLine();
                Console.Write("Would you like to place another order? "); //update the while condition
                order = Console.ReadLine();
            }
            Console.WriteLine();
            Console.WriteLine("Thank you for your business!");

        }
    }
}

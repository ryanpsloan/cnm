using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SloanE2
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Ryan Sloan");
            Console.WriteLine("Exercise 2");
            Console.WriteLine("Objective: Creating Classes");
            Console.WriteLine();
            Console.WriteLine("Welcome to C# Pizza Palace");
            Console.WriteLine();
            PaisanosPizza pie = new PaisanosPizza();
            Console.WriteLine("Here are our menu options.");
            Console.WriteLine("1. Choose your size.");
            Console.WriteLine(pie.sizestring());
            Console.WriteLine(pie.pricestring());
            Console.WriteLine("2. Choose from any of our toppings add $1.00 for each!");
            Console.WriteLine(pie.toppingstring());
            Console.WriteLine();
            Console.WriteLine("Arrivederci");
            

        }
    }
}

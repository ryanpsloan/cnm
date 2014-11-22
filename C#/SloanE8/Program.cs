using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SloanE8
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Ryan Sloan");
            Console.WriteLine("LINQ");
            Console.WriteLine("Exercise 8");
            Console.WriteLine();
            Invoice[] ObjectArray = new Invoice[8];
            ObjectArray[0] = new Invoice(83,"Electric Sander", 7, 57.98M);
            ObjectArray[1] = new Invoice(24, "Power Saw", 18, 99.99M);
            ObjectArray[2] = new Invoice(7, "Sledge Hammer", 11, 21.50M);
            ObjectArray[3] = new Invoice(77, "Hammer", 76, 11.99M);
            ObjectArray[4] = new Invoice(39, "Lawn Mower", 3, 79.50M);
            ObjectArray[5] = new Invoice(68, "Screwdriver", 106, 6.99M);
            ObjectArray[6] = new Invoice(56, "Jig Saw", 21, 11.00M);
            ObjectArray[7] = new Invoice(3, "Wrench", 34, 7.50M);
            Console.WriteLine("Here is the data sorted by Part Description");
            Console.WriteLine();
            Console.WriteLine("Part#, Description, Quantity, Price");
            var invoices =
                from i in ObjectArray
                orderby i.PartDescription
                select i;
            foreach (var i in invoices)
                Console.WriteLine("{0,-5} {1,-20} {2,-5} {3,6:C}", i.PartNumber,
                    i.PartDescription, i.Quantity, i.Price);
                        Console.WriteLine();
            
            Console.WriteLine("Here is the data sorted by Price");
            Console.WriteLine();
            Console.WriteLine("Part#, Description, Quantity, Price");
            var invoices2 =
                from i in ObjectArray
                orderby i.Price
                select i;
            foreach (var i in invoices2)
                Console.WriteLine("{0,-5} {1,-20} {2,-5} {3,6:C}", i.PartNumber,
                    i.PartDescription, i.Quantity, i.Price);
            Console.WriteLine();
            
            Console.WriteLine("Here is the data sorted by Quantity");
            Console.WriteLine();
            Console.WriteLine("Part#, Description, Quantity, Price");
            var invoices3 =
                from i in ObjectArray
                orderby i.Quantity
                select i;
            foreach (var i in invoices3)
                Console.WriteLine("{0,-5} {1,-20} {2,-5} {3,6:C}", i.PartNumber,
                    i.PartDescription, i.Quantity, i.Price);
            Console.WriteLine();

            Console.WriteLine("Here is the data with a new column");
            Console.WriteLine();
            Console.WriteLine("Part#, Description, Quantity, Price, InvoiceTotal");
            var invoices4 =
                from i in ObjectArray 
                let x = i.Quantity * i.Price
                select i;
            foreach (var i in invoices4)
                Console.WriteLine("{0,-5} {1,-20} {2,-5} {3,6:C} {4,8:C}", i.PartNumber,
                    i.PartDescription, i.Quantity, i.Price, i.Quantity * i.Price );
            Console.WriteLine();

            Console.WriteLine("Here is the final results");
            Console.WriteLine();
            Console.WriteLine("Part#, Description, Quantity, Price, InvoiceTotal");
            var invoices5 =
                from i in ObjectArray
                let x = i.Price * i.Quantity
                where x >= 200 && x <= 500
                select i;
            foreach (var i in invoices5)
                Console.WriteLine("{0,-5} {1,-20} {2,-5} {3,6:C} {4,8:C}", i.PartNumber,
                    i.PartDescription, i.Quantity, i.Price, i.Quantity * i.Price);
            Console.WriteLine();

            
            
        }
    }
}

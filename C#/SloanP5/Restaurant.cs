// CIS1280 - Ivonne Nelson
// Ryan Sloan, rsloan2@cnm.edu
// Restaurant.cs

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SloanP5
{
    public class Restaurant
    {
         
        private string[] salads = { "Spinach Salad $11.99", "Grilled Chicken Salad $12.99", "Greek Salad $11.99", "Antipasto Platter $14.99" };
        private string[] pastas = { "Meat Lasagna $12.99", "Baked Ziti $11.99", "Eggplant Parmigiana $13.99", "Spagetti & Meatballs $10.99" };
        private string[] chicken = { "Chicken Parmisaigna $16.99", "Chicken Francese $16.99", "Chicken Milanese $16.99", "Chicken Florentina $17.99" };
        private string[] seafood = { "Zuppa di Pesce $22.99", "Gamberoni Scampi $19.99", "Salmon Bruschetta $17.99", "Mussels Marinara $16.99" };

        private double[,] foodprices =   {{11.99,12.99,11.99,14.99},
                                          {12.99,11.99,13.99,10.99},
                                          {16.99,16.99,16.99,17.99},
                                          {22.99,19.99,17.99,16.99}};
       
        private int[,] orders = {   { 0, 0, 0, 0 },
                                    { 0, 0, 0, 0 },
                                    { 0, 0, 0, 0 },
                                    { 0, 0, 0, 0 }};

        private int[] bev = { 0, 0, 0, 0, 0, 0, 0, 0 };
        private double[] bevPrices = { 1.75, 1.75, 1.25, 1.25, 6.00, 4.50, 1.50, 2.00 };
        private double totalprice = 0.00;
        private double entreetotal = 0.00;
        private double drinktotal = 0.00;

        public string[] Salads
        {
            get { return salads; }
        }
        public string[] Pastas
        {
            get { return pastas; }
        }
        public string[] Chicken
        {
            get { return chicken; }
        }
        public string[] Seafood
        {
            get { return seafood; }
        }

        private int saladindex;
        public int SaladIndex
        {
            set
            {
                saladindex = value;
                Increment(0,saladindex);
            }
        }

        private int pastaindex;
        public int PastaIndex
        {
            set
            {
                pastaindex = value;
                Increment(1,pastaindex);
            }
        }

        private int chickenindex;
        public int ChickenIndex
        {
            set
            {
                chickenindex = value;
                Increment(2,chickenindex);
            }
        }

        private int seafoodindex;
        public int SeafoodIndex
        {
            set
            {
                seafoodindex = value;
                Increment(3,seafoodindex);
            }
        }

        private PizzaClass pizza = new PizzaClass();
        public PizzaClass Pizza
        {
            get { return pizza; }
            set { pizza = value; Calculate(); }
        }
        
        private void Increment(int index, int comboindex)
        {
            orders[index,comboindex] += 1;
            Calculate();
        }
        
        public void Bev(int index)
        {
            bev[index] += 1;
            Calculate();
        }

       
        private void Calculate()
        {
            for (int i = 0; i < 4; ++i)
                {
                    for (int j = 0; j < 4; ++j)
                    {
                        double price = orders[i, j] * foodprices[i, j];
                        if (price > 0)
                        {
                            orders[i, j]--;
                            entreetotal += price;
                        }
                    }
                }
            

           
          
            for (int k = 0; k < 8; ++k)
                {
                    double price = bev[k] * bevPrices[k];
                    if (price > 0)
                    {
                        bev[k]--;
                        drinktotal += price;
                    }
                }
           


            totalprice = entreetotal + drinktotal + pizza.TotalPrice;    
        }

        public override string ToString()
        {
            string output = "";

            if (entreetotal > 0.00)
                output += "Your Food Total is $" + entreetotal + "\n";
            if (drinktotal > 0.00)
                output += "Your Drink Total is $" + drinktotal + "\n";
            if (pizza.TotalPrice > 0.00)
                output += "Your Pizza Total is $" + pizza.TotalPrice + "\n";
            output += "\nYour Total is $" + totalprice + "\n";
            return output;
        }
       
    }
}

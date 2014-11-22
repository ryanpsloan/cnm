using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SloanE2
{
    public class PaisanosPizza
    {
        private string[] toppings = { "Extra Cheese", "Black Olives", "Jalepenos", "Pineapple" };
        private int[] size = {12, 14, 16};
        private double[] price = {7.99, 10.99, 12.99};


        public string toppingstring()
        { 
            string topping = "";
            foreach(string top in toppings)
                topping = topping + top + "  ";

            return topping;
        }

        public string sizestring()
        { 
            string asize = "";
            foreach(int bsize in size)
                asize = asize + bsize.ToString() + " inch ";
            
            return asize;
        }

        public string pricestring()
        {
            string prices = "";
            foreach (double p in price)
                prices = prices + "$" + p.ToString() + "   ";

            return prices;
        }
    }
}
        
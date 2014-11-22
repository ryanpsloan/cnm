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
    class Paisanos //The Class
    {
        //Three Arrays declared and initialized along with a List Object
        private string[] toppings = {"Extra Cheese","Pepperoni", "Mushrooms", "Black Olives", "Pineapple", "Green Chile" };
        private int[] size = { 10, 12, 14 };
        private double[] price = {10.99, 12.99, 14.99};
        public List<string> toppingslist = new List<string>();
                 
        //This method outputs the values found in the topping array.
        public string toppingstring()
        { 
            string topping = "";
            for (int i = 0; i < toppings.Length; ++i)
                 topping += (i + 1).ToString() + ". " + toppings[i].ToString() + "\n";

            return topping;
        }

        //This method outputs the values found in the size array
        public string sizestring()
        { 
            string asize = "";
            for (int i = 0; i < size.Length; ++i)
            {
                asize += (i + 1).ToString() + ". " + size[i].ToString() + " inch " + "$" + price[i].ToString() + "\n"; 
            }
                   
            return asize;
        }

        //This method outputs the values found in the price array
        public string pricestring()
        {
            string prices = "";
            for (int i = 0; i < price.Length; ++i)
            {
                prices += price[i].ToString() + " ";
            }
            return prices;
        }

        //This property is assigned the value of the the size when the customer orders 
        private int sizeVar;
        public int Size 
        { 
            get
            { 
                return sizeVar; 
            }
            set
            {
                sizeVar = value;
                pricereturn(sizeVar);
            }
        }
        //This method returns the cost of the basic pizza
        double basicPrice = 1;
        public double BasicPrice
        {
            get 
            {
                return basicPrice;
            }

        }

        //This method determines via evaluation of Size the cost of the basic order before toppings.
        private void pricereturn(int Size)
        {
            
            if (Size == 10 || Size == 1)
            {
                basicPrice = price[0];
                sizeVar = 10; //In case they inputted 1 as their size option from the menu I 
                           //change Size back to 10 because I use it for output later in the program
            }
            else if (Size == 12 || Size == 2)
            {
                basicPrice = price[1];
                sizeVar = 12;
            }
            else if (Size == 14 || Size == 3)
            {
                basicPrice = price[2];
                sizeVar = 14;
            }
            
        }
        //If a customer chooses toppings, this property holds the int value of the number they chose
        int topNum = 1;
        public int TopNum 
        { 
            get
            {
                return topNum;
            }
            set
            {
                topNum = value;
                toppingscost(topNum);
            }
        }
        
        //This property returns the calculated cost of the toppings.
        double topCost = 1;
        public double TopCost
        {
            get
            {
                return topCost;
            }
        }
        
        //This method calculates the cost of the toppings and outputs it to the property TopCost
        private void toppingscost(int TopNum)
        {
            topCost = TopNum * 1.00;            
        }
    }
}

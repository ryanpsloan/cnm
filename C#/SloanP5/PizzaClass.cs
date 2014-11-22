using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SloanP5
{
    public class PizzaClass
    {
        //List Object
      
        public List<string> toppingslist = new List<string>(); //interfaces with 
        //the form to get the toppings list
                 
       //This property is assigned the value of the the size from the form 
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
        
        private double basicPrice = 1;
        //This method determines via evaluation of Size the cost of the basic order before toppings.
        private void pricereturn(int Size)
        {
            
            if (Size == 10 || Size == 1)
            {
                basicPrice = 10.99;
            }
            else if (Size == 12 || Size == 2)
            {
                basicPrice = 12.99;
            }
            else if (Size == 14 || Size == 3)
            {
                basicPrice = 14.99;               
            }
            priceCalc();
        }

        //Interfaces with the form to get the topping count
        private int topNum = 1;
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
        
        private double topCost = 1;
        //This method calculates the cost of the toppings and outputs it to the property TopCost
        private void toppingscost(int TopNum)
        {
            topCost = TopNum * 1.00;
            priceCalc();
        }
    
        //Based on the inputted index from the form, this property assigns the cost to a 
        //variable and the type of crust to a string
        int crustIndex;
        private string crusttype;
        private double crustPrice;
        public int Crust
        {
            get
            {
                return crustIndex; 
            }
            set
            {
                crustIndex = value;
                if (crustIndex == 0)
                {
                    crusttype = "Thin-Crust";
                    crustPrice = 0;
                }
                if (crustIndex == 1)
                { 
                    crusttype = "Thick-Crust";
                    crustPrice = 1.00;
                }
                if (crustIndex == 2)
                { 
                    crusttype = "Hand-Tossed Crust";
                    crustPrice = 2.00;
                }
                priceCalc();
            }
        }


        //This method calculates the total cost of the pizza
        private double totalPrice;
        public double TotalPrice
        {
            get
            {
                return totalPrice;
            }
            set
            {
                totalPrice = value;
            }
        }

        private double priceCalc()
        {
            
            totalPrice = topCost + basicPrice + crustPrice;
            return totalPrice;
        }
        
        // Converts toppingslist from a list into a string.       
        private string toppingsstring()
        {
            string stoppings = "";
            for (int i = 0; i < TopNum; ++i)
            {
                stoppings += " " + toppingslist[i] + " ";
            }
                return stoppings;
        }
        //ToString Override
        public override string ToString()
        {
            string final;
            final = "The cost for a " + Size.ToString() + " inch pizza with " + crusttype
                + " and" + toppingsstring() + " is " + "$" + priceCalc() + ".";
            
            return final;
        }
    }
}
    


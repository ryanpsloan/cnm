// Ryan Sloan, rsloan2@cnm.edu
// SloanP1 - Lottery Game

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SloanP1
{
    class LotteryGame
    {
        static void Main(string[] args)
        {
            
            //Initial Printout
            Console.WriteLine("Ryan Sloan");
            Console.WriteLine("Lottery Game");
            Console.WriteLine("Guess the Hidden Numbers");
            Console.WriteLine();
            //Variable Initialization
            int score = 0;
            bool exit = false;
            //Array for clues.
            string[] clue = new string[12]  { "go with your gut.",
                                              "follow your heart.",
                                              "use the Force.",
                                              "go for 1.",
                                              "try 2.",
                                              "3 sounds good.",
                                              "try using 4.",
                                              "I recommend 1.",
                                              "use 2.",
                                              "go with 3.",
                                              "you might try 4.",
                                              "repeat a number." };

            
            //Welcome Statement
            Console.WriteLine("Welcome to Guess the Hidden Numbers!");
            Console.WriteLine();
            Console.WriteLine("Hello and Welcome. First off let's outline the game. ");
            Console.WriteLine("I will choose three times from the numbers 1,2,3 or 4.");
            Console.WriteLine("Sometimes the numbers I choose are different and sometimes");
            Console.WriteLine("I pick the same number twice or even three times.");
            Console.WriteLine("You get points for every number that you guess correctly.");
            Console.WriteLine("You get 10 points for one match, 100 points for two matches,");
            Console.WriteLine("1,000 points for three and if you guess all three numbers");
            Console.WriteLine("in the matching order you get... 10,000 points!");
            Console.WriteLine("I will give you some hints along the way.");
            Console.WriteLine("So Let's Play!");
            Console.WriteLine();
           
            //Game Loop
            while (exit == false)
            {
                //Score
                
                Console.WriteLine("Your initial score is {0}", score);
                Console.WriteLine();

                //Random Number Generation
                Random randomNumGen = new Random();
                int number1 = randomNumGen.Next(1, 5);
                int number2 = randomNumGen.Next(1, 5);
                int number3 = randomNumGen.Next(1, 5);
                Console.WriteLine("Okay, I've picked.");
                Console.WriteLine();

                //Uncomment this line to cheat and see the generated numbers before picking
               /* Console.WriteLine("For Testing Purposes only. {0}{1}{2}", number1, number2, number3); */

                //Clue generation
                int x = randomNumGen.Next(0, 11);
                //User guesses as input
                Console.Write("Guess a number, {0} (1-4) ",clue[x]);
                int guess1 = Convert.ToInt32(Console.ReadLine());
                //randomNumGen set to 12 to include the final element in the array. I didn't want it appearing in the first go round.
                x = randomNumGen.Next(0, 12);
                Console.Write("Now try another number, {0} (1-4) ", clue[x]);
                int guess2 = Convert.ToInt32(Console.ReadLine());
                x = randomNumGen.Next(0, 12);
                Console.Write("And guess your final number, {0} (1-4) ",clue[x]);
                int guess3 = Convert.ToInt32(Console.ReadLine());

                //More output to the screen
                Console.WriteLine();
                Console.WriteLine("Let's see how you did.");
                Console.Write("{0}, {1}, {2} were the numbers you guessed.", guess1, guess2, guess3);
                Console.WriteLine();
                Console.WriteLine("{0}, {1}, {2} were the numbers I picked.", number1, number2, number3);

                //Evaluation Statements
                // Checking to see if got the gold.
                int match = 0;
                if (number1 == guess1 && number2 == guess2 && number3 == guess3)
                {
                    Console.WriteLine("You guessed all three!!! Congratulations");
                    match = 4;
                }
                else
                {
                    // Comparing the first number against all three guesses.
                    if (number1 == guess1)
                    {
                        Console.WriteLine("You matched {0} and {1}", number1, guess1);
                        ++match;
                        guess1 = 0;
                    }
                    else if (number1 == guess2)
                    {
                        Console.WriteLine("You matched {0} and {1}", number1, guess2);
                        ++match;
                        guess2 = 0;
                    }
                    else if (number1 == guess3)
                    {
                        Console.WriteLine("You matched {0} and {1}", number1, guess3);
                        ++match;
                        guess3 = 0;
                    }
                    //Comparing the second number against all three guesses;
                    if (number2 == guess1)
                    {
                        Console.WriteLine("You matched {0} and {1}", number2, guess1);
                        ++match;
                        guess1 = 0;
                    }
                    else if (number2 == guess2)
                    {
                        Console.WriteLine("You matched {0} and {1}", number2, guess2);
                        ++match;
                        guess2 = 0;
                    }
                    else if (number2 == guess3)
                    {
                        Console.WriteLine("You matched {0} and {1}", number2, guess3);
                        ++match;
                        guess3 = 0;
                    }
                    //Compares number 3 against all three guesses.
                    if (number3 == guess1)
                    {
                        Console.WriteLine("You matched {0} and {1}", number3, guess1);
                        ++match;
                        guess1 = 0;
                    }
                    else if (number3 == guess2)
                    {
                        Console.WriteLine("You matched {0} and {1}", number3, guess2);
                        ++match;
                        guess2 = 0;
                    }
                    else if (number3 == guess3)
                    {
                        Console.WriteLine("You matched {0} and {1}", number3, guess3);
                        ++match;
                        guess3 = 0;
                    }
                }
                //Evaluation for Scoring 
                if (match == 1)
                {
                    score += 10;
                }
                else if (match == 2)
                {
                    score += 100;
                }
                else if (match == 3)
                {
                    score += 1000;
                }
                else if (match == 4)
                {
                    score += 10000;
                }

                char replay;
                Console.WriteLine("Your Final Score is {0}", score);
                Console.Write("Play Again? Y/N");
                replay = Convert.ToChar(Console.ReadLine());
                if (replay == 'y' || replay == 'Y')
                {
                    Console.WriteLine();
                    Console.WriteLine("Here we go!");
                    Console.WriteLine();
                }
                else
                {
                    Console.WriteLine();
                    Console.WriteLine("Thanks for Playing!");
                    exit = true;
                }
            }
            Console.WriteLine();
            Console.WriteLine("GAME OVER");       
                    
        } 
    }                
}                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                  
            
            
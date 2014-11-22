using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SloanE4
{
    class Students
    {
        static void Main(string[] args)
        {
            Student first = new Student();
            Student second = new Student();
            Student third = new Student(456, "Marco", 2.4);
            Student fourth = new Student();
            first.IdNumber = 123;
            first.LastName = "Anderson";
            first.GradePointAverage = 3.5;
            second.IdNumber = 789;
            second.LastName = "Daniels";
            second.GradePointAverage = 4.1;

            Display(first);
            Display(second);
            Display(third);
            Display(fourth);
        }

        internal static void Display(Student stu)
        { 
            Console.WriteLine("{0,5} {1,-10} {2,6}", stu.IdNumber, stu.LastName, stu.GradePointAverage.ToString("F1"));
        }
    }

}

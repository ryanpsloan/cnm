using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SloanE4
{
    class Student
    {
        private double gradePointAverage;
        public const double HIGHEST_GPA = 4.0;
        public const double LOWEST_GPA = 0.0;

        public int IdNumber { get; set; }
        public string LastName { get; set; }
        

        public double GradePointAverage
        {
            get
            {
                return gradePointAverage;
            }
            set
            {
                if (value >= LOWEST_GPA && value <= HIGHEST_GPA)
                    gradePointAverage = value;
                else
                    gradePointAverage = LOWEST_GPA;
            }
        }

        public Student(int id, string name, double gpa)
        {
            IdNumber = id;
            LastName = name;
            GradePointAverage = gpa;
        }

        public Student(): this(0, "XXX", 0.0)
        { }
    
    }
}

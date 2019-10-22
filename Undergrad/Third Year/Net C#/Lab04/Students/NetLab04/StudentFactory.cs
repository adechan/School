using System;
using System.Collections.Generic;
using System.Text;

namespace NetLab4
{
    public class StudentFactory
    {
        public Student[] Create()
        {
            Student[] studentArray =
            {
                new Student { StudentId = 1, StudentName = "John", Age = 18 } ,
                new Student { StudentId = 2, StudentName = "Steve", Age = 21 } ,
                new Student { StudentId = 3, StudentName = "Bill", Age = 25 } ,
                new Student { StudentId = 4, StudentName = "Ram", Age = 20 } ,
                new Student { StudentId = 5, StudentName = "Ron", Age = 23 } ,
                new Student { StudentId = 6, StudentName = "Chris", Age = 17 } ,
                new Student { StudentId = 7, StudentName = "Rob", Age = 19 } ,
                new Student { StudentId = 8, StudentName = "Jan", Age = 16 } ,
                new Student { StudentId = 9, StudentName = "Job", Age = 17 } ,
                new Student { StudentId = 10, StudentName = "Steven", Age = 20 } ,

            };

            return studentArray;
        }
    }
}

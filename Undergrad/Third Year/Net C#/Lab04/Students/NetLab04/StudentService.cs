using System;
using System.Collections.Generic;
using System.Text;

namespace NetLab4
{
    public abstract class StudentService
    {
        public abstract Student[] GetStudentsOlderThan19();
        public abstract Student[] GetStudentsBetween18And22();
        public abstract int CountStudentsThatContainInNameJ();
        public abstract int CountStudentsThatContainInNameI();

        public abstract Student[] GetStudentsWithAge17();

    }
}

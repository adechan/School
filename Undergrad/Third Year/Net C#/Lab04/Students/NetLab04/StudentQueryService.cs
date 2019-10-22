
using System;
using System.Linq;

namespace NetLab4
{
    public class StudentQueryService : StudentService
    {
        public StudentQueryService(Student[] students)
        {
            this.Students = students;
        }
        public Student[] Students { get; }
        public override Student[] GetStudentsOlderThan19()
        {
            var result = from student in this.Students
                         where student.Age > 19
                         select student;

            return result.ToArray();
        }

        public override Student[] GetStudentsBetween18And22()
        {
            var result = this.Students.Where(student => student.Age >= 18 && student.Age <= 22);
            return result.ToArray();
        }

        public override int CountStudentsThatContainInNameJ()
        {
            var result = (from student in this.Students
                          where student.StudentName.Contains('J')
                          select student).Count();

            return Convert.ToInt32(result.ToString());
        }

        public override int CountStudentsThatContainInNameI()
        {
            var result = (from student in this.Students
                          where student.StudentName.Contains('I')
                          select student).Count();

            return Convert.ToInt32(result.ToString());
        }

        public override Student[] GetStudentsWithAge17()
        {
            var result = from student in this.Students
                         where student.Age == 17
                         select student;

            return result.ToArray();
        }
    }
}

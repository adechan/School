using System.Linq;

namespace NetLab4
{
    public class StudentMethodService : StudentService
    {
        private Student[] Students { set; get; }
        public StudentMethodService(Student[] students)
        {
            this.Students = students;
        }

        public override Student[] GetStudentsOlderThan19()
        {
            var result = Students.Where(student => student.Age > 19);

            return result.ToArray();
        }

        public override Student[] GetStudentsBetween18And22()
        {
            var result = Students.Where(student => student.Age >= 18).Where(student => student.Age <= 22);
            return result.ToArray();
        }

        public override int CountStudentsThatContainInNameJ()
        {
            int result = Students.Where(student => student.StudentName.Contains('J')).Count();

            return result;
        }

        public override int CountStudentsThatContainInNameI()
        {
            int result = Students.Where(student => student.StudentName.Contains('I')).Count();

            return result;
        }

        public override Student[] GetStudentsWithAge17()
        {
            var result = Students.Where(student => student.Age == 17);

            return result.ToArray();
        }
    }
}

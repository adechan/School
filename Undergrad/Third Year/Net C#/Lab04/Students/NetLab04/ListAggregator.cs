

using System.Linq;

namespace NetLab4
{
    public class ListAggregator
    {
        private Student[] students { get; set; }
        public ListAggregator(Student[] students)
        {
            this.students = students;
        }

        public Student[] Agregate(Student[] newList)
        {
            students.Union(newList);
            return students;
        }
    }
}

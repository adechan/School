
using NetLab4;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace NetLab4
{
    [TestClass]
    class ListAggregatorTests
    {
        [TestMethod]
        void Aggregate_Expects()
        {
            Student[] students = new StudentFactory().Create();
            ListAggregator aggregator = new ListAggregator(students);
            Student[] newStudentList = { new Student { StudentId = 1, StudentName = "Andreea", Age = 18 } };
            newStudentList = aggregator.Agregate(newStudentList);

            Assert.AreEqual(students.Length + 1, newStudentList.Length);
        }
    }
}

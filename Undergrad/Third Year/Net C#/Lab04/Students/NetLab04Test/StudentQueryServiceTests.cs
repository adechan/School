using System;
using NetLab4;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace NetLab4
{
    [TestClass]
    public class StudentQueryServiceTests
    {
        [TestMethod]

        public void GetStudentBetweenAge19And22_StudentsBetweenAgeAnd22_True()
        {
            Student[] studentArray = {

                new Student() { StudentId = 1, StudentName = "John", Age = 17 } ,
                new Student() { StudentId = 4, StudentName = "Ram", Age = 20 }
            };

            StudentQueryService studentMethodService = new StudentQueryService(studentArray);
            var filteredList = studentMethodService.GetStudentsBetween18And22();
            Boolean result = filteredList.Length == 1 && filteredList[0].StudentName.Equals("Ram");

            Assert.IsTrue(result);

        }

        [TestMethod]
        public void GetStudentsOlderThan19_StudentsOlderThan19_True()
        {
            Student[] studentArray = {

                new Student() { StudentId = 1, StudentName = "John", Age = 17 } ,
                new Student() { StudentId = 4, StudentName = "Ram", Age = 20 }
            };

            StudentQueryService studentMethodService = new StudentQueryService(studentArray);
            var filteredList = studentMethodService.GetStudentsOlderThan19();
            Boolean result = filteredList.Length == 1 && filteredList[0].StudentName.Equals("Ram");

            Assert.IsTrue(result);
        }

        [TestMethod]
        public void CountStudentsThatContainInNameJ_StudentsThatContainsJ_Equal_1()
        {
            Student[] studentArray =
            {

                new Student() {StudentId = 1, StudentName = "John", Age = 17},
                new Student() {StudentId = 4, StudentName = "Ram", Age = 20}
            };

            StudentQueryService studentMethodService = new StudentQueryService(studentArray);
            var filteredList = studentMethodService.CountStudentsThatContainInNameJ();


            Assert.AreEqual(1, filteredList);
        }

        [TestMethod]
        public void CountStudentsThatContainInNameI_StudentsThatContainsI_Equal_1()
        {
            Student[] studentArray =
            {

                new Student() {StudentId = 1, StudentName = "Ian", Age = 17},
                new Student() {StudentId = 4, StudentName = "Ram", Age = 20}
            };

            StudentQueryService studentMethodService = new StudentQueryService(studentArray);
            var filteredList = studentMethodService.CountStudentsThatContainInNameI();


            Assert.AreEqual(1, filteredList);
        }

        [TestMethod]
        public void GetStudentsWithAge17_StudentsThatHaveAge17_Equal_1()
        {
            Student[] studentArray =
            {

                new Student() {StudentId = 1, StudentName = "Ian", Age = 17},
                new Student() {StudentId = 4, StudentName = "Ram", Age = 20}
            };

            StudentQueryService studentMethodService = new StudentQueryService(studentArray);
            var filteredList = studentMethodService.GetStudentsWithAge17();

            Boolean result = filteredList.Length == 1 && filteredList[0].StudentName.Equals("Ian");

            Assert.AreEqual("Ian", filteredList[0].StudentName);
        }
    }
}



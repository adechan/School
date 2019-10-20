using System;
using NetLab3;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace NetLab3Test
{
    [TestClass]
    public class ArchitectTest
    {

        [TestMethod]
        public void GivenNewArchitect_WhenGettingFullName()
        {
            // Arrange 
            Architect architect = new Architect("Shaun", "Ostoic", new DateTime(2019, 06, 29),
               new DateTime(2019, 09, 30), 3000);

            // Act
            string fullName = architect.GetFullName();

            // Assert
            Assert.AreEqual("Shaun Ostoic", fullName);
        }

        [TestMethod]
        public void GiveNewArchitect_WhenSalute_ThenSalute()
        {
            // Arrange 
            Architect architect = new Architect("Shaun", "Ostoic", new DateTime(2019, 06, 29),
               new DateTime(2019, 09, 30), 3000);

            // Act
            string salutation = architect.Salutation();

            // Assert
            Assert.AreEqual("Hello architect, Shaun Ostoic", architect.Salutation());
        }

        [TestMethod]
        public void GivenNewArchitect_WhenStartDate2019_ThenStartDate2019()
        {
            // Arrange 
            Architect architect = new Architect("Shaun", "Ostoic", new DateTime(2019, 06, 29),
               new DateTime(2019, 09, 30), 3000);

            // Act
            DateTime date = architect.startDate;
            // Assert
            Assert.AreEqual(new DateTime(2019, 06, 29), date);

        }

        [TestMethod]
        public void GivenNewArchitect_WhenEndDate2019_ThenEndDate2019()
        {
            // Arrange 
            Architect architect = new Architect("Shaun", "Ostoic", new DateTime(2019, 06, 29),
               new DateTime(2019, 09, 30), 3000);

            // Act
            DateTime date = architect.endDate;
            // Assert
            Assert.AreEqual(new DateTime(2019, 09, 30), date);
        }

        [TestMethod]
        public void GivenNewArchitect_WhenLastNameOstoic_ThenLastNameOstoic()
        {
            // Arrange 
            Architect architect = new Architect("Shaun", "Ostoic", new DateTime(2019, 06, 29),
               new DateTime(2019, 09, 30), 3000);

            // Act
            string lastName = architect.lastName;

            // Assert
            Assert.AreEqual("Ostoic", lastName);
        }


        [TestMethod]
        public void GivenNewArchitect_WhenSalary3000_ThenSalary3000()
        {
            // Arrange 
            Architect architect = new Architect("Shaun", "Ostoic", new DateTime(2019, 06, 29),
               new DateTime(2019, 09, 30), 3000);

            // Act
            int salary = architect.salary;

            // Assert
            Assert.AreEqual(3000, salary);
        }
    }
}

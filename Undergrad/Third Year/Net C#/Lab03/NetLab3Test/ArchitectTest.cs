using System;
using NetLab3;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace NetLab3Test
{
    [TestClass]
    public class ArchitectTest
    {
        [TestMethod]
        public void TestMethod1()
        {
            // Arrange 
            Architect architect = new Architect("Shaun", "Ostoic", new DateTime(2019, 06, 29),
               new DateTime(2019, 09, 30), 3000);

            // Act
            string name = architect.firstName;
            string fullName = architect.GetFullName();

            // Assert
            Assert.AreEqual("Shaun", architect.firstName);
            Assert.AreEqual("Ostoic", architect.lastName);
        }

        [TestMethod]
        public void TestMethod2()
        {
            // Arrange 
            Architect architect = new Architect("Shaun", "Ostoic", new DateTime(2019, 06, 29),
               new DateTime(2019, 09, 30), 3000);

            // Act
            string fullName = architect.GetFullName();

            // Assert
            Assert.AreEqual("Shaun Ostoic", architect.GetFullName());
        }

        [TestMethod]
        public void TestMethod3()
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
        public void TestMethod4()
        {
            // Arrange 
            Architect architect = new Architect("Shaun", "Ostoic", new DateTime(2019, 06, 29),
               new DateTime(2019, 09, 30), 3000);

            // Act
            string name = architect.firstName;
            string fullName = architect.GetFullName();

            // Assert
            Assert.AreEqual(new DateTime(2019, 06, 29), architect.startDate);
            Assert.AreEqual(new DateTime(2019, 09, 30), architect.endDate);
        }

        [TestMethod]
        public void TestMethod5()
        {
            // Arrange 
            Architect architect = new Architect("Shaun", "Ostoic", new DateTime(2019, 06, 29),
               new DateTime(2019, 09, 30), 3000);

            // Act
            string name = architect.firstName;
            string fullName = architect.GetFullName();

            // Assert
            Assert.AreEqual("Ostoic", architect.lastName);
        }

        [TestMethod]
        public void TestMethod6()
        {
            // Arrange 
            Architect architect = new Architect("Shaun", "Ostoic", new DateTime(2019, 06, 29),
               new DateTime(2019, 09, 30), 3000);

            // Act
            string name = architect.firstName;
            string fullName = architect.GetFullName();

            // Assert
            Assert.AreEqual(3000, architect.salary);
        }
    }
}

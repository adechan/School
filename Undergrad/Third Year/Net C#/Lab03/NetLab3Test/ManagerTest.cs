using System;
using System.Text;
using System.Collections.Generic;
using NetLab3;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace NetLab3Test
{
    [TestClass]
    public class ManagerTest
    {
        [TestMethod]
        public void TestMethod1()
        {
            // Arrange
            Manager manager = new Manager("Andreea", "Rindasu", new DateTime(2019, 05, 30), new DateTime(2020, 05, 30), 4500);

            // Act
            string fullName = manager.GetFullName();

            // Assert
            Assert.AreEqual("Andreea Rindasu", manager.GetFullName());
        }

        [TestMethod]
        public void TestMethod2()
        {
            // Arrange
            Manager manager = new Manager("Andreea", "Rindasu", new DateTime(2019, 05, 30), new DateTime(2020, 05, 30), 4500);

            // Act
            

            // Assert
            Assert.AreEqual("Hello manager, Andreea Rindasu", manager.Salutation());
        }

        [TestMethod]
        public void TestMethod3()
        {
            // Arrange
            Manager manager = new Manager("Andreea", "Rindasu", new DateTime(2019, 05, 30), new DateTime(2019, 07, 30), 4500);

            // Act


            // Assert
            Assert.AreEqual(false, manager.IsActive());
        }

        [TestMethod]
        public void TestMethod4()
        {
            // Arrange
            Manager manager = new Manager("Andreea", "Rindasu", new DateTime(2019, 05, 30), new DateTime(2019, 10, 30), 4500);

            // Act


            // Assert
            Assert.AreEqual(true, manager.IsActive());
        }
    }
}

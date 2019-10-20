using System;
using NetLab3;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace NetLab3Test
{
    [TestClass]
    public class ManagerTest
    {
        [TestMethod]
        public void GivenNewManager_WhenFirstLastName_ThenGetFullName()
        {
            // Arrange
            Manager manager = new Manager("Andreea", "Rindasu", new DateTime(2019, 05, 30), new DateTime(2020, 05, 30), 4500);

            // Act
            string fullName = manager.GetFullName();

            // Assert
            Assert.AreEqual("Andreea Rindasu", fullName);
        }

        [TestMethod]
        public void GivenNewManager_WhenSalutation_ThenSalutation()
        {
            // Arrange
            Manager manager = new Manager("Andreea", "Rindasu", new DateTime(2019, 05, 30), new DateTime(2020, 05, 30), 4500);

            // Act
            string salutation = manager.Salutation();

            // Assert
            Assert.AreEqual("Hello manager, Andreea Rindasu", salutation);
        }

        [TestMethod]
        public void GivenNewManager_WhenEndDate2019_ThenIsNotActive()
        {
            // Arrange
            Manager manager = new Manager("Andreea", "Rindasu", new DateTime(2019, 05, 30), new DateTime(2019, 07, 30), 4500);

            // Act
            bool active = manager.IsActive();


            // Assert
            Assert.AreEqual(false, active);
        }

        [TestMethod]
        public void GivenNewManager_WhenEndDate2019_ThenIsActive()
        {
            // Arrange
            Manager manager = new Manager("Andreea", "Rindasu", new DateTime(2019, 05, 30), new DateTime(2019, 10, 30), 4500);

            // Act
            bool active = manager.IsActive();

            // Assert
            Assert.AreEqual(true, active);
        }
    }
}

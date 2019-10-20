using System;
using NetLab3;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace NetLab3Test
{
   
    [TestClass]
    public class EmployeeTest
    { 
        [TestMethod]
        public void GivenNewArchitect_When_ThenNotConstruct()
        {
            Employee employee = new Architect("Shaun", "Ostoic", new DateTime(2019, 06, 29),
                new DateTime(2019, 09, 30), 3000);

            // Act
            string salutation = employee.Salutation();

            // Assert
            Assert.AreEqual("Hello architect, Shaun Ostoic", salutation);

        }

        [TestMethod]
        public void GivenNewManager_WhenSalutation_ThenSalutation()
        {
            Employee employee = new Manager("Shaun", "Ostoic", new DateTime(2019, 06, 29),
                new DateTime(2019, 09, 30), 3000);

            // Act
            string salutation = employee.Salutation();

            // Assert
            Assert.AreEqual("Hello manager, Shaun Ostoic", salutation);

        }

        [TestMethod]
        public void GivenNewManager_WhenId_ThenId()
        {
            Employee employee = new Manager("Shaun", "Ostoic", new DateTime(2019, 06, 29),
                new DateTime(2019, 09, 30), 3000);

            // Act
            Guid id = employee.Id;

            // Assert
            Assert.AreEqual(Guid.Empty, id);
        }

        [TestMethod]
        public void GivenNewManager_WhenFirstNameNotLetters_ThenNotConstruct()
        {
            Employee employee = new Manager("Shau5n", "Ostoic", new DateTime(2019, 06, 29),
                new DateTime(2019, 09, 30), 3000);

            // Act
            string firstName = employee.firstName;

            // Assert'
            Assert.AreEqual("Shau5n", firstName);
        }

    }
    }

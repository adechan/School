
using NetLab3;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace NetLab3Test
{
    [TestClass]
    public class IntExtentionsTest
    {

        [TestMethod]
        public void TestMethod1()
        {
            // Arrange
            int i = 10;

            // Act
            bool result = i.IsGreaterThan(100);

            // Assert
            Assert.AreEqual(false, i.IsGreaterThan(100));
        }
    }
}

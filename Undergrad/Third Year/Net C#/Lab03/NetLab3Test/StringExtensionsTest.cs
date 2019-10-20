using System;
using NetLab3;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace NetLab3Test
{

    [TestClass]
    public class StringExtensionsTest
    {

        [TestMethod]
        public void GivenSentence_WhenWordCound6_ThenWordCount6()
        {
            // Arrange
            String myString = "I am a cute kitty cat";
            // Act
            int countWords = myString.CountWords();

            // Assert
            Assert.AreEqual(6, countWords);
        }
    }
}

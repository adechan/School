
using Lab5;
using Lab5Entity;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.Collections.Generic;

namespace Lab5EntityTests
{
    [TestClass]
    public class ProductMethodTest
    {
        private const string G = "62FA647C-AD54-4BCC-A860-E5A2664B019D";

        [TestMethod]
        public void TestReturnProducts_Expected_All_Products()
        {
            List<Product> products = CreateSut();
            ProductMethods pm = new ProductMethods(products);

            var results = pm.GetProducts();

            Assert.AreEqual(2, results.Count);
        }

        [TestMethod]

        public void TestReturnProducts_Greater_Than_Price()
        {
                List<Product> products = CreateSut();
                ProductMethods pm = new ProductMethods(products);

               var results = pm.GetProductsGreateterThan(3.5);

                Assert.AreEqual("banana", results[0].Description);
        }
        [TestMethod]
        public void TestMethodProducts_In_Range()
        {
            List<Product> products = CreateSut();
            ProductMethods pm = new ProductMethods(products);

            var results = pm.GetProductsInRange(3.5,10);

            Assert.AreEqual("banana", results[0].Description);
        }

      
        public List<Product> CreateSut()
        {
 
            return new List<Product>
            {
                Product.Create("banana", 5),
                Product.Create("mar",3)
            };
        }
    }
}

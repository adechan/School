using System.Linq;
using FluentAssertions;
using Linq;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace LinqTests
{
    [TestClass]
    public class ProductServiceTests
    {
        [TestMethod]
        public void TestMethod1()
        {
            // Arrange
            ProductService productService = new ProductService();
            // Act
            var productsCount = productService.Products.Count;
            // Assert
            // Assert.AreEqual(productsCount, 4);
            productsCount.Should().Be(4);
        }

        [TestMethod]
        public void QuerySyntaxSample()
        {
            // Arrange
            ProductService productService = new ProductService();
            // Act
            var products = productService.Products;

            var filteredProducts = from p in products
                                   where p.Price > 10
                                   select p;

            filteredProducts.Should().NotContainNulls();
        }

        [TestMethod]
        public void MethodSyntaxSample()
        {
            // Arrange
            ProductService productService = new ProductService();
            // Act
            var products = productService.Products;

            var filteredProducts = products.Where(p => p.Price > 10);

            filteredProducts.Should().NotContainNulls();
        }

        [TestMethod]
        public void AggregateSample()
        {
            // Arrange
            ProductService productService = new ProductService();
            // Act
            var products = productService.Products.Union(productService.ProductsForAggregation);

            var productNumbers = products.Count();

            productNumbers.Should().Be(6);
        }

    }
}

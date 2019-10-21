using System;

namespace Linq
{
    public class Product
    {
        public string ProductName { get; }
        public int Price { get; }

        public Guid Id { get; }

        public Product(string productName, int price)
        {
            Id = Guid.NewGuid();
            ProductName = productName;
            Price = price;
        }
    }
}
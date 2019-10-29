using System;

namespace Lab5
{
    public class Product
    {
        private Product()
        {

        }
        public static Product Create(string description, double price)
        {

            return new Product
            {
                ProductId = Guid.NewGuid(),
                Description = description,
                Price = price
            };
        }
        public Guid ProductId { get; private set; }
        public string Description { get;set; }
        public double Price { get; set; }
    }
}

using System.Collections.Generic;

namespace Linq
{
    public class ProductService
    {
        public List<Product> Products { get; }

        public List<Product> ProductsForAggregation { get; }

        public ProductService()
        {
            this.Products = new List<Product>
            {
                new Product("Mere",5),
                new Product("Pere",6),
                new Product("Banane",20),
                new Product("Cirese",10)

            };

            this.ProductsForAggregation = new List<Product>
            {
                new Product("Visine", 3),
                new Product("Caise", 5)
            };
        }

    }
}

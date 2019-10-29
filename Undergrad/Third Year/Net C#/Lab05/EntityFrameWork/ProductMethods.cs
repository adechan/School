using Lab5;
using System;
using System.Collections.Generic;
using System.Linq;

namespace Lab5Entity
{
    public class ProductMethods
    {
        private List<Product> products;
        public ProductMethods(List<Product> myProducts)
        {
            products = myProducts;
        }

        public List<Product> GetProducts() { return products; }
        public List<Product> GetProductsGreateterThan(double price) => products.Where(p => p.Price > price).ToList();
        public Product GetProductById(Guid id) => products.Find(p => p.ProductId == id);

        public List<Product> GetProductsInRange(double min, double max) => GetProductsGreateterThan(min).Where(p => p.Price < max).ToList();

        public void UpdateProduct(Guid id, double price)
        {
            List<Product> result = products.Where(p => p.ProductId == id).ToList();
            result.ForEach(prod => prod.Price = price);
        }

        public void UpdateProduct(Guid id,string description)
        {
            List<Product> result = products.Where(p => p.ProductId == id).ToList();
            result.ForEach(prod => prod.Description = description);
        }

        public void DeleteProduct(Guid id) => products.RemoveAll(p => p.ProductId == id);
      

    }
}

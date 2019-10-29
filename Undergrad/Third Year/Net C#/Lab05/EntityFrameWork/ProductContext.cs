
using Lab5;
using Microsoft.EntityFrameworkCore;

namespace EntityFrameWork
{
    public class ProductContext : DbContext
    {
        public ProductContext()
        {
            Database.EnsureCreated();
        }

        public DbSet<Product> Products { get; set; }

        protected override void OnConfiguring(DbContextOptionsBuilder optionBuilder)
        {
            optionBuilder.UseSqlite(@"Data Source=IdentitySample.sqlite;");   
        }
        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            modelBuilder.Entity<Product>(e =>
              {
                  e.Property(t => t.Description).IsRequired().HasMaxLength(40);
                  e.Property(t => t.Price).IsRequired();
              });

            modelBuilder.Entity<Product>().HasData(
                Product.Create("banana buna", 2.0),
                Product.Create("mar si mai bun",1.5)
             );

        }
    }
}

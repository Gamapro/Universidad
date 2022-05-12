using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FinaProjectSalesApp
{
    public class Store
    {
        public int id;
        public string name;
        public List<Product> products;
        public int soda, bread, vegetables, profit;
        public Store(int id, string name)
        {
            this.id = id;
            this.name = name;
            products = new List<Product>();
            soda = bread = vegetables = 0;
        }
        public void addProduct(Product product)
        {
            products.Add(product);
        }
        public string getProductsString()
        {
            return "Sodas : " + soda.ToString() + ", Bread : " + bread.ToString() + ", Vegetables : " + vegetables.ToString();
        }
        public void setProductValues()
        {
            int b = 0, s = 0, v = 0;
            foreach (Product p in products)
            {
                if (p.id == 0) s++;
                if (p.id == 1) b++;
                if (p.id == 2) v++;
            }
            soda = s; bread = b; vegetables = v;
            return;
        }
        public void setProfit()
        {
            this.profit = soda * Soda.price + bread * Bread.price + vegetables * Vegetables.price;
        }
    }
}

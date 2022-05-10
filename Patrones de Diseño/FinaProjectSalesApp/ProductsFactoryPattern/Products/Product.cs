using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FinaProjectSalesApp
{
    public class Product
    {
        public int id;
        protected string name;
        protected int price;
        protected int amount;
        public Product()
        {
            this.price = 1;
            this.amount = 1;
        }
    }
}

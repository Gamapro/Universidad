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
        static public int price = 1;
        public int amount;
        public Product()
        {
            this.amount = 1;
        }
    }
}

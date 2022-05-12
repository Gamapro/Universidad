using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FinaProjectSalesApp
{
    class Vegetables : Product
    {
        static public new int price = 3;
        public Vegetables() : base()
        {
            price = 3;
            this.id = 2;
            this.name = "Vegetables";
        }
    }
}

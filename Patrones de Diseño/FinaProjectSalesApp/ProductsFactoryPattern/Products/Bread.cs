using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FinaProjectSalesApp
{
    class Bread : Product
    {
        static public new int price = 5;
        public Bread() : base()
        {
            price = 5;
            this.id = 1;
            this.name = "Bread";
        }
    }
}

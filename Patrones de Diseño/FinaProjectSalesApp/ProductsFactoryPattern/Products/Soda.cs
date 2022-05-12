using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FinaProjectSalesApp
{
    class Soda : Product
    {
        static public new int price = 10;
        public Soda() : base()
        {
            this.id = 0;
            this.name = "Soda";
        }
    }
}


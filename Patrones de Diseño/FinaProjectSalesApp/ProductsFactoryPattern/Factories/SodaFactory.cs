using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FinaProjectSalesApp
{
    class SodaFactory : Factory
    {
        public override Product FactoryCreate()
        {
            return new Soda();
        }
    }
}

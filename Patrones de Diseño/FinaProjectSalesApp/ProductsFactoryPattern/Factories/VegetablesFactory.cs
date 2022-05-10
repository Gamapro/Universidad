using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FinaProjectSalesApp
{
    class VegetablesFactory : Factory
    {
        public override Product FactoryCreate()
        {
            return new Vegetables();
        }
    }
}

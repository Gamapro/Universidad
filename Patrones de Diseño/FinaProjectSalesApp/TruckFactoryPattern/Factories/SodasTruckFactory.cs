using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FinaProjectSalesApp
{
    public class SodasTruckFactory : TruckFactory
    {
        public override Truck FactoryCreate()
        {
            Truck truck = new SodaTruck();
            truck.quantity = 120;
            truck.id = 0;
            return truck;
        }
    }
}

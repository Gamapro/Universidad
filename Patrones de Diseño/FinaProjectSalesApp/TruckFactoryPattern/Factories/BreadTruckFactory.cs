using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FinaProjectSalesApp
{
    public class BreadTruckFactory : TruckFactory
    {
        public override Truck FactoryCreate()
        {
            Truck truck = new BreadTruck();
            truck.quantity = 270;
            truck.id = 1;
            return truck;
        }
    }
}

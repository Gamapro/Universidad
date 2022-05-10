using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FinaProjectSalesApp
{
    public class VegetablesTruckFactory : TruckFactory
    {
        public override Truck FactoryCreate()
        {
            Truck truck = new VegetablesTruck();
            truck.quantity = 95;
            truck.id = 2;
            return truck;
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FinaProjectSalesApp
{
    class Mediator
    {
        private Orders form;
        private FacadeQR facade;
        public Mediator()
        {
            facade = new FacadeQR();
            Singleton singleton = Singleton.Instance;
            singleton = Singleton.GetInstance();
            form = singleton.ordersForm;
        }
        public Mediator(ref Orders form)
        {
            this.form = form;
        }
        public void updateStoreTable()
        {
            facade = new FacadeQR();
            List<Store> stores = facade.getStoreList();
            form.Grid.DataSource = null;
            int i = 0;
            form.Grid.Rows.Clear();
            foreach (Store store in stores)
            {
                form.Grid.Rows.Add();
                form.Grid[0, i].Value = store.id;
                form.Grid[1, i].Value = store.name;
                form.Grid[2, i].Value = store.getProductsString();
                i++;
            } 
        }
        public void updateBinnacle(string text)
        {
            Singleton singleton = Singleton.GetInstance();
            singleton.binnacle.textboxAddText(text);
            singleton.binnacle.textAddText(text);
            singleton.binnacle.gridAddText(text);
        }
        public bool checkTruckCapacity(List<int> numTrucks)
        {
            Singleton singleton = Singleton.GetInstance();
            List<int> orderValues = facade.getStoresTotalAmount();
            foreach (Truck truck in singleton.trucks) { 
                if(numTrucks[truck.id] > 0)
                {
                    orderValues[truck.id] -= truck.quantity;
                    numTrucks[truck.id] -= 1;
                }
            }
            int k = 0;
            foreach(int x in orderValues)
            {
                k += Math.Max(0, x);
            }
            return k == 0;
        }
        public List<int> getProductsAmount(List<int> numTrucks)
        {
            Singleton singleton = Singleton.GetInstance();
            List<int> amount = facade.getEmptyList(3);
            foreach (Truck truck in singleton.trucks)
            {
                if (numTrucks[truck.id] > 0)
                {
                    amount[truck.id] += truck.quantity;
                    numTrucks[truck.id] -= 1;
                }
            }
            return amount;
        }
        public bool checkNonZero()
        {
            int val = 0;
            List<int> vals = getIdealTruckDistribution();
            foreach (int x in vals) val += x;
            return val == 0;
        }
        public bool checkTruckAvailability()
        {
            Singleton singleton = Singleton.GetInstance();
            List<int> values = facade.getStoresTotalAmount();
            foreach (Truck truck in singleton.trucks)
            {
                values[truck.id] -= truck.quantity;
            }
            foreach(int x in values)
            {
                if(x > 0) return false;
            }
            return true;
        }
        public List<int> getIdealTruckDistribution()
        {
            Singleton singleton = Singleton.GetInstance();
            List<int> orderValues = facade.getStoresTotalAmount();
            List<int> trucksNeeded = facade.getEmptyList(3);
            foreach (Truck truck in singleton.trucks)
            {
                if (orderValues[truck.id] > 0)
                {
                    orderValues[truck.id] -= truck.quantity;
                    trucksNeeded[truck.id] += 1;
                }
            }
            return trucksNeeded;
        }
    }
}

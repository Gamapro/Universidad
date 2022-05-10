using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace FinaProjectSalesApp
{
    class FacadeQR
    {
        ApiQR api;
        public FacadeQR()
        {
            api = new ApiQR();
        }
        public void AddNewStore(string storeName, int id)
        {
            // Create new store
            Store store = new Store(id, storeName);
            // create qr
            string jsonStore = api.serializeStore(store);
            var stream = api.request(jsonStore);
            api.saveBMPStream(stream, id.ToString()+"-"+storeName+ ".bmp");
            // Use singletone for mediator and form
            Singleton singleton = Singleton.Instance;
            singleton = Singleton.GetInstance();
            // call mediator to update
            singleton.mediatorUpdateStoreTable();
            singleton.ordersForm.Show();
        }
        public void AddNewStore(Store store)
        {
            // create qr
            string jsonStore = api.serializeStore(store);
            var stream = api.request(jsonStore);
            api.saveBMPStream(stream, store.id.ToString() + "-" + store.name + ".bmp");
            // Use singletone for mediator and form
            Singleton singleton = Singleton.Instance;
            singleton = Singleton.GetInstance();
            // call mediator to update
            singleton.mediatorUpdateStoreTable();
        }
        public void ModifyStore(int s, int b, int v, int id)
        {
            Store store = getStoreByIndex(id);
            Singleton singleton = Singleton.Instance;
            singleton = Singleton.GetInstance();
            store.soda = s;
            store.bread = b;
            store.vegetables = v;
            // Because of terms of memory and the api used
            // products are not going to be add as classes but as the number of products
            // while (s-- > 0) store.products.Add(singleton.sodaFactory.FactoryCreate());
            // while (b-- > 0) store.products.Add(singleton.breadFactory.FactoryCreate());
            // while (v-- > 0) store.products.Add(singleton.vegetablesFactory.FactoryCreate());
            AddNewStore(store);
        }
        public List<Store> getStoreList()
        {
            List<Store> list = new List<Store>();
            string path = Directory.GetCurrentDirectory();
            string[] filePaths = Directory.GetFiles(path,"*.bmp");
            foreach (String s in filePaths)
            {
                string jsonString = api.decode(s);
                if(jsonString != "") list.Add(api.deserializeStore(jsonString));
            }
            return list;
        }
        public void messageBox(string message, string caption)
        {
            var result = MessageBox.Show(message, caption,
                                            MessageBoxButtons.OKCancel,
                                            MessageBoxIcon.Information);
            return;
        }
        public bool validId(int id)
        {
            List<Store> list = getStoreList();
            foreach(Store store in list)
            {
                if (store.id == id) return false;
            }
            return true;
        }
        public List<ComboItem> getComboItemsList()
        {
            List<ComboItem> items = new List<ComboItem>();
            List<Store> list = getStoreList();
            foreach (Store store in list)
            {
                items.Add(new ComboItem() { Text = store.name, ID = store.id });
            }
            return items;
        }
        public Store getStoreByIndex(int id)
        {
            List<Store> list = getStoreList();
            foreach (Store store in list)
            {
                if (store.id == id) return store;
            }
            return null;
        }
        public List<int> getStoresTotalAmount()
        {
            List<int> sol = getEmptyList(3);
            List<Store> list = getStoreList();
            Console.WriteLine(sol.Count);
            foreach (Store store in list)
            {
                sol[0] += store.soda;
                sol[1] += store.bread;
                sol[2] += store.vegetables;
            }
            return sol;
        }
        public List<int> getEmptyList(int x)
        {
            List<int> sol = new List<int>(x);
            for (int i = 0; i < x; i++) sol.Add(0);
            return sol;
        }
    }
}

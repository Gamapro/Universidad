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
        public Mediator()
        {
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
            FacadeQR facade = new FacadeQR();
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
    }
}

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace FinaProjectSalesApp
{
    public partial class Delivery : Form
    {
        Orders form;
        FacadeQR facade;
        public Delivery(ref Orders form)
        {
            InitializeComponent();
            facade = new FacadeQR();
            this.form = form;
            // Mediator updates binnacle
            string str = "Starting delivery route.";
            Singleton.GetInstance().mediator.updateBinnacle(str);
        }
        private void Exit_Click(object sender, EventArgs e)
        {
            form.Show();
            this.Close();
        }
        private void register_Click(object sender, EventArgs e)
        {
            if (!validateNumber(sodasTextBox.Text,"Soda") || !validateNumber(breadTextBox.Text,"Bread") || !validateNumber(vegetablesTextBox.Text, "Vegetables"))
            {
                return;
            }
            int s, b, v;
            Int32.TryParse(sodasTextBox.Text, out s);
            Int32.TryParse(breadTextBox.Text, out b);
            Int32.TryParse(vegetablesTextBox.Text, out v);
            Singleton singleton = Singleton.GetInstance();
            if(s+b+v == 0)
            {
                facade.messageBox("Number of trucks must be at least 1.", "Invalid number of trucks");
                return;
            }
            if (s + b + v > 5)
            {
                facade.messageBox("Number of trucks must not exceed 5.", "Invalid number of trucks");
                return;
            }
            List<int> vals = facade.getEmptyList(3);
            vals[0] = s; vals[1] = b; vals[2] = v;
            if (!singleton.mediator.checkTruckCapacity( vals ) )
            {
                facade.messageBox("Not enough trucks to satisfy the demand.", "Invalid number of trucks");
                return;
            }

            // Mediator updates binnacle
            Singleton.GetInstance().mediator.updateBinnacle((s+b+v).ToString() + " trucks added to the route.");

            vals[0] = s; vals[1] = b; vals[2] = v;
            List<int> productsAmount = singleton.mediator.getProductsAmount(vals);

            string str = "Starting delivery route.";
            facade.messageBox(str, "Delivery process");
            // Delivery process
            List<Store> stores = facade.getStoreList();

            // sort store by profit
            for (int i = 0; i < stores.Count; i++)
            {
                for (int j = i; j > 0; j--)
                {   
                    if (stores[j].profit > stores[j-1].profit)
                    {
                        Store aux = stores[j];
                        stores[j] = stores[j-1];
                        stores[j-1] = aux;
                    }
                }
            }

            foreach (Store store in stores)
            {
                productsAmount[0] -= store.soda;
                productsAmount[1] -= store.bread;
                productsAmount[2] -= store.vegetables;
                str = String.Format("Store {3} received {4}\n" +
                    "Products left: Soda {0}, Bread {1}, Vegetables {2}\n" + 
                    "Profit: {5}",
                    productsAmount[0], productsAmount[1], productsAmount[2],
                    store.name, store.getProductsString(), store.profit);
                facade.messageBox(str, "Delivery process");
            }
            string left = String.Format("Products left: Soda {0}, Bread {1}, Vegetables {2}",
                    productsAmount[0], productsAmount[1], productsAmount[2]);

            // Mediator updates binnacle
            str = "Delivery completed.";
            Singleton.GetInstance().mediator.updateBinnacle(str);
            facade.messageBox(str+"\n"+left, "Delivery process");
            form.Show();
            this.Close();
        }
        private bool validateNumber(string s, string camp)
        {
            int val = 0;
            Console.WriteLine(s);
            if (s == "" || !Int32.TryParse(s, out val)) {
                facade.messageBox("Please introduce a valid quantity.", "Invalid quantity on "+camp);
                return false;
            }
            if (val < 0) {
                facade.messageBox("Only non-negative numbers are accepted.", "Invalid quantity on "+camp);
                return false;
            }
            if (val > 3)
            {
                facade.messageBox("Number of trucks are limited to 3.", "Invalid quantity on " + camp);
                return false;
            } 
            return true;
        }

        private void idealDistribution_Click(object sender, EventArgs e)
        {
            Singleton singleton = Singleton.GetInstance();
            List<int> ideal = singleton.mediator.getIdealTruckDistribution();
            string rec = String.Format("The recommended amount of trucks are: Sodas {0}, Bread {1}, Vegetables {2}",
                ideal[0], ideal[1], ideal[2]
                );
            facade.messageBox(rec, "Ideal route");
            // Mediator updates binnacle
            Singleton.GetInstance().mediator.updateBinnacle("Get ideal truck distribution.");
            return;
        }
    }
}

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace FinaProjectSalesApp
{
    public partial class Orders : Form
    {
        Mediator mediator = null;
        public Orders()
        {
            InitializeComponent();
            var t = this;
            mediator = new Mediator(ref t);
            mediator.updateStoreTable();
        }
        private void AddStore_Click(object sender, EventArgs e)
        {
            setReference();
            var t = this;
            StoreRegister form = new StoreRegister(ref t);
            form.Show();
            this.Hide();
        }
        private void ModifyStore_Click(object sender, EventArgs e)
        {
            setReference();
            var t = this;
            StoreOrder form = new StoreOrder(ref t);
            form.Show();
            this.Hide();
        }
        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();
            if(Singleton.Instance != null)
            {
                Singleton.GetInstance().binnacle.Close();
            }
        }
        private void delivery_Click(object sender, EventArgs e)
        {
            setReference();
            Singleton singleton = Singleton.Instance;
            singleton = Singleton.GetInstance();
            if (!singleton.mediator.checkTruckAvailability())
            {
                singleton.facade.messageBox("There are not enough trucks to satisfy the order.","Not enough trucks");
                return;
            }
            if (singleton.mediator.checkNonZero())
            {
                singleton.facade.messageBox("All orders are empty.", "Empty orders.");
                return;
            }
            var t = this;
            Delivery form = new Delivery(ref t);
            form.Show();
            this.Hide();
        }

        private void binacle_Click(object sender, EventArgs e)
        {
            setReference();
            Singleton singleton =  Singleton.GetInstance();
            singleton.binnacle.Show();
            this.Hide();
        }
        private void setReference()
        {
            Singleton singleton = Singleton.GetInstance();
            if (singleton.ordersForm == null)
            {
                singleton.ordersForm = this;
                singleton.mediator = mediator;
            }
        }
    }
}



















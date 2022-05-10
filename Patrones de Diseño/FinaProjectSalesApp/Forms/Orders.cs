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
        public Orders()
        {
            InitializeComponent();
            var t = this;
            Mediator mediator = new Mediator(ref t);
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
        private void setReference()
        {
            Singleton singleton = Singleton.Instance;
            singleton = Singleton.GetInstance();
            if(singleton.ordersForm == null)
            {
                singleton.ordersForm = this;
            }
        }
    }
}



















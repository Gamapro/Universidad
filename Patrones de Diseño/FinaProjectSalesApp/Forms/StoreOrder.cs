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
    public partial class StoreOrder : Form
    {
        Orders form;
        FacadeQR facade;
        public StoreOrder(ref Orders form)
        {
            InitializeComponent();
            facade = new FacadeQR();
            this.form = form;
            List<ComboItem> items = facade.getComboItemsList();
            items.Insert(0, new ComboItem() { Text = "Select store", ID = -1 });
            comboBoxID.DataSource = items;
            comboBoxID.ValueMember = "Text";
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
            int id = getCurrentStoreId();
            if (id == -1) return;
            int s, b, v;
            Int32.TryParse(sodasTextBox.Text, out s);
            Int32.TryParse(breadTextBox.Text, out b);
            Int32.TryParse(vegetablesTextBox.Text, out v);
            facade.ModifyStore(s,b,v,id);
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
            return true;
        }
        private void ComboBox1_SelectedIndexChanged(object sender, System.EventArgs e)
        {
            int id = getCurrentStoreId();
            if (id == -1)
            {
                sodaLabel.Text = breadLabel.Text = vegetablesLabel.Text = infoLabel.Text = "";
                disableElements();
                return;
            }
            Store store = facade.getStoreByIndex(id);
            if (store == null) return;
            enableElements();
            fillLabels();
            fillTextBox(store);
        }
        private int getCurrentStoreId()
        {
            ComboItem itm = (ComboItem)comboBoxID.SelectedItem;
            return itm.ID;
        }
        private void enableElements()
        {
            sodasTextBox.Visible = true;
            breadTextBox.Visible = true;
            vegetablesTextBox.Visible = true;
            register.Enabled = true;
        }
        private void disableElements()
        {
            sodasTextBox.Visible = false;
            breadTextBox.Visible = false;
            vegetablesTextBox.Visible = false;
            register.Enabled = false;
        }
        private void fillTextBox(Store store)
        {
            sodasTextBox.Text = store.soda.ToString();
            breadTextBox.Text = store.bread.ToString();
            vegetablesTextBox.Text = store.vegetables.ToString();
        }
        private void fillLabels()
        {
            infoLabel.Text = "The requested products are:";
            sodaLabel.Text = "Sodas";
            breadLabel.Text = "Bread";
            vegetablesLabel.Text = "Vegetables";
        }
    }
}

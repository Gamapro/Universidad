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
    public partial class StoreRegister : Form
    {
        FacadeQR facade;
        Orders form;
        public StoreRegister(ref Orders form)
        {
            InitializeComponent();
            facade = new FacadeQR();
            this.form = form;
        }
        private void RegisterStore_Click(object sender, EventArgs e)
        {
            if (textName.Text == "") {
                facade.messageBox("Please introduce a valid name.", "Invalid store name");
                return;
            }
            int id = 0;
            if (idText.Text == "" || !Int32.TryParse(idText.Text, out id)){
                facade.messageBox("Please introduce a valid ID.", "Invalid ID");
                return;
            }
            if (id < 0) {
                facade.messageBox("Please introduce a valid ID. Only non-negative numbers are accepted.", "Invalid ID");
                return;
            }
            if (!facade.validId(id)){
                facade.messageBox("That ID is already on use. Please choose a different one.", "Invalid ID");
                return;
            }
            facade.AddNewStore(textName.Text, id );
            form.Show();
            this.Close();
        }
        private void Exit_Click(object sender, EventArgs e)
        {
            form.Show();
            this.Close();
        }
    }
}

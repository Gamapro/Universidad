using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace FinaProjectSalesApp
{
    public partial class Binacle : Form
    {
        private int text, textbox, grid;
        private string filename;
        public Binacle()
        {
            InitializeComponent();
            text = textbox = grid = 0;
            setText();
            filename = "text.txt";
            if (File.Exists(filename))
            {
                File.Delete(filename);
            }
            using (FileStream fs = File.Create(filename))
            {
                fs.Close();
            }
        }
        private void textButton_Click(object sender, EventArgs e)
        {
            text += 1;
            setText();
        }
        private void reset_Click(object sender, EventArgs e)
        {
            text = textbox = grid = 0;
            setText();
        }
        private void textBoxButton_Click(object sender, EventArgs e)
        {
            textbox += 1;
            setText();
        }
        private void gridButton_Click(object sender, EventArgs e)
        {
            grid += 1;
            setText();
        }
        private void button1_Click(object sender, EventArgs e)
        {
            Singleton singleton = Singleton.GetInstance();
            singleton.ordersForm.Show();
            this.Hide();
        }
        private void setText()
        {
            textButton.Text = "Text";
            textBoxButton.Text = "Textbox";
            gridButton.Text = "Grid";
            if (text > 0) textButton.Text += "\n(" + text.ToString() +")";
            if (textbox > 0) textBoxButton.Text += "\n(" + textbox.ToString() + ")";
            if (grid > 0) gridButton.Text += "\n(" + grid.ToString() + ")";
        }
        public void textboxAddText(string s)
        {
            for(int i = 0; i < textbox; i++) richTextBox.Text += s + "\n";
        }
        public void textAddText(string s)
        {
            using (StreamWriter sw = File.AppendText(filename))
            {
                for (int i = 0; i < text; i++)
                    sw.WriteLine(s);
                sw.Close();
            }
        }
        public void gridAddText(string s)
        {
            for (int i = 0; i < grid; i++)
            {
                dataGridView.Rows.Add(s + "\n");
            }
        }
    }
}

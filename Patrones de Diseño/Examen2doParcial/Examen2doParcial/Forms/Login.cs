using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;

namespace Examen2doParcial
{
    public partial class Login : Form
    {
        public Login()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if ( userText.Text != "" && passText.Text != "" )
            {
                SingletonUsers singleton = SingletonUsers.Instance;
                singleton = SingletonUsers.GetInstance();
                Alumno alumno = null;
                if (singleton.validateUser(userText.Text, passText.Text, ref alumno))
                {
                    var formLogin = this;
                    InfoForm alumnoForm = new InfoForm(alumno, ref formLogin);
                    alumnoForm.Show();
                    this.Hide();
                    Debug.WriteLine("Login");
                }
                else 
                {
                    // sofia.bravo@hotmail.com
                    // CHUiHB
                    Debug.WriteLine("Failed!");
                }
            }

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }
    }
}

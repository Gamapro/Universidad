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
                Supervisor supervisor = null;
                Profesor profesor = null;
                var formLogin = this;
                Director director = new Director();
                if (singleton.validateAlumnoUser(userText.Text, passText.Text, ref alumno))
                {
                    Builder build = new AlumnoBuilder(alumno, ref formLogin);
                    director.Construct(build);
                    Form form = build.GetResult();
                    form.Show();
                    this.Hide();
                    Debug.WriteLine("Login");
                }
                else if (singleton.validateProfesorUser(userText.Text, passText.Text, ref profesor))
                {
                    Builder build = new ProfesorBuilder(profesor, ref formLogin);
                    director.Construct(build);
                    Form form = build.GetResult();
                    form.Show();
                    this.Hide();
                    Debug.WriteLine("Login");
                }
                else if (singleton.validateUser(userText.Text, passText.Text, ref supervisor))
                {
                    Builder build = new SupervisorBuilder(supervisor, ref formLogin);
                    director.Construct(build);
                    Form form = build.GetResult();
                    form.Show();
                    this.Hide();
                    Debug.WriteLine("Login");
                }
                else 
                {
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

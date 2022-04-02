using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Reflection;
using System.Diagnostics;
using System.IO;

namespace Examen2doParcial
{
    public partial class InfoForm : Form
    {
        private Alumno alumno { get; set; }
        private Login loginForm;
        public InfoForm(Alumno alumno, ref Login loginForm)
        {
            InitializeComponent();
            this.loginForm = loginForm;
            this.alumno = alumno;
            createDataTable();
            createGradesTable();
        }
        public void createDataTable()
        {
            dataTable.Columns.Add("Informacion", "Informacion");
            float promedio = 0, n = 0;
            foreach (PropertyInfo property in alumno.GetType().GetProperties())
            {
                if (property.Name == "Calificaciones")
                {
                    foreach (int calf in alumno.Calificaciones )
                    {
                        promedio+=calf; n+=1;
                    }
                    continue;
                }
                int rowIdx = dataTable.Rows.Count - 1;
                dataTable.Rows.Add(property.GetValue(alumno));
                dataTable.Rows[rowIdx].HeaderCell.Value = property.Name;
                Size textSize = TextRenderer.MeasureText(property.Name, dataTable.Font);
                dataTable.RowHeadersWidth = Math.Max(textSize.Width + 40, dataTable.RowHeadersWidth);
            }
            int rowIdx2 = dataTable.Rows.Count-1;
            if (n != 0) promedio /= n; else promedio = 0;
            dataTable.Rows.Add(promedio);
            dataTable.Rows[rowIdx2].HeaderCell.Value = "Promedio";
        }
        public void createGradesTable()
        {
            SingletonUsers singleton = SingletonUsers.Instance;
            singleton = SingletonUsers.GetInstance();
            string[] materias = singleton.getGrades();
            foreach (string materia in materias) 
            {
                gradesTable.Columns.Add(materia, materia);
            }
            int rowIdx = gradesTable.Rows.Count - 1;
            for(int i = 0; i < materias.Length; i++)
            {
                gradesTable[i, rowIdx].Value = alumno.Calificaciones[i].ToString();
            }
            return;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            loginForm.Show();
            this.Hide();
        }

        private void botonDescarga_Click(object sender, EventArgs e)
        {
            string path = Directory.GetCurrentDirectory();
            string fileName = path + "Calificaciones-"+alumno.Nombre+".txt";
            float promedio = 0;
            int n = 0;
            FileInfo fiile = new FileInfo(fileName);
            try
            {    
                if (fiile.Exists)
                {
                    fiile.Delete();
                }
                using (StreamWriter sw = fiile.CreateText())
                {
                    SingletonUsers singleton = SingletonUsers.Instance;
                    singleton = SingletonUsers.GetInstance();
                    string[] materias = singleton.getGrades();
                    for (int i = 0; i < Math.Min(alumno.Calificaciones.Length, materias.Length); i++){
                        sw.WriteLine(materias[i] + ": " + alumno.Calificaciones[i].ToString());
                        promedio += alumno.Calificaciones[i]; n++;
                    }
                    if (n != 0) promedio /= n; else promedio = 0;
                    sw.WriteLine("Promedio: " + promedio.ToString());
                }
                // readonly 
                string message = "Documento exitosamente creado en la carpeta "+fileName;
                const string caption = "Descarga exitosa";
                var result = MessageBox.Show(message, caption,
                                             MessageBoxButtons.OK,
                                             MessageBoxIcon.Information);
            }
            catch (Exception Ex)
            {
                Console.WriteLine(Ex.ToString());
            }
        }
    }
}

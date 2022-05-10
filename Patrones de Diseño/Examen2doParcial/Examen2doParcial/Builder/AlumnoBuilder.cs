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
using System.Configuration;

namespace Examen2doParcial
{
    public class AlumnoBuilder : Builder
    {
        private Alumno alumno;
        private Login login;
        private UserForm form;
        public AlumnoBuilder(Alumno alumno, ref Login login)
        {
            this.alumno = alumno;
            this.login = login;
            this.form = new UserForm();
        }
        public override void InitializeFormElements()
        {
            form.Regresar = new System.Windows.Forms.Button();
            form.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(form.components);
            form.gradesTable = new System.Windows.Forms.DataGridView();
            form.dataTable = new System.Windows.Forms.DataGridView();
            form.DatosLabel = new System.Windows.Forms.Label();
            form.calificacionesLabel = new System.Windows.Forms.Label();
            form.botonDescarga = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(form.gradesTable)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(form.dataTable)).BeginInit();
            form.SuspendLayout();

            // 
            // Regresar
            // 
            form.Regresar.Location = new System.Drawing.Point(684, 382);
            form.Regresar.Name = "Regresar";
            form.Regresar.Size = new System.Drawing.Size(84, 38);
            form.Regresar.TabIndex = 1;
            form.Regresar.Text = "Regresar";
            form.Regresar.UseVisualStyleBackColor = true;
            form.Regresar.Click += new System.EventHandler(this.button1_Click);
            // 
            // contextMenuStrip1
            // 
            form.contextMenuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            form.contextMenuStrip1.Name = "contextMenuStrip1";
            form.contextMenuStrip1.Size = new System.Drawing.Size(61, 4);

        }
        public override void BuildDownloadGrades()
        {
            // 
            // botonDescarga
            // 
            form.botonDescarga.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            form.botonDescarga.Location = new System.Drawing.Point(514, 271);
            form.botonDescarga.Name = "botonDescarga";
            form.botonDescarga.Size = new System.Drawing.Size(172, 60);
            form.botonDescarga.TabIndex = 9;
            form.botonDescarga.Text = "Descargar calificaciones";
            form.botonDescarga.UseVisualStyleBackColor = true;
            form.botonDescarga.Click += new System.EventHandler(this.botonDescarga_Click);
        }
        public override void BuildConsultGrades()
        {
            // 
            // calificacionesLabel
            // 
            form.calificacionesLabel.AutoSize = true;
            form.calificacionesLabel.Font = new System.Drawing.Font("Microsoft YaHei", 13.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            form.calificacionesLabel.Location = new System.Drawing.Point(508, 62);
            form.calificacionesLabel.Name = "calificacionesLabel";
            form.calificacionesLabel.Size = new System.Drawing.Size(178, 31);
            form.calificacionesLabel.TabIndex = 8;
            form.calificacionesLabel.Text = "Calificaciones";
            form.calificacionesLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // gradesTable
            // 
            form.gradesTable.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            form.gradesTable.Location = new System.Drawing.Point(404, 125);
            form.gradesTable.Name = "gradesTable";
            form.gradesTable.RowHeadersWidth = 51;
            form.gradesTable.RowTemplate.Height = 24;
            form.gradesTable.Size = new System.Drawing.Size(374, 105);
            form.gradesTable.TabIndex = 5;
            createGradesTable();
        }
        public override void BuildBasicInfo()
        {
            // 
            // dataTable
            //
            form.dataTable.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.DisplayedCells;
            form.dataTable.AutoSizeRowsMode = System.Windows.Forms.DataGridViewAutoSizeRowsMode.DisplayedCells;
            form.dataTable.ColumnHeadersBorderStyle = System.Windows.Forms.DataGridViewHeaderBorderStyle.Sunken;
            form.dataTable.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            form.dataTable.Location = new System.Drawing.Point(25, 94);
            form.dataTable.Name = "dataTable";
            form.dataTable.RowHeadersWidth = 51;
            form.dataTable.RowTemplate.Height = 24;
            form.dataTable.Size = new System.Drawing.Size(351, 257);
            form.dataTable.TabIndex = 6;
            // 
            // DatosLabel
            // 
            form.DatosLabel.AutoSize = true;
            form.DatosLabel.Font = new System.Drawing.Font("Microsoft YaHei", 13.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            form.DatosLabel.Location = new System.Drawing.Point(158, 33);
            form.DatosLabel.Name = "DatosLabel";
            form.DatosLabel.Size = new System.Drawing.Size(85, 31);
            form.DatosLabel.TabIndex = 7;
            form.DatosLabel.Text = "Datos";
            form.DatosLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // InfoForm
            // 
            form.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            form.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            form.ClientSize = new System.Drawing.Size(800, 450);
            form.Controls.Add(form.botonDescarga);
            form.Controls.Add(form.calificacionesLabel);
            form.Controls.Add(form.DatosLabel);
            form.Controls.Add(form.dataTable);
            form.Controls.Add(form.gradesTable);
            form.Controls.Add(form.Regresar);
            form.Name = "InfoForm";
            form.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(form.gradesTable)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(form.dataTable)).EndInit();
            form.ResumeLayout(false);
            form.PerformLayout();


            createDataTable();
        }
        public override UserForm GetResult()
        {
            // InfoForm form = new InfoForm(alumno, ref login);
            return this.form;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            login.Show();
            form.Hide();
        }

        private void botonDescarga_Click(object sender, EventArgs e)
        {
            string path = Directory.GetCurrentDirectory();
            // string ext = "txt";
            var ext = ConfigurationManager.AppSettings["ext"];
            string fileName = path + "Calificaciones-" + alumno.Nombre + "." + ext;
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
                    for (int i = 0; i < Math.Min(alumno.Calificaciones.Length, materias.Length); i++)
                    {
                        sw.WriteLine(materias[i] + ": " + alumno.Calificaciones[i].ToString());
                        promedio += alumno.Calificaciones[i]; n++;
                    }
                    if (n != 0) promedio /= n; else promedio = 0;
                    sw.WriteLine("Promedio: " + promedio.ToString());
                }
                // readonly 
                string message = "Documento exitosamente creado en la carpeta " + fileName;
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

        public void createDataTable()
        {
            form.dataTable.Columns.Add("Informacion", "Informacion");
            float promedio = 0, n = 0;
            foreach (PropertyInfo property in alumno.GetType().GetProperties())
            {
                if (property.Name == "Calificaciones")
                {
                    foreach (int calf in alumno.Calificaciones)
                    {
                        promedio += calf; n += 1;
                    }
                    continue;
                }
                int rowIdx = form.dataTable.Rows.Count - 1;
                form.dataTable.Rows.Add(property.GetValue(alumno));
                form.dataTable.Rows[rowIdx].HeaderCell.Value = property.Name;
                Size textSize = TextRenderer.MeasureText(property.Name, form.dataTable.Font);
                form.dataTable.RowHeadersWidth = Math.Max(textSize.Width + 40, form.dataTable.RowHeadersWidth);
            }
            int rowIdx2 = form.dataTable.Rows.Count - 1;
            if (n != 0) promedio /= n; else promedio = 0;
            form.dataTable.Rows.Add(promedio);
            form.dataTable.Rows[rowIdx2].HeaderCell.Value = "Promedio";
        }
        public void createGradesTable()
        {
            SingletonUsers singleton = SingletonUsers.Instance;
            singleton = SingletonUsers.GetInstance();
            string[] materias = singleton.getGrades();
            foreach (string materia in materias)
            {
                form.gradesTable.Columns.Add(materia, materia);
            }
            int rowIdx = form.gradesTable.Rows.Count - 1;
            for (int i = 0; i < materias.Length; i++)
            {
                form.gradesTable[i, rowIdx].Value = alumno.Calificaciones[i].ToString();
            }
            return;
        }

    }

}

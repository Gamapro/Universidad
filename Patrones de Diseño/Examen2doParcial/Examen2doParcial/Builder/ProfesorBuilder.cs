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
    public class ProfesorBuilder : Builder
    {
        private Profesor profesor;
        private Login login;
        private UserForm form;
        public ProfesorBuilder(Profesor profesor, ref Login login)
        {
            this.profesor = profesor;
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
        public override void BuildDownloadGrades() { }
        public override void BuildConsultGrades() {
            // 
            // calificacionesLabel
            // 
            form.calificacionesLabel.AutoSize = true;
            form.calificacionesLabel.Font = new System.Drawing.Font("Microsoft YaHei", 13.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            form.calificacionesLabel.Location = new System.Drawing.Point(451, 37);
            form.calificacionesLabel.Name = "calificacionesLabel";
            form.calificacionesLabel.Size = new System.Drawing.Size(294, 31);
            form.calificacionesLabel.TabIndex = 8;
            form.calificacionesLabel.Text = "Calificaciones Alumnos";
            form.calificacionesLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // gradesTable
            // 
            form.gradesTable.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.DisplayedCells;
            form.gradesTable.AutoSizeRowsMode = System.Windows.Forms.DataGridViewAutoSizeRowsMode.DisplayedCells;
            form.gradesTable.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            form.gradesTable.Location = new System.Drawing.Point(404, 99);
            form.gradesTable.Name = "gradesTable";
            form.gradesTable.RowHeadersWidth = 51;
            form.gradesTable.RowTemplate.Height = 24;
            form.gradesTable.Size = new System.Drawing.Size(374, 259);
            form.gradesTable.TabIndex = 5;

            createGradesTable();

        }
        public override void BuildBasicInfo() {
            // 
            // dataTable
            // 
            form.dataTable.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.DisplayedCells;
            form.dataTable.AutoSizeRowsMode = System.Windows.Forms.DataGridViewAutoSizeRowsMode.DisplayedCells;
            form.dataTable.ColumnHeadersBorderStyle = System.Windows.Forms.DataGridViewHeaderBorderStyle.Sunken;
            form.dataTable.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            form.dataTable.Location = new System.Drawing.Point(25, 117);
            form.dataTable.Name = "dataTable";
            form.dataTable.RowHeadersWidth = 51;
            form.dataTable.RowTemplate.Height = 24;
            form.dataTable.Size = new System.Drawing.Size(351, 216);
            form.dataTable.TabIndex = 6;
            // 
            // DatosLabel
            // 
            form.DatosLabel.AutoSize = true;
            form.DatosLabel.Font = new System.Drawing.Font("Microsoft YaHei", 13.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            form.DatosLabel.Location = new System.Drawing.Point(157, 67);
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
        public override UserForm GetResult() {
            return form;
        }
        public void createDataTable()
        {
            form.dataTable.Columns.Add("Informacion", "Informacion");
            foreach (PropertyInfo property in profesor.GetType().GetProperties())
            {
                if (property.Name == "Alumnos")
                {
                    continue;
                }
                int rowIdx = form.dataTable.Rows.Count - 1;
                form.dataTable.Rows.Add(property.GetValue(profesor));
                form.dataTable.Rows[rowIdx].HeaderCell.Value = property.Name;
                Size textSize = TextRenderer.MeasureText(property.Name, form.dataTable.Font);
                form.dataTable.RowHeadersWidth = Math.Max(textSize.Width + 40, form.dataTable.RowHeadersWidth);
            }
        }
        public void createGradesTable()
        {
            SingletonUsers singleton = SingletonUsers.Instance;
            singleton = SingletonUsers.GetInstance();
            string[] materias = singleton.getGrades();
            List<Alumno> lista = singleton.getAlumnosFromTeacher(profesor);
            form.gradesTable.Columns.Add("Alumno", "Alumno");
            foreach (string materia in materias)
            {
                form.gradesTable.Columns.Add(materia, materia);
            }
            foreach (Alumno alumno in lista)
            {
                int rowIdx = form.gradesTable.Rows.Count - 1;
                form.gradesTable.Rows.Add();
                form.gradesTable.Rows[rowIdx].HeaderCell.Value = "ID:" + alumno.Id.ToString();
                form.gradesTable[0, rowIdx].Value = alumno.Nombre;
                Size textSize = TextRenderer.MeasureText("ID:" + alumno.Id.ToString(), form.gradesTable.Font);
                form.gradesTable.RowHeadersWidth = Math.Max(textSize.Width + 36, form.gradesTable.RowHeadersWidth);
                for (int i = 1; i <= materias.Length; i++)
                {
                    form.gradesTable[i, rowIdx].Value = alumno.Calificaciones[i - 1].ToString();
                }
            }
            return;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            login.Show();
            form.Hide();
        }

    }
}

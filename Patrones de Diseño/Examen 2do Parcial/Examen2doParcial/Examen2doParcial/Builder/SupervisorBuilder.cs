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
    public class SupervisorBuilder : Builder
    {
        private Supervisor supervisor;
        private Login login;
        private UserForm form;
        public SupervisorBuilder(Supervisor supervisor, ref Login login)
        {
            this.supervisor = supervisor;
            this.login = login;
            this.form = new UserForm();
        }
        public override void InitializeFormElements()
        {
            form.Regresar = new System.Windows.Forms.Button();
            form.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(form.components);
            form.dataTable = new System.Windows.Forms.DataGridView();
            form.DatosLabel = new System.Windows.Forms.Label();
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
            form.Regresar.Click += new System.EventHandler(button1_Click);
            // 
            // contextMenuStrip1
            // 
            form.contextMenuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            form.contextMenuStrip1.Name = "contextMenuStrip1";
            form.contextMenuStrip1.Size = new System.Drawing.Size(61, 4);
        }
        public override void BuildDownloadGrades() { }
        public override void BuildConsultGrades() { }
        public override void BuildBasicInfo() {
            // 
            // dataTable
            // 
            form.dataTable.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.DisplayedCells;
            form.dataTable.AutoSizeRowsMode = System.Windows.Forms.DataGridViewAutoSizeRowsMode.DisplayedCells;
            form.dataTable.ColumnHeadersBorderStyle = System.Windows.Forms.DataGridViewHeaderBorderStyle.Sunken;
            form.dataTable.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            form.dataTable.Location = new System.Drawing.Point(242, 110);
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
            form.DatosLabel.Location = new System.Drawing.Point(374, 60);
            form.DatosLabel.Name = "DatosLabel";
            form.DatosLabel.Size = new System.Drawing.Size(85, 31);
            form.DatosLabel.TabIndex = 7;
            form.DatosLabel.Text = "Datos";
            form.DatosLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;

            createDataTable();

            // 
            // InfoForm
            // 
            form.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            form.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            form.ClientSize = new System.Drawing.Size(800, 450);
            form.Controls.Add(form.DatosLabel);
            form.Controls.Add(form.dataTable);
            form.Controls.Add(form.Regresar);
            form.Name = "InfoForm";
            form.Text = "InfoForm";
            ((System.ComponentModel.ISupportInitialize)(form.dataTable)).EndInit();
            form.ResumeLayout(false);
            form.PerformLayout();
        }
        public override UserForm GetResult()
        {
            return form;
        }

        public void createDataTable()
        {
            form.dataTable.Columns.Add("Informacion", "Informacion");
            foreach (PropertyInfo property in supervisor.GetType().GetProperties())
            {
                if (property.Name == "Alumnos")
                {
                    continue;
                }
                int rowIdx = form.dataTable.Rows.Count - 1;
                form.dataTable.Rows.Add(property.GetValue(supervisor));
                form.dataTable.Rows[rowIdx].HeaderCell.Value = property.Name;
                Size textSize = TextRenderer.MeasureText(property.Name, form.dataTable.Font);
                form.dataTable.RowHeadersWidth = Math.Max(textSize.Width + 40, form.dataTable.RowHeadersWidth);
            }
        }
        private void button1_Click(object sender, EventArgs e)
        {
            login.Show();
            form.Hide();
        }

    }
}

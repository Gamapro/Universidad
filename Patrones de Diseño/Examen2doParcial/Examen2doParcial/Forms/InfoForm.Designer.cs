
namespace Examen2doParcial
{
    partial class InfoForm
    {
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.Regresar = new System.Windows.Forms.Button();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.gradesTable = new System.Windows.Forms.DataGridView();
            this.dataTable = new System.Windows.Forms.DataGridView();
            this.DatosLabel = new System.Windows.Forms.Label();
            this.calificacionesLabel = new System.Windows.Forms.Label();
            this.botonDescarga = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.gradesTable)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataTable)).BeginInit();
            this.SuspendLayout();
            // 
            // Regresar
            // 
            this.Regresar.Location = new System.Drawing.Point(684, 382);
            this.Regresar.Name = "Regresar";
            this.Regresar.Size = new System.Drawing.Size(84, 38);
            this.Regresar.TabIndex = 1;
            this.Regresar.Text = "Regresar";
            this.Regresar.UseVisualStyleBackColor = true;
            this.Regresar.Click += new System.EventHandler(this.button1_Click);
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(61, 4);
            // 
            // gradesTable
            // 
            this.gradesTable.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.gradesTable.Location = new System.Drawing.Point(404, 125);
            this.gradesTable.Name = "gradesTable";
            this.gradesTable.RowHeadersWidth = 51;
            this.gradesTable.RowTemplate.Height = 24;
            this.gradesTable.Size = new System.Drawing.Size(374, 105);
            this.gradesTable.TabIndex = 5;
            // 
            // dataTable
            // 
            this.dataTable.ColumnHeadersBorderStyle = System.Windows.Forms.DataGridViewHeaderBorderStyle.Sunken;
            this.dataTable.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataTable.Location = new System.Drawing.Point(25, 94);
            this.dataTable.Name = "dataTable";
            this.dataTable.RowHeadersWidth = 51;
            this.dataTable.RowTemplate.Height = 24;
            this.dataTable.Size = new System.Drawing.Size(351, 257);
            this.dataTable.TabIndex = 6;
            // 
            // DatosLabel
            // 
            this.DatosLabel.AutoSize = true;
            this.DatosLabel.Font = new System.Drawing.Font("Microsoft YaHei", 13.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.DatosLabel.Location = new System.Drawing.Point(158, 33);
            this.DatosLabel.Name = "DatosLabel";
            this.DatosLabel.Size = new System.Drawing.Size(85, 31);
            this.DatosLabel.TabIndex = 7;
            this.DatosLabel.Text = "Datos";
            this.DatosLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // calificacionesLabel
            // 
            this.calificacionesLabel.AutoSize = true;
            this.calificacionesLabel.Font = new System.Drawing.Font("Microsoft YaHei", 13.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.calificacionesLabel.Location = new System.Drawing.Point(508, 62);
            this.calificacionesLabel.Name = "calificacionesLabel";
            this.calificacionesLabel.Size = new System.Drawing.Size(178, 31);
            this.calificacionesLabel.TabIndex = 8;
            this.calificacionesLabel.Text = "Calificaciones";
            this.calificacionesLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // botonDescarga
            // 
            this.botonDescarga.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.botonDescarga.Location = new System.Drawing.Point(514, 271);
            this.botonDescarga.Name = "botonDescarga";
            this.botonDescarga.Size = new System.Drawing.Size(172, 60);
            this.botonDescarga.TabIndex = 9;
            this.botonDescarga.Text = "Descargar calificaciones";
            this.botonDescarga.UseVisualStyleBackColor = true;
            this.botonDescarga.Click += new System.EventHandler(this.botonDescarga_Click);
            // 
            // InfoForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.botonDescarga);
            this.Controls.Add(this.calificacionesLabel);
            this.Controls.Add(this.DatosLabel);
            this.Controls.Add(this.dataTable);
            this.Controls.Add(this.gradesTable);
            this.Controls.Add(this.Regresar);
            this.Name = "InfoForm";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.gradesTable)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataTable)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Button Regresar;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.DataGridView gradesTable;
        private System.Windows.Forms.DataGridView dataTable;
        private System.Windows.Forms.Label DatosLabel;
        private System.Windows.Forms.Label calificacionesLabel;
        private System.Windows.Forms.Button botonDescarga;
    }
}


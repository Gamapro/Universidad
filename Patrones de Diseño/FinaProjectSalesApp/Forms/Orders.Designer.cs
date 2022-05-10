
namespace FinaProjectSalesApp
{
    partial class Orders
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
            this.StoresLabel = new System.Windows.Forms.Label();
            this.Grid = new System.Windows.Forms.DataGridView();
            this.dataGridViewTextBoxColumn1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn2 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn3 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.ID = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Name = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Order = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.AddStore = new System.Windows.Forms.Button();
            this.ModifyStore = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.delivery = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.Grid)).BeginInit();
            this.SuspendLayout();
            // 
            // StoresLabel
            // 
            this.StoresLabel.AutoSize = true;
            this.StoresLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.StoresLabel.Location = new System.Drawing.Point(347, 9);
            this.StoresLabel.Name = "StoresLabel";
            this.StoresLabel.Size = new System.Drawing.Size(103, 32);
            this.StoresLabel.TabIndex = 2;
            this.StoresLabel.Text = "Stores";
            // 
            // Grid
            // 
            this.Grid.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.AllCells;
            this.Grid.BackgroundColor = System.Drawing.Color.GhostWhite;
            this.Grid.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.Grid.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.dataGridViewTextBoxColumn1,
            this.dataGridViewTextBoxColumn2,
            this.dataGridViewTextBoxColumn3});
            this.Grid.Location = new System.Drawing.Point(179, 72);
            this.Grid.Name = "Grid";
            this.Grid.ReadOnly = true;
            this.Grid.RowHeadersWidth = 51;
            this.Grid.RowTemplate.Height = 24;
            this.Grid.Size = new System.Drawing.Size(426, 212);
            this.Grid.TabIndex = 3;
            // 
            // dataGridViewTextBoxColumn1
            // 
            this.dataGridViewTextBoxColumn1.HeaderText = "Id";
            this.dataGridViewTextBoxColumn1.MinimumWidth = 6;
            this.dataGridViewTextBoxColumn1.Name = "dataGridViewTextBoxColumn1";
            this.dataGridViewTextBoxColumn1.ReadOnly = true;
            this.dataGridViewTextBoxColumn1.Width = 48;
            // 
            // dataGridViewTextBoxColumn2
            // 
            this.dataGridViewTextBoxColumn2.HeaderText = "Name";
            this.dataGridViewTextBoxColumn2.MinimumWidth = 6;
            this.dataGridViewTextBoxColumn2.Name = "dataGridViewTextBoxColumn2";
            this.dataGridViewTextBoxColumn2.ReadOnly = true;
            this.dataGridViewTextBoxColumn2.Width = 74;
            // 
            // dataGridViewTextBoxColumn3
            // 
            this.dataGridViewTextBoxColumn3.HeaderText = "Products";
            this.dataGridViewTextBoxColumn3.MinimumWidth = 6;
            this.dataGridViewTextBoxColumn3.Name = "dataGridViewTextBoxColumn3";
            this.dataGridViewTextBoxColumn3.ReadOnly = true;
            this.dataGridViewTextBoxColumn3.Width = 93;
            // 
            // ID
            // 
            this.ID.HeaderText = "Column1";
            this.ID.MinimumWidth = 6;
            this.ID.Name = "ID";
            this.ID.Width = 125;
            // 
            // Name
            // 
            this.Name.HeaderText = "Column1";
            this.Name.MinimumWidth = 6;
            this.Name.Name = "Name";
            this.Name.Width = 125;
            // 
            // Order
            // 
            this.Order.HeaderText = "Column1";
            this.Order.MinimumWidth = 6;
            this.Order.Name = "Order";
            this.Order.Width = 125;
            // 
            // AddStore
            // 
            this.AddStore.Location = new System.Drawing.Point(267, 346);
            this.AddStore.Name = "AddStore";
            this.AddStore.Size = new System.Drawing.Size(110, 49);
            this.AddStore.TabIndex = 4;
            this.AddStore.Text = "Add Store";
            this.AddStore.UseVisualStyleBackColor = true;
            this.AddStore.Click += new System.EventHandler(this.AddStore_Click);
            // 
            // ModifyStore
            // 
            this.ModifyStore.Location = new System.Drawing.Point(415, 346);
            this.ModifyStore.Name = "ModifyStore";
            this.ModifyStore.Size = new System.Drawing.Size(110, 49);
            this.ModifyStore.TabIndex = 5;
            this.ModifyStore.Text = "Modify Store Order";
            this.ModifyStore.UseVisualStyleBackColor = true;
            this.ModifyStore.Click += new System.EventHandler(this.ModifyStore_Click);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(123, 346);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(110, 49);
            this.button1.TabIndex = 6;
            this.button1.Text = "Exit";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // delivery
            // 
            this.delivery.Location = new System.Drawing.Point(554, 346);
            this.delivery.Name = "delivery";
            this.delivery.Size = new System.Drawing.Size(110, 49);
            this.delivery.TabIndex = 7;
            this.delivery.Text = "Delivery Route";
            this.delivery.UseVisualStyleBackColor = true;
            this.delivery.Click += new System.EventHandler(this.delivery_Click);
            // 
            // Orders
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.SlateBlue;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.delivery);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.ModifyStore);
            this.Controls.Add(this.AddStore);
            this.Controls.Add(this.Grid);
            this.Controls.Add(this.StoresLabel);
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.Grid)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label StoresLabel;
        public System.Windows.Forms.DataGridView Grid;
        public System.Windows.Forms.DataGridViewTextBoxColumn ID;
        public System.Windows.Forms.DataGridViewTextBoxColumn Name;
        public System.Windows.Forms.DataGridViewTextBoxColumn Order;
        private System.Windows.Forms.Button AddStore;
        private System.Windows.Forms.Button ModifyStore;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn1;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn2;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn3;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button delivery;
    }
}



namespace FinaProjectSalesApp
{
    partial class StoreRegister
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.colorDialog1 = new System.Windows.Forms.ColorDialog();
            this.label1 = new System.Windows.Forms.Label();
            this.textName = new System.Windows.Forms.TextBox();
            this.RegisterStore = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.idText = new System.Windows.Forms.TextBox();
            this.Exit = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(121, 19);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(165, 32);
            this.label1.TabIndex = 1;
            this.label1.Text = "Store Name";
            // 
            // textName
            // 
            this.textName.Location = new System.Drawing.Point(136, 54);
            this.textName.Name = "textName";
            this.textName.Size = new System.Drawing.Size(139, 22);
            this.textName.TabIndex = 2;
            // 
            // RegisterStore
            // 
            this.RegisterStore.Location = new System.Drawing.Point(220, 183);
            this.RegisterStore.Name = "RegisterStore";
            this.RegisterStore.Size = new System.Drawing.Size(117, 34);
            this.RegisterStore.TabIndex = 0;
            this.RegisterStore.Text = "Register Store";
            this.RegisterStore.UseVisualStyleBackColor = true;
            this.RegisterStore.Click += new System.EventHandler(this.RegisterStore_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(187, 93);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(42, 32);
            this.label2.TabIndex = 3;
            this.label2.Text = "ID";
            // 
            // idText
            // 
            this.idText.Location = new System.Drawing.Point(136, 128);
            this.idText.Name = "idText";
            this.idText.Size = new System.Drawing.Size(139, 22);
            this.idText.TabIndex = 4;
            // 
            // Exit
            // 
            this.Exit.Location = new System.Drawing.Point(74, 183);
            this.Exit.Name = "Exit";
            this.Exit.Size = new System.Drawing.Size(117, 34);
            this.Exit.TabIndex = 5;
            this.Exit.Text = "Exit";
            this.Exit.UseVisualStyleBackColor = true;
            this.Exit.Click += new System.EventHandler(this.Exit_Click);
            // 
            // StoreRegister
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.ClientSize = new System.Drawing.Size(392, 253);
            this.Controls.Add(this.Exit);
            this.Controls.Add(this.idText);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.textName);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.RegisterStore);
            this.Name = "StoreRegister";
            this.Text = "StoreRegister";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.ColorDialog colorDialog1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textName;
        private System.Windows.Forms.Button RegisterStore;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox idText;
        private System.Windows.Forms.Button Exit;
    }
}
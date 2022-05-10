
namespace FinaProjectSalesApp
{
    partial class StoreOrder
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
            this.Exit = new System.Windows.Forms.Button();
            this.register = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.comboBoxID = new System.Windows.Forms.ComboBox();
            this.infoLabel = new System.Windows.Forms.Label();
            this.vegetablesLabel = new System.Windows.Forms.Label();
            this.sodaLabel = new System.Windows.Forms.Label();
            this.breadLabel = new System.Windows.Forms.Label();
            this.sodasTextBox = new System.Windows.Forms.TextBox();
            this.breadTextBox = new System.Windows.Forms.TextBox();
            this.vegetablesTextBox = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // Exit
            // 
            this.Exit.Location = new System.Drawing.Point(256, 327);
            this.Exit.Name = "Exit";
            this.Exit.Size = new System.Drawing.Size(92, 29);
            this.Exit.TabIndex = 1;
            this.Exit.Text = "Exit";
            this.Exit.UseVisualStyleBackColor = true;
            this.Exit.Click += new System.EventHandler(this.Exit_Click);
            // 
            // register
            // 
            this.register.Enabled = false;
            this.register.Location = new System.Drawing.Point(457, 327);
            this.register.Name = "register";
            this.register.Size = new System.Drawing.Size(92, 29);
            this.register.TabIndex = 2;
            this.register.Text = "Register Order";
            this.register.UseVisualStyleBackColor = true;
            this.register.Click += new System.EventHandler(this.register_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(302, 30);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(185, 29);
            this.label1.TabIndex = 3;
            this.label1.Text = "Select store ID";
            // 
            // comboBoxID
            // 
            this.comboBoxID.FormattingEnabled = true;
            this.comboBoxID.Location = new System.Drawing.Point(336, 77);
            this.comboBoxID.Name = "comboBoxID";
            this.comboBoxID.Size = new System.Drawing.Size(121, 24);
            this.comboBoxID.TabIndex = 4;
            this.comboBoxID.Text = "Select store";
            this.comboBoxID.SelectedIndexChanged += new System.EventHandler(this.ComboBox1_SelectedIndexChanged);
            // 
            // infoLabel
            // 
            this.infoLabel.AutoSize = true;
            this.infoLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.infoLabel.Location = new System.Drawing.Point(271, 125);
            this.infoLabel.Name = "infoLabel";
            this.infoLabel.Size = new System.Drawing.Size(0, 20);
            this.infoLabel.TabIndex = 5;
            // 
            // vegetablesLabel
            // 
            this.vegetablesLabel.AutoSize = true;
            this.vegetablesLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.vegetablesLabel.Location = new System.Drawing.Point(541, 178);
            this.vegetablesLabel.Name = "vegetablesLabel";
            this.vegetablesLabel.Size = new System.Drawing.Size(0, 20);
            this.vegetablesLabel.TabIndex = 6;
            // 
            // sodaLabel
            // 
            this.sodaLabel.AutoSize = true;
            this.sodaLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.sodaLabel.Location = new System.Drawing.Point(167, 178);
            this.sodaLabel.Name = "sodaLabel";
            this.sodaLabel.Size = new System.Drawing.Size(0, 20);
            this.sodaLabel.TabIndex = 7;
            // 
            // breadLabel
            // 
            this.breadLabel.AutoSize = true;
            this.breadLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.breadLabel.Location = new System.Drawing.Point(366, 178);
            this.breadLabel.Name = "breadLabel";
            this.breadLabel.Size = new System.Drawing.Size(0, 20);
            this.breadLabel.TabIndex = 8;
            // 
            // sodasTextBox
            // 
            this.sodasTextBox.Location = new System.Drawing.Point(150, 221);
            this.sodasTextBox.Name = "sodasTextBox";
            this.sodasTextBox.Size = new System.Drawing.Size(100, 22);
            this.sodasTextBox.TabIndex = 9;
            this.sodasTextBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.sodasTextBox.Visible = false;
            // 
            // breadTextBox
            // 
            this.breadTextBox.Location = new System.Drawing.Point(347, 221);
            this.breadTextBox.Name = "breadTextBox";
            this.breadTextBox.Size = new System.Drawing.Size(100, 22);
            this.breadTextBox.TabIndex = 10;
            this.breadTextBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.breadTextBox.Visible = false;
            // 
            // vegetablesTextBox
            // 
            this.vegetablesTextBox.Location = new System.Drawing.Point(543, 221);
            this.vegetablesTextBox.Name = "vegetablesTextBox";
            this.vegetablesTextBox.Size = new System.Drawing.Size(100, 22);
            this.vegetablesTextBox.TabIndex = 11;
            this.vegetablesTextBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.vegetablesTextBox.Visible = false;
            // 
            // StoreOrder
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.vegetablesTextBox);
            this.Controls.Add(this.breadTextBox);
            this.Controls.Add(this.sodasTextBox);
            this.Controls.Add(this.breadLabel);
            this.Controls.Add(this.sodaLabel);
            this.Controls.Add(this.vegetablesLabel);
            this.Controls.Add(this.infoLabel);
            this.Controls.Add(this.comboBoxID);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.register);
            this.Controls.Add(this.Exit);
            this.Name = "StoreOrder";
            this.Text = "s";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Button Exit;
        private System.Windows.Forms.Button register;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox comboBoxID;
        private System.Windows.Forms.Label infoLabel;
        private System.Windows.Forms.Label vegetablesLabel;
        private System.Windows.Forms.Label sodaLabel;
        private System.Windows.Forms.Label breadLabel;
        private System.Windows.Forms.TextBox sodasTextBox;
        private System.Windows.Forms.TextBox breadTextBox;
        private System.Windows.Forms.TextBox vegetablesTextBox;
    }
}
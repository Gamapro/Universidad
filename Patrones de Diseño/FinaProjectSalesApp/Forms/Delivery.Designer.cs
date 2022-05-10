
namespace FinaProjectSalesApp
{
    partial class Delivery
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
            this.deliver = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.infoLabel = new System.Windows.Forms.Label();
            this.vegetablesLabel = new System.Windows.Forms.Label();
            this.sodaLabel = new System.Windows.Forms.Label();
            this.breadLabel = new System.Windows.Forms.Label();
            this.sodasTextBox = new System.Windows.Forms.TextBox();
            this.breadTextBox = new System.Windows.Forms.TextBox();
            this.vegetablesTextBox = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.idealDistribution = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // Exit
            // 
            this.Exit.Location = new System.Drawing.Point(141, 287);
            this.Exit.Name = "Exit";
            this.Exit.Size = new System.Drawing.Size(106, 43);
            this.Exit.TabIndex = 1;
            this.Exit.Text = "Cancel";
            this.Exit.UseVisualStyleBackColor = true;
            this.Exit.Click += new System.EventHandler(this.Exit_Click);
            // 
            // deliver
            // 
            this.deliver.Location = new System.Drawing.Point(403, 287);
            this.deliver.Name = "deliver";
            this.deliver.Size = new System.Drawing.Size(106, 43);
            this.deliver.TabIndex = 2;
            this.deliver.Text = "Deliver";
            this.deliver.UseVisualStyleBackColor = true;
            this.deliver.Click += new System.EventHandler(this.register_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(233, 36);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(184, 29);
            this.label1.TabIndex = 3;
            this.label1.Text = "Delivery Route";
            // 
            // infoLabel
            // 
            this.infoLabel.AutoSize = true;
            this.infoLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.infoLabel.Location = new System.Drawing.Point(195, 85);
            this.infoLabel.Name = "infoLabel";
            this.infoLabel.Size = new System.Drawing.Size(0, 20);
            this.infoLabel.TabIndex = 5;
            // 
            // vegetablesLabel
            // 
            this.vegetablesLabel.AutoSize = true;
            this.vegetablesLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.vegetablesLabel.Location = new System.Drawing.Point(465, 138);
            this.vegetablesLabel.Name = "vegetablesLabel";
            this.vegetablesLabel.Size = new System.Drawing.Size(102, 20);
            this.vegetablesLabel.TabIndex = 6;
            this.vegetablesLabel.Text = "Vegetables";
            // 
            // sodaLabel
            // 
            this.sodaLabel.AutoSize = true;
            this.sodaLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.sodaLabel.Location = new System.Drawing.Point(91, 138);
            this.sodaLabel.Name = "sodaLabel";
            this.sodaLabel.Size = new System.Drawing.Size(61, 20);
            this.sodaLabel.TabIndex = 7;
            this.sodaLabel.Text = "Sodas";
            // 
            // breadLabel
            // 
            this.breadLabel.AutoSize = true;
            this.breadLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.breadLabel.Location = new System.Drawing.Point(290, 138);
            this.breadLabel.Name = "breadLabel";
            this.breadLabel.Size = new System.Drawing.Size(59, 20);
            this.breadLabel.TabIndex = 8;
            this.breadLabel.Text = "Bread";
            // 
            // sodasTextBox
            // 
            this.sodasTextBox.Location = new System.Drawing.Point(74, 181);
            this.sodasTextBox.Name = "sodasTextBox";
            this.sodasTextBox.Size = new System.Drawing.Size(100, 22);
            this.sodasTextBox.TabIndex = 9;
            this.sodasTextBox.Text = "0";
            this.sodasTextBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // breadTextBox
            // 
            this.breadTextBox.Location = new System.Drawing.Point(271, 181);
            this.breadTextBox.Name = "breadTextBox";
            this.breadTextBox.Size = new System.Drawing.Size(100, 22);
            this.breadTextBox.TabIndex = 10;
            this.breadTextBox.Text = "0";
            this.breadTextBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // vegetablesTextBox
            // 
            this.vegetablesTextBox.Location = new System.Drawing.Point(467, 181);
            this.vegetablesTextBox.Name = "vegetablesTextBox";
            this.vegetablesTextBox.Size = new System.Drawing.Size(100, 22);
            this.vegetablesTextBox.TabIndex = 11;
            this.vegetablesTextBox.Text = "0";
            this.vegetablesTextBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(91, 85);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(459, 20);
            this.label2.TabIndex = 12;
            this.label2.Text = "Please select the number of trucks you want for the delivery.";
            // 
            // idealDistribution
            // 
            this.idealDistribution.Location = new System.Drawing.Point(271, 287);
            this.idealDistribution.Name = "idealDistribution";
            this.idealDistribution.Size = new System.Drawing.Size(106, 43);
            this.idealDistribution.TabIndex = 13;
            this.idealDistribution.Text = "Get ideal distribution";
            this.idealDistribution.UseVisualStyleBackColor = true;
            this.idealDistribution.Click += new System.EventHandler(this.idealDistribution_Click);
            // 
            // Delivery
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.MediumTurquoise;
            this.ClientSize = new System.Drawing.Size(651, 371);
            this.Controls.Add(this.idealDistribution);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.vegetablesTextBox);
            this.Controls.Add(this.breadTextBox);
            this.Controls.Add(this.sodasTextBox);
            this.Controls.Add(this.breadLabel);
            this.Controls.Add(this.sodaLabel);
            this.Controls.Add(this.vegetablesLabel);
            this.Controls.Add(this.infoLabel);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.deliver);
            this.Controls.Add(this.Exit);
            this.Name = "Delivery";
            this.Text = "s";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Button Exit;
        private System.Windows.Forms.Button deliver;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label infoLabel;
        private System.Windows.Forms.Label vegetablesLabel;
        private System.Windows.Forms.Label sodaLabel;
        private System.Windows.Forms.Label breadLabel;
        private System.Windows.Forms.TextBox sodasTextBox;
        private System.Windows.Forms.TextBox breadTextBox;
        private System.Windows.Forms.TextBox vegetablesTextBox;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button idealDistribution;
    }
}
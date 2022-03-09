namespace teste_ranking
{
    partial class Form1
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
            this.ltb1 = new System.Windows.Forms.ListBox();
            this.btnadd = new System.Windows.Forms.Button();
            this.btnord = new System.Windows.Forms.Button();
            this.tb1 = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // ltb1
            // 
            this.ltb1.FormattingEnabled = true;
            this.ltb1.Location = new System.Drawing.Point(27, 12);
            this.ltb1.Name = "ltb1";
            this.ltb1.Size = new System.Drawing.Size(252, 264);
            this.ltb1.TabIndex = 0;
            // 
            // btnadd
            // 
            this.btnadd.Location = new System.Drawing.Point(56, 354);
            this.btnadd.Name = "btnadd";
            this.btnadd.Size = new System.Drawing.Size(75, 23);
            this.btnadd.TabIndex = 1;
            this.btnadd.Text = "add";
            this.btnadd.UseVisualStyleBackColor = true;
            this.btnadd.Click += new System.EventHandler(this.btnadd_Click);
            // 
            // btnord
            // 
            this.btnord.Location = new System.Drawing.Point(204, 354);
            this.btnord.Name = "btnord";
            this.btnord.Size = new System.Drawing.Size(75, 23);
            this.btnord.TabIndex = 2;
            this.btnord.Text = "ord";
            this.btnord.UseVisualStyleBackColor = true;
            this.btnord.Click += new System.EventHandler(this.btnord_Click);
            // 
            // tb1
            // 
            this.tb1.Location = new System.Drawing.Point(106, 312);
            this.tb1.Name = "tb1";
            this.tb1.Size = new System.Drawing.Size(100, 20);
            this.tb1.TabIndex = 3;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(310, 389);
            this.Controls.Add(this.tb1);
            this.Controls.Add(this.btnord);
            this.Controls.Add(this.btnadd);
            this.Controls.Add(this.ltb1);
            this.Name = "Form1";
            this.Text = "       ";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListBox ltb1;
        private System.Windows.Forms.Button btnadd;
        private System.Windows.Forms.Button btnord;
        private System.Windows.Forms.TextBox tb1;
    }
}


namespace Conversor_cores
{
    partial class Frm_rgbxhsv
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Frm_rgbxhsv));
            this.Btn_calcular = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.TxtBlue = new System.Windows.Forms.TextBox();
            this.TxtRed = new System.Windows.Forms.TextBox();
            this.TxtGreen = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.TxtValue = new System.Windows.Forms.TextBox();
            this.TxtHue = new System.Windows.Forms.TextBox();
            this.TxtSaturation = new System.Windows.Forms.TextBox();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // Btn_calcular
            // 
            this.Btn_calcular.Location = new System.Drawing.Point(61, 122);
            this.Btn_calcular.Name = "Btn_calcular";
            this.Btn_calcular.Size = new System.Drawing.Size(100, 23);
            this.Btn_calcular.TabIndex = 29;
            this.Btn_calcular.Text = "Calcular";
            this.Btn_calcular.UseVisualStyleBackColor = true;
            this.Btn_calcular.Click += new System.EventHandler(this.Btn_calcular_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(148, 9);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(30, 15);
            this.label3.TabIndex = 20;
            this.label3.Text = "Blue";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(83, 9);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(38, 15);
            this.label2.TabIndex = 19;
            this.label2.Text = "Green";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(18, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(27, 15);
            this.label1.TabIndex = 18;
            this.label1.Text = "Red";
            // 
            // TxtBlue
            // 
            this.TxtBlue.Location = new System.Drawing.Point(148, 27);
            this.TxtBlue.Name = "TxtBlue";
            this.TxtBlue.Size = new System.Drawing.Size(56, 23);
            this.TxtBlue.TabIndex = 17;
            // 
            // TxtRed
            // 
            this.TxtRed.Location = new System.Drawing.Point(18, 27);
            this.TxtRed.Name = "TxtRed";
            this.TxtRed.Size = new System.Drawing.Size(59, 23);
            this.TxtRed.TabIndex = 15;
            // 
            // TxtGreen
            // 
            this.TxtGreen.Location = new System.Drawing.Point(83, 27);
            this.TxtGreen.Name = "TxtGreen";
            this.TxtGreen.Size = new System.Drawing.Size(59, 23);
            this.TxtGreen.TabIndex = 16;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(148, 62);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(35, 15);
            this.label4.TabIndex = 35;
            this.label4.Text = "Value";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.label5.Location = new System.Drawing.Point(83, 62);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(61, 15);
            this.label5.TabIndex = 34;
            this.label5.Text = "Saturation";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(18, 62);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(29, 15);
            this.label6.TabIndex = 33;
            this.label6.Text = "Hue";
            // 
            // TxtValue
            // 
            this.TxtValue.Enabled = false;
            this.TxtValue.Location = new System.Drawing.Point(148, 80);
            this.TxtValue.Name = "TxtValue";
            this.TxtValue.Size = new System.Drawing.Size(56, 23);
            this.TxtValue.TabIndex = 32;
            // 
            // TxtHue
            // 
            this.TxtHue.Enabled = false;
            this.TxtHue.Location = new System.Drawing.Point(18, 80);
            this.TxtHue.Name = "TxtHue";
            this.TxtHue.Size = new System.Drawing.Size(59, 23);
            this.TxtHue.TabIndex = 30;
            // 
            // TxtSaturation
            // 
            this.TxtSaturation.Enabled = false;
            this.TxtSaturation.Location = new System.Drawing.Point(83, 80);
            this.TxtSaturation.Name = "TxtSaturation";
            this.TxtSaturation.Size = new System.Drawing.Size(59, 23);
            this.TxtSaturation.TabIndex = 31;
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox1.Image")));
            this.pictureBox1.Location = new System.Drawing.Point(171, 117);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(118, 105);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox1.TabIndex = 57;
            this.pictureBox1.TabStop = false;
            // 
            // Frm_rgbxhsv
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(224, 161);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.TxtValue);
            this.Controls.Add(this.TxtHue);
            this.Controls.Add(this.TxtSaturation);
            this.Controls.Add(this.Btn_calcular);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.TxtBlue);
            this.Controls.Add(this.TxtRed);
            this.Controls.Add(this.TxtGreen);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Frm_rgbxhsv";
            this.Text = "RGB To HSV";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Frm_rgbxhsv_FormClosing);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private Button Btn_calcular;
        private Label label3;
        private Label label2;
        private Label label1;
        private TextBox TxtBlue;
        private TextBox TxtRed;
        private TextBox TxtGreen;
        private Label label4;
        private Label label5;
        private Label label6;
        private TextBox TxtValue;
        private TextBox TxtHue;
        private TextBox TxtSaturation;
        private PictureBox pictureBox1;
    }
}
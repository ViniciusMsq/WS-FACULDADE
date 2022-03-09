namespace Semaforo
{
    partial class Form1
    {
        /// <summary>
        /// Variável de designer necessária.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpar os recursos que estão sendo usados.
        /// </summary>
        /// <param name="disposing">true se for necessário descartar os recursos gerenciados; caso contrário, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código gerado pelo Windows Form Designer

        /// <summary>
        /// Método necessário para suporte ao Designer - não modifique 
        /// o conteúdo deste método com o editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.BtnVerde = new System.Windows.Forms.Button();
            this.BtnAmarelo = new System.Windows.Forms.Button();
            this.BtnVermelho = new System.Windows.Forms.Button();
            this.BtnIniciar = new System.Windows.Forms.Button();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.BtnParar = new System.Windows.Forms.Button();
            this.LbVerde = new System.Windows.Forms.Label();
            this.timer2 = new System.Windows.Forms.Timer(this.components);
            this.panel1 = new System.Windows.Forms.Panel();
            this.SuspendLayout();
            // 
            // BtnVerde
            // 
            this.BtnVerde.Location = new System.Drawing.Point(63, 36);
            this.BtnVerde.Name = "BtnVerde";
            this.BtnVerde.Size = new System.Drawing.Size(46, 41);
            this.BtnVerde.TabIndex = 0;
            this.BtnVerde.UseVisualStyleBackColor = true;
            // 
            // BtnAmarelo
            // 
            this.BtnAmarelo.Location = new System.Drawing.Point(63, 83);
            this.BtnAmarelo.Name = "BtnAmarelo";
            this.BtnAmarelo.Size = new System.Drawing.Size(46, 41);
            this.BtnAmarelo.TabIndex = 1;
            this.BtnAmarelo.UseVisualStyleBackColor = true;
            // 
            // BtnVermelho
            // 
            this.BtnVermelho.Location = new System.Drawing.Point(63, 130);
            this.BtnVermelho.Name = "BtnVermelho";
            this.BtnVermelho.Size = new System.Drawing.Size(46, 41);
            this.BtnVermelho.TabIndex = 2;
            this.BtnVermelho.UseVisualStyleBackColor = true;
            // 
            // BtnIniciar
            // 
            this.BtnIniciar.Location = new System.Drawing.Point(49, 194);
            this.BtnIniciar.Name = "BtnIniciar";
            this.BtnIniciar.Size = new System.Drawing.Size(75, 23);
            this.BtnIniciar.TabIndex = 3;
            this.BtnIniciar.Text = "Iniciar";
            this.BtnIniciar.UseVisualStyleBackColor = true;
            this.BtnIniciar.Click += new System.EventHandler(this.BtnIniciar_Click);
            // 
            // timer1
            // 
            this.timer1.Interval = 10000;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // BtnParar
            // 
            this.BtnParar.Location = new System.Drawing.Point(49, 230);
            this.BtnParar.Name = "BtnParar";
            this.BtnParar.Size = new System.Drawing.Size(75, 23);
            this.BtnParar.TabIndex = 4;
            this.BtnParar.Text = "Parar";
            this.BtnParar.UseVisualStyleBackColor = true;
            this.BtnParar.Click += new System.EventHandler(this.BtnParar_Click);
            // 
            // LbVerde
            // 
            this.LbVerde.AutoSize = true;
            this.LbVerde.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.LbVerde.Location = new System.Drawing.Point(78, 6);
            this.LbVerde.Name = "LbVerde";
            this.LbVerde.Size = new System.Drawing.Size(21, 15);
            this.LbVerde.TabIndex = 5;
            this.LbVerde.Text = "10";
            this.LbVerde.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // timer2
            // 
            this.timer2.Interval = 1000;
            this.timer2.Tick += new System.EventHandler(this.timer2_Tick);
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.panel1.Location = new System.Drawing.Point(49, 26);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(75, 157);
            this.panel1.TabIndex = 6;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(177, 267);
            this.Controls.Add(this.LbVerde);
            this.Controls.Add(this.BtnParar);
            this.Controls.Add(this.BtnIniciar);
            this.Controls.Add(this.BtnVermelho);
            this.Controls.Add(this.BtnAmarelo);
            this.Controls.Add(this.BtnVerde);
            this.Controls.Add(this.panel1);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button BtnVerde;
        private System.Windows.Forms.Button BtnAmarelo;
        private System.Windows.Forms.Button BtnVermelho;
        private System.Windows.Forms.Button BtnIniciar;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Button BtnParar;
        private System.Windows.Forms.Label LbVerde;
        private System.Windows.Forms.Timer timer2;
        private System.Windows.Forms.Panel panel1;
    }
}


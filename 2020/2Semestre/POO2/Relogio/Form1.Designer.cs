namespace Relogio
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
            this.BtnCriaRelogio = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.TxtHora = new System.Windows.Forms.TextBox();
            this.TxtSegundos = new System.Windows.Forms.TextBox();
            this.TxtMinutos = new System.Windows.Forms.TextBox();
            this.LbHorario = new System.Windows.Forms.Label();
            this.BtnAtualiza = new System.Windows.Forms.Button();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.SuspendLayout();
            // 
            // BtnCriaRelogio
            // 
            this.BtnCriaRelogio.Location = new System.Drawing.Point(163, 27);
            this.BtnCriaRelogio.Name = "BtnCriaRelogio";
            this.BtnCriaRelogio.Size = new System.Drawing.Size(100, 45);
            this.BtnCriaRelogio.TabIndex = 0;
            this.BtnCriaRelogio.Text = "Cria Relogio Base";
            this.BtnCriaRelogio.UseVisualStyleBackColor = true;
            this.BtnCriaRelogio.Click += new System.EventHandler(this.BtnCriaRelogio_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(163, 290);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(100, 45);
            this.button2.TabIndex = 1;
            this.button2.Text = "Ajustar";
            this.button2.UseVisualStyleBackColor = true;
            // 
            // TxtHora
            // 
            this.TxtHora.Location = new System.Drawing.Point(163, 139);
            this.TxtHora.Name = "TxtHora";
            this.TxtHora.Size = new System.Drawing.Size(100, 20);
            this.TxtHora.TabIndex = 2;
            // 
            // TxtSegundos
            // 
            this.TxtSegundos.Location = new System.Drawing.Point(163, 245);
            this.TxtSegundos.Name = "TxtSegundos";
            this.TxtSegundos.Size = new System.Drawing.Size(100, 20);
            this.TxtSegundos.TabIndex = 3;
            // 
            // TxtMinutos
            // 
            this.TxtMinutos.Location = new System.Drawing.Point(163, 190);
            this.TxtMinutos.Name = "TxtMinutos";
            this.TxtMinutos.Size = new System.Drawing.Size(100, 20);
            this.TxtMinutos.TabIndex = 4;
            // 
            // LbHorario
            // 
            this.LbHorario.AutoSize = true;
            this.LbHorario.Location = new System.Drawing.Point(42, 169);
            this.LbHorario.Name = "LbHorario";
            this.LbHorario.Size = new System.Drawing.Size(41, 13);
            this.LbHorario.TabIndex = 5;
            this.LbHorario.Text = "Horario";
            // 
            // BtnAtualiza
            // 
            this.BtnAtualiza.Location = new System.Drawing.Point(163, 78);
            this.BtnAtualiza.Name = "BtnAtualiza";
            this.BtnAtualiza.Size = new System.Drawing.Size(100, 45);
            this.BtnAtualiza.TabIndex = 6;
            this.BtnAtualiza.Text = "Atualiza hora";
            this.BtnAtualiza.UseVisualStyleBackColor = true;
            // 
            // timer1
            // 
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(289, 375);
            this.Controls.Add(this.BtnAtualiza);
            this.Controls.Add(this.LbHorario);
            this.Controls.Add(this.TxtMinutos);
            this.Controls.Add(this.TxtSegundos);
            this.Controls.Add(this.TxtHora);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.BtnCriaRelogio);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button BtnCriaRelogio;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.TextBox TxtHora;
        private System.Windows.Forms.TextBox TxtSegundos;
        private System.Windows.Forms.TextBox TxtMinutos;
        private System.Windows.Forms.Label LbHorario;
        private System.Windows.Forms.Button BtnAtualiza;
        private System.Windows.Forms.Timer timer1;
    }
}


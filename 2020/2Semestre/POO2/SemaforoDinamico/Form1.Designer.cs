﻿namespace SemaforoDinamico
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
            this.BtnSemaforo = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // BtnSemaforo
            // 
            this.BtnSemaforo.Location = new System.Drawing.Point(30, 280);
            this.BtnSemaforo.Name = "BtnSemaforo";
            this.BtnSemaforo.Size = new System.Drawing.Size(103, 23);
            this.BtnSemaforo.TabIndex = 0;
            this.BtnSemaforo.Text = "Criar Semaforo";
            this.BtnSemaforo.UseVisualStyleBackColor = true;
            this.BtnSemaforo.Click += new System.EventHandler(this.BtnSemaforo_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(164, 349);
            this.Controls.Add(this.BtnSemaforo);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Form1";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button BtnSemaforo;
    }
}


using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Relogio
{
    public partial class Form1 : Form
    {
        Relogio relogio;
        public Form1()
        {
            InitializeComponent();
        }

        private void BtnCriaRelogio_Click(object sender, EventArgs e)
        {
            relogio = new Relogio(int.Parse(TxtHora.Text), int.Parse(TxtMinutos.Text), int.Parse(TxtSegundos.Text));
            timer1.Enabled = true;
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            LbHorario.Text = relogio.AtualizarHora();

        }
    }
}

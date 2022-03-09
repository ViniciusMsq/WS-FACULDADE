using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Conversor_cores
{
    public partial class Frm_cmykxrgb : Form
    {
        private Form1 principal;
        public Frm_cmykxrgb(Form1 frm)
        {
            principal = frm;
            InitializeComponent();
        }

        private void Btn_calcular_Click(object sender, EventArgs e)
        {
            double R, G, B;
            double C, M, Y, K;

            C = double.Parse(TxtCyan.Text) / 100;
            M = double.Parse(TxtMagenta.Text) / 100;
            Y = double.Parse(TxtYellow.Text) / 100;
            K = double.Parse(TxtKey.Text) / 100;

            R = 255 * (1 - C) * (1 - K);
            G = 255 * (1 - M) * (1 - K);
            B = 255 * (1 - Y) * (1 - K);

            TxtRed.Text = R.ToString("F0");
            TxtGreen.Text = G.ToString("F0");
            TxtBlue.Text = B.ToString("F0");
        }

        private void Frm_cmykxrgb_FormClosing(object sender, FormClosingEventArgs e)
        {
            principal.Enabled = true;
        }
    }
}

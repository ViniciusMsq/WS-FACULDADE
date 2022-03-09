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
    public partial class Frm_rgbxcmyk : Form
    {
        private Form1 principal;
        public Frm_rgbxcmyk(Form1 frm)
        {
            principal = frm;
            InitializeComponent();
        }

        private void Btn_calcular_Click(object sender, EventArgs e)
        {
            double R, G, B, Rl, Gl, Bl;
            double C, M, Y, K;

            R = double.Parse(TxtRed.Text);
            G = double.Parse(TxtGreen.Text);
            B = double.Parse(TxtBlue.Text);

            if (R == 0 && G == 0 && B == 0)
            {
                C = 0;
                M = 0;
                Y = 0;
                K = 100;
            }
            else
            {
                Rl = R / 255;
                Gl = G / 255;
                Bl = B / 255;

                K = Math.Max(Rl, Gl);
                K = 1 - (Math.Max(K, Bl));

                C = ((1 - Rl - K) / (1 - K)) * 100;
                M = ((1 - Gl - K) / (1 - K)) * 100;
                Y = ((1 - Bl - K) / (1 - K)) * 100;
                K *= 100;
            }

            TxtCyan.Text = C.ToString("F0") + "%";
            TxtMagenta.Text = M.ToString("F0") + "%";
            TxtYellow.Text = Y.ToString("F0") + "%";
            TxtKey.Text = K.ToString("F0") + "%";

        }

        private void Frm_rgbxcmyk_FormClosing(object sender, FormClosingEventArgs e)
        {
            principal.Enabled = true;
        }
    }
}

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
    public partial class Frm_hsvxrgb : Form
    {
        private Form1 principal;
        public Frm_hsvxrgb(Form1 frm)
        {
            principal = frm;
            InitializeComponent();
        }

        private void Btn_calcular_Click(object sender, EventArgs e)
        {
            double R, G, B;
            double Rl = 0, Gl = 0, Bl = 0;
            double H, S, V;

            double C, X, M = 0;

            H = double.Parse(TxtHue.Text);
            S = double.Parse(TxtSaturation.Text);
            V = double.Parse(TxtValue.Text);

            H = (H >= 360 ? 359 : H);
            S /= 100;
            V /= 100;
            
            if(H>=0 && H < 360){
                C = V * S;
                X = C * (1 - Math.Abs((H / 60) % 2 - 1));

                M = V - C;

                if(H >= 0 && H < 60)
                {
                    Rl = C;
                    Gl = X;
                    Bl = 0;
                }else if (H >= 60 && H < 120)
                {
                    Rl = X;
                    Gl = C;
                    Bl = 0;
                }else if (H >= 120 && H < 180)
                {
                    Rl = 0;
                    Gl = C;
                    Bl = X;
                }else if (H >= 180 && H < 240)
                {
                    Rl = 0;
                    Gl = X;
                    Bl = C;
                }else if (H >= 240 && H < 300)
                {
                    Rl = X;
                    Gl = 0;
                    Bl = C;
                }else if (H >= 300 && H < 360)
                {
                    Rl = C;
                    Gl = 0;
                    Bl = X;
                }


            }

            R = (Rl + M) * 255;
            G = (Gl + M) * 255;
            B = (Bl + M) * 255;


            R = Math.Round(R);
            G = Math.Round(G);
            B = Math.Round(B);

            TxtRed.Text = R.ToString();
            TxtGreen.Text = G.ToString();
            TxtBlue.Text = B.ToString();

        }

        private void Frm_hsvxrgb_FormClosing(object sender, FormClosingEventArgs e)
        {
            principal.Enabled = true;
        }
    }
}

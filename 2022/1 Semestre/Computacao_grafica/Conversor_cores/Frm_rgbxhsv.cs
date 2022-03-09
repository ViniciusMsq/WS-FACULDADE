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
    public partial class Frm_rgbxhsv : Form
    {
        private Form1 principal;
        public Frm_rgbxhsv(Form1 frm)
        {
            principal = frm;
            InitializeComponent();
        }

        private void Btn_calcular_Click(object sender, EventArgs e)
        {
            double R=0, G=0, B=0, Rl=0, Gl=0, Bl=0;
            double H=0, S=0, V=0;

            double minimo, maximo;


            R = double.Parse(TxtRed.Text);
            G = double.Parse(TxtGreen.Text);
            B = double.Parse(TxtBlue.Text);

            if (R == 0 && G == 0 && B == 0)
            {
                H = 0;
                S = 0;
                V = 0; 
            }
            else 
            {
                R /= 255;
                G /= 255;
                B /= 255;

                minimo = Math.Min(R, G);
                minimo = Math.Min(minimo, B);

                maximo = Math.Max(R, G);
                maximo = Math.Max(maximo, B);

                V = maximo;
                S = (maximo - minimo) / maximo;

                if (S == 0)
                {
                    H = 0;
                    S = 0;
                }
                else
                {

                    if (maximo == minimo)
                    {
                        H = 0;
                    }

                    
                    if (maximo == R && G >= B)
                    {
                        H = 60 * ((G - B) / (maximo - minimo));
                    }
                    else if (maximo == R && G < B)
                    {
                        H = 60 * ((G - B) / (maximo - minimo)) + 360;
                    }
                    else if (maximo == G)
                    {
                        H = 60 * ((B - R) / (maximo - minimo)) + 120;
                    }
                    else if (maximo == B)
                    {
                        H = 60 * ((B - G) / (maximo - minimo)) + 240;
                    }

                }
                S *= 100;
                V *= 100;
            }
            /*H = Math.Round(H);
            S = Math.Round(S);
            V = Math.Round(V);*/

            TxtHue.Text = H.ToString("F0") + " °";
            TxtSaturation.Text = S.ToString("F1") + "%";
            TxtValue.Text = V.ToString("F1") + "%";
        }

        private void Frm_rgbxhsv_FormClosing(object sender, FormClosingEventArgs e)
        {
            principal.Enabled = true;
        }
    }
}

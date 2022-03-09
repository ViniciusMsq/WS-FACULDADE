using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Semaforo
{
    public partial class Form1 : Form
    {
        int cont = 10;
        public Form1()
        {
            InitializeComponent();
        }

        private void BtnIniciar_Click(object sender, EventArgs e)
        {
            timer1.Start();
            timer2.Start();
            BtnAmarelo.BackColor = Color.Yellow;
            BtnVerde.BackColor = Color.Gray;
            BtnVermelho.BackColor = Color.Gray;
        }

        private void BtnParar_Click(object sender, EventArgs e)
        {
            timer1.Stop();
            timer2.Stop();
            BtnAmarelo.BackColor = Color.Yellow;
            BtnVerde.BackColor = Color.Gray;
            BtnVermelho.BackColor = Color.Gray;
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (BtnVerde.BackColor == Color.Gray && BtnAmarelo.BackColor == Color.Gray && BtnVermelho.BackColor == Color.Gray)
            {
                BtnVerde.BackColor = Color.Green;
            }
            else
            {
                if (BtnVerde.BackColor == Color.Green) { 
                    
                    BtnVerde.BackColor = Color.Gray;
                    BtnAmarelo.BackColor = Color.Yellow;
                    BtnVermelho.BackColor = Color.Gray;
                    timer1.Interval = 5000;
                    cont = 6;
                }
                else if(BtnAmarelo.BackColor == Color.Yellow) {

                    BtnVerde.BackColor = Color.Gray;
                    BtnAmarelo.BackColor = Color.Gray;
                    BtnVermelho.BackColor = Color.Red;
                    timer1.Interval = 10000;
                    cont = 11;
                }
                else if (BtnVermelho.BackColor == Color.Red)
                {
                    BtnVerde.BackColor = Color.Green;
                    BtnAmarelo.BackColor = Color.Gray;
                    BtnVermelho.BackColor = Color.Gray;
                    cont = 11;
                }
            }
        }

        private void timer2_Tick(object sender, EventArgs e)
        {
            if (!(cont == 0)) {
                cont--;
                LbVerde.Text = "" + cont;
            }
        }
    }
}

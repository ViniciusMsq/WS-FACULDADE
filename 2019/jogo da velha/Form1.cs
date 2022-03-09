using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace jogo_da_velha
{
    struct jogadores{

       public string nome;
       public int pont;

    }

    public partial class Form1 : Form
    {

        int Xpont = 0, Opont = 0, Emp = 0, rodadas = 0;
        bool turno = true, jogoFinal = false;
        string[] texto = new string[9];
        int i = 0;
        
        int tmvet = 0;

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
           
            tmvet += 2;
            jogadores[] registro = new jogadores[tmvet];
            jogadores aux;
            

            //registro 1 recebe nome do campo 1
            registro[i].nome = tb1.Text;
            //pontos 1
            registro[i].pont = Convert.ToInt32(lbX.Text);
            //caixa de nome 2
            registro[i + 1].nome = tb2.Text;
            //pontuação 2
            registro[i + 1].pont = Convert.ToInt32(lbO.Text);

            for (int c = 0; c< tmvet; c++)

            {
                if (registro[c].pont < registro[c + 1].pont)
                {
                    aux = registro[c];
                    registro[c] = registro[c + 1];
                    registro[c + 1] = aux;
                }
            }

            
            //imprimindo os numeros e nomes na listBox
            ltbRanking.Items.Add(registro[i].pont + " - " + registro[i].nome);
            ltbRanking.Items.Add(registro[i+1].pont + " - " + registro[i+1].nome);

            i += 2;

            lbX.Text = "0";
            lbE.Text = "0";
            lbO.Text = "0";
            Xpont = 0;
            Opont = 0;
            Emp = 0;
        }

        private void BtLimpar_Click(object sender, EventArgs e)
        {
            rodadas = 0;
            jogoFinal = false;
            bt1.Text = "";
            bt2.Text = "";
            bt3.Text = "";
            bt4.Text = "";
            bt5.Text = "";
            bt6.Text = "";
            bt7.Text = "";
            bt8.Text = "";
            bt9.Text = "";

            for (int i = 0; i < 9; i++)
            {
                texto[i] = "";
            }
        }

        private void Bt1_Click(object sender, EventArgs e)
        {
            Button btn = (Button)sender;
            int btnIndex = btn.TabIndex;

            if (btn.Text == "" && jogoFinal == false)
            {
                if (turno)
                {
                    btn.Text = "X";
                    texto[btnIndex] = btn.Text;
                    rodadas++;
                    turno = false;
                    checagem(1);
                }
                else
                {
                    btn.Text = "O";
                    texto[btnIndex] = btn.Text;
                    rodadas++;
                    turno = true;
                    checagem(2);
                }
            }
        }

        void vencedor(int ganhador)
        {
            jogoFinal = true;
            if (ganhador == 1)
            {
                Xpont++ ;
                lbX.Text = Convert.ToString(Xpont);
                MessageBox.Show("jogador X ganhou");
                turno = true;
                
            }
            else
            {
                Opont++;
                lbO.Text = Convert.ToString(Opont);
                MessageBox.Show("Jogador O ganhou");
                turno = false;
            }

        }

        void checagem(int checPlayer)
        {
            string suporte = "";

            if(checPlayer == 1)
            {
                suporte = "X";
            }
            else
            {
                suporte = "O";
            }


            for (int horizontal = 0; horizontal < 8; horizontal += 3)
            {
                if(suporte == texto[horizontal])
                {
                    if(texto[horizontal] == texto[horizontal + 1] && texto[horizontal] == texto[horizontal + 2])
                    {
                        vencedor(checPlayer);
                        return;
                    }
                }
            }

            for (int vertical = 0; vertical < 3; vertical ++)
            {
                if (suporte == texto[vertical])
                {
                    if (texto[vertical] == texto[vertical + 3] && texto[vertical] == texto[vertical + 6])
                    {
                        vencedor(checPlayer);
                        return;
                    }
                }
            }

            if (texto[0] == suporte)
            {
                if (texto[0] == texto[4] && texto[0] == texto[8])
                {
                    vencedor(checPlayer);
                    return;
                }
            }

            if(texto[2] == suporte)
            {
                if (texto[2] == texto[4] && texto[4] == texto[6])
                {
                    vencedor(checPlayer);
                    return;
                }
            }

            if (rodadas > 8 && jogoFinal == false)
            {
                Emp++;
                lbE.Text = Convert.ToString(Emp);
                MessageBox.Show("Empate");
                jogoFinal = true;
                return;

            }

        }
    }
}

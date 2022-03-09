using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SemaforoDinamico
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void BtnSemaforo_Click(object sender, EventArgs e)
        {
            Semaforo s = new Semaforo(this);

        }

        public class Semaforo
        {
            Button vd;
            Button am;
            Button vm;

            Timer timer1 = new Timer();

            public Semaforo(Form form)
            {
                vd = new Button();
                vd.Size = new Size(40, 40);
                vd.Location = new Point(62, 50);
                vd.BackColor = Color.Gray;
                form.Controls.Add(vd);

                am = new Button();
                am.Size = new Size(40, 40);
                am.Location = new Point(62, 100);
                am.BackColor = Color.Yellow;
                form.Controls.Add(am);

                vm = new Button();
                vm.Size = new Size(40, 40);
                vm.Location = new Point(62, 150);
                vm.BackColor = Color.Gray;
                form.Controls.Add(vm);

                timer1.Interval = 3000;
                timer1.Enabled = true;
                timer1.Tick += new EventHandler(timer1_Tick);
            }

            private void timer1_Tick(object sender, EventArgs e)
            {
                if (vd.BackColor == Color.Gray && am.BackColor == Color.Gray && vm.BackColor == Color.Gray)
                {
                    vd.BackColor = Color.Green;
                }
                else
                {
                    if (vd.BackColor == Color.Green)
                    {

                        vd.BackColor = Color.Gray;
                        am.BackColor = Color.Yellow;
                        vm.BackColor = Color.Gray;
                        timer1.Interval = 5000;
                    }
                    else if (am.BackColor == Color.Yellow)
                    {

                        vd.BackColor = Color.Gray;
                        am.BackColor = Color.Gray;
                        vm.BackColor = Color.Red;
                        timer1.Interval = 10000;
                    }
                    else if (vm.BackColor == Color.Red)
                    {
                        vd.BackColor = Color.Green;
                        am.BackColor = Color.Gray;
                        vm.BackColor = Color.Gray;
                    }
                }
            }


        }

    }
}

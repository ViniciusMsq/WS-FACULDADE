using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Carro
{
    public partial class Form1 : Form
    {
        Carro car;

        public Form1()
        {
            InitializeComponent();
        }
        private void btnTeste_Click(object sender, EventArgs e)
        {
            car = new Carro(this);
        }

        private void btnUp_Click(object sender, EventArgs e)
        {
            car = Carro.getCarro();
            car.Up();
        }
        private void btnRigth_Click(object sender, EventArgs e)
        {
            car = Carro.getCarro();
            car.Right();
        }
        private void btnDown_Click(object sender, EventArgs e)
        {
            car = Carro.getCarro();
            car.Down();
        }
        private void btnLeft_Click(object sender, EventArgs e)
        {
            car = Carro.getCarro();
            car.Left();
        }
    }
}

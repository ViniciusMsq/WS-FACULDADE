using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Forma2d
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnCirc_Click(object sender, EventArgs e)
        {
            Circunferencia c = new Circunferencia(float.Parse(txtRaio.Text));

            lbValorC.Text = c.CalculaArea().ToString();
        }
    }
}

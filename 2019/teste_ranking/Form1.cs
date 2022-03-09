using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace teste_ranking
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnadd_Click(object sender, EventArgs e)
        {
            ltb1.Items.Add(Convert.ToString(tb1.Text));
        }

        private void btnord_Click(object sender, EventArgs e)
        {
            /*string[] a = ltb1.Items.Cast<string>().ToArray();
            ltb1.Items.Clear();

            var ret = a.OrderBy(p => int.Parse(p));

            foreach (var item in ret)
                ltb1.Items.Add(item.ToString());*/

           
        }
    }
}

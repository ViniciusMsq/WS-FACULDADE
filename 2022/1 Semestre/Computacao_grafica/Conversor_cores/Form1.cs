namespace Conversor_cores
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Btn_rgbxmcyk_Click(object sender, EventArgs e)
        {
            
            Frm_rgbxcmyk frm = new Frm_rgbxcmyk(this);

            this.Enabled = false;
            frm.Show();

        }

        private void button1_Click(object sender, EventArgs e)
        {
            Frm_cmykxrgb frm = new Frm_cmykxrgb(this);

            this.Enabled = false;
            frm.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Frm_rgbxhsv frm = new Frm_rgbxhsv(this);

            this.Enabled = false;
            frm.Show();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Frm_hsvxrgb frm = new Frm_hsvxrgb(this);

            this.Enabled = false;
            frm.Show();
        }

    }
}
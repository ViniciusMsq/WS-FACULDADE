using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing;

namespace Carro
{
    class Carro
    {
        Button principal;
        Button car;
        Image foto;
        Timer timer = new Timer();
        int op = 0;

        static Carro carro;
        public Carro(Form form)
        {
            car = new Button();
            car.Size = new Size(167, 68);
            car.Location = new Point(12, 12);
            foto = Image.FromFile(@"C:\Users\Vinicius\DriveFai\2020\2Semestre\POO2\Carro\img\CarNovo.png");
            car.Image = foto;
            car.FlatStyle = 0;
            car.FlatAppearance.BorderSize = 0;

            form.Controls.Add(car);
            
            car.Click += new EventHandler(botaoClick);
            principal = car;
            timer.Enabled = true;
            timer.Interval = 100;
            timer.Tick += new EventHandler(timer1_Tick);
            carro = this;
        }

        private void botaoClick(object sender, EventArgs e)
        {
            carro = this;
            //principal = (Button)sender;
            //principal.FlatAppearance.BorderSize = 2;
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            int velocidade = 5;
            int x = principal.Location.X;
            int y = principal.Location.Y;

            switch (op)
            {
                case 1:
                    principal.Location = new Point(x, (y - velocidade));
                    break;
                case 2:
                    principal.Location = new Point((x + velocidade), y);

                    break;
                case 3:
                    principal.Location = new Point(x, (y + velocidade));
                    break;
                case 4:
                    principal.Location = new Point((x - velocidade), y);
                    break;
            }
        }

        public void Up()
        {
            op = 1;
        }
        public void Right()
        {
            op = 2;
        }
        public void Down()
        {
            op = 3;
        }
        public void Left()
        {
            op = 4;
        }
        static public Carro getCarro()
        {
            return carro;
        }
    }
}

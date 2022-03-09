using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Forma2d
{
    class Triangulo :Forma2D
    {
        float baze=0, altura=0;

        public Triangulo() : base()
        {
        }
        public Triangulo(float baze, float altura)
        {
            this.baze = baze;
            this.altura = altura;
        }
        public override float CalculaArea()
        {
            return (baze * altura) / 2;
        }
    }
}

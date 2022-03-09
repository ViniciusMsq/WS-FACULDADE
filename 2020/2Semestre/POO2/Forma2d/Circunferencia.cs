using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Forma2d
{
    class Circunferencia : Forma2D
    {
        float raio = 0;

        public Circunferencia():base()
        {
        }
        public Circunferencia(float raio)
        {
            this.raio = raio;
        }
        public override float CalculaArea()
        {
            return (float) 3.14 * (raio * raio);
        }
    }
}

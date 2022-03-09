using System;
using System.Collections.Generic;
using System.Text;

namespace Figuras
{
    class Circulo
    {
        float raio;
        public Circulo(float raio)
        {
            this.raio = raio;
        }
        public float getRaio()
        {
            return raio;
        }
        public double area()
        {
            return Math.PI * (raio * raio);
        }
        
    }
}

using System;
using System.Collections.Generic;
using System.Text;

namespace Prova2sem
{
    class Moto
    {
        string modelo, fabricante;
        int quilometragem;

        public double TransformaKmEmMilhas()
        {
            return quilometragem / 1.609;
        }
    }
}

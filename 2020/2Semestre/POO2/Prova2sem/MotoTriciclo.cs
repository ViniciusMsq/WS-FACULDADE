using System;
using System.Collections.Generic;
using System.Text;

namespace Prova2sem
{
    class MotoTriciclo : Moto
    {
        public float TransformaKmEmMilhas()
        {
            return quilometragem / 1.589;
        }
    }
}

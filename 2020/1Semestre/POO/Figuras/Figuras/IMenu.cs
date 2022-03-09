using System;
using System.Collections.Generic;
using System.Text;

namespace Figuras
{
    class IMenu
    {
        private int escolha;

        public int LeMenu()
        {
            Console.WriteLine("Escolha a opção desejada: ");
            Console.WriteLine("1- Circulo    2- Retangulo");
            escolha = int.Parse(Console.ReadLine());
            return escolha;
        }
    }
}

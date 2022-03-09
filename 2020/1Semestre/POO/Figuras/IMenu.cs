using System;
using System.Collections.Generic;
using System.Text;

namespace Figuras
{
    class IMenu
    {
        private int escolha=0;

        public int LeMenu()
        {
            
                Console.Clear();
                Console.WriteLine("Escolha a opção desejada: ");
                Console.WriteLine("1 - Cria Circulo ");
                Console.WriteLine("2 - Mostra Circulo ");
                Console.WriteLine("3 - Criar Retangulo ");
                Console.WriteLine("4 - Mostra Retangulo ");
                Console.WriteLine("5 - Fim ");
                Console.WriteLine("Sua opção: ");
                escolha = int.Parse(Console.ReadLine());
                return escolha;
        }
        
    }
}

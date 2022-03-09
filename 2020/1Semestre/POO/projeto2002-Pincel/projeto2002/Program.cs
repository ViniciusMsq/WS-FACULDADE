using System;

namespace projeto2002
{
    class Program
    {
        static void Main(string[] args)
        {
            Pincel p = new Pincel();
            
            p.setCor("azul");
            p.setPreco(20);
            p.setTamanho(8);
            p.Pintar();
            Console.WriteLine("Tamanho " + p.getTamanho() + "cm");
            Console.WriteLine("Preço " + p.getPreco());
            Console.WriteLine("cor " + p.getCor());
            p.cor;

        }

    }
}

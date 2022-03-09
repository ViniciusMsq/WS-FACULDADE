using System;

namespace Prova2sem
{
    class Program
    {
        static void Main(string[] args)
        {
            Golfinho g = new Golfinho();
            Homem h = new Homem();
            Macaco m = new Macaco();

            Console.WriteLine("Golfinho");
            g.LocomoverSe();
            Console.WriteLine("Homem");
            h.LocomoverSe();
            Console.WriteLine("Macaco");
            m.LocomoverSe();
        }
    }

    abstract class Ex2 {

        public abstract void exemplo();
    }

    class Exemplo2: Ex2
    {
        public override void exemplo()
        {
            //modificando e aplicando diferenças
            Console.WriteLine("Boa noite");
        }
    }

}

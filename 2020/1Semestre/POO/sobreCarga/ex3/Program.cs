using System;

namespace ex4
{
    class Program
    {
        static void Main(string[] args)
        {
            Circunferencia c = new Circunferencia(2);
            Retangulo r = new Retangulo(5,3);
            Quadrado q = new Quadrado(5);

            Console.WriteLine("Circunferencia: "+ Figuras.CalcularArea(c));
            Console.WriteLine("Circunferencia: "+ Figuras.CalcularArea(r));
            Console.WriteLine("Circunferencia: "+ Figuras.CalcularArea(q));

        }
    }
}

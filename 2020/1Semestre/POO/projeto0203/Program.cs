using System;

namespace projeto0203
{
    class Program
    {
        static void Main(string[] args)
        {
            Quadrado q;
            int lado,altura;
            lado = int.Parse(Console.ReadLine());
            q = new Quadrado(lado);
            Console.WriteLine("Area = " + q.area());

            Retangulo r;
            lado = int.Parse(Console.ReadLine());
            altura = int.Parse(Console.ReadLine());
            r = new Retangulo(lado, altura);
            Console.WriteLine("area: " + r.area());
        }
    }
}

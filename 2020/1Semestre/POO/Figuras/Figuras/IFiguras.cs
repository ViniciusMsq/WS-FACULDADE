using System;
using System.Collections.Generic;
using System.Text;

namespace Figuras
{
    class IFiguras
    {
        public Circulo ILeCirculo()
        { 
            Circulo c;
            float raio;
            Console.WriteLine("raio: ");
            raio = float.Parse(Console.ReadLine());
            c = new Circulo(raio);
            return c;
        }
        public void IMostraCirculo(Circulo c)
        {
            Console.WriteLine("Raio: " + c.getRaio());
        }
        public void IMostraAreaC(Circulo c)
        {
            Console.WriteLine("Área: " + c.area());
        }
        public Retangulo ILeRetangulo()
        {
            Retangulo r;
            float lado, altura;
            Console.WriteLine("infome o valor do lado: ");
            lado = float.Parse(Console.ReadLine());
            Console.WriteLine("informe o valor da altura: ");
            altura = float.Parse(Console.ReadLine());
            r = new Retangulo(lado, altura);
            return r;
        }
        public void IMostraRetangulo(Retangulo r)
        {
            Console.WriteLine("Lado: " + r.getLado() + ", Altura: " + r.getAltura());
        }
        public void IMostraAreaR(Retangulo r)
        {
            Console.WriteLine("Área: " + r.area());
        }
    }
}

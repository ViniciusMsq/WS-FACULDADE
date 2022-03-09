using System;

namespace projeto2002
{
    class Program
    {
        static void Main(string[] args)
        {
            Quadrado quadrado = new Quadrado();
            int lado, altura, raio;
            Console.WriteLine("Informe o lado do quadrado: ");
            lado = int.Parse(Console.ReadLine());
            quadrado.setLado(lado);
            Console.WriteLine("a area é " + quadrado.AreaQuadrado());

            Trigangulo triangulo = new Trigangulo();
            Console.WriteLine("Informe a base do triangulo: ");
            lado = int.Parse(Console.ReadLine());
            triangulo.setLado(lado);
            Console.WriteLine("Informe a altura do triangulo: ");
            altura = int.Parse(Console.ReadLine());
            triangulo.setAltura(altura);
            Console.WriteLine("a area é " + triangulo.AreaTriangulo());

            Circulo circulo = new Circulo();
            Console.WriteLine("Informe o raio do circulo: ");
            raio = int.Parse(Console.ReadLine());
            circulo.setLado(raio);
            Console.WriteLine("a area é " + circulo.AreaCirculo());
        }
    }

    class Quadrado
    {
        int lado;
        public void setLado(int lado)
        {
            this.lado = lado;
        }
        public int getLado()
        {
            return lado;
        }
        public double AreaQuadrado()
        {
            return lado * lado;
        }
    }
    class Trigangulo
    {
        int lado, altura;
        public void setLado(int lado)
        {
            this.lado = lado;
        }
        public int getLado()
        {
            return lado;
        }
        public void setAltura(int altura)
        {
            this.altura = altura;
        }
        public int getAltura()
        {
            return altura;
        }
        public double AreaTriangulo()
        {
            return (lado * altura) / 2;
        }

    }
    class Circulo
    {
        int raio;
        public void setRaio(int raio)
        {
            this.raio = raio;
        }
        public int getRaio()
        {
            return raio;
        }
        public double AreaCirculo()
        {
            return 3,1415 * (raio * raio);
        }
    }
}

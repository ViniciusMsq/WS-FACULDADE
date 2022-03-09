using System;

namespace projeto1302
{
    class Program
    {
        static void Main(string[] args)
        {
            int l, a, r;
            int n1, n2, n3;
            Area area = new Area();
            Comparar c = new Comparar();

            Console.WriteLine("informe o tamanho do lado do quadrado: ");
            l = int.Parse(Console.ReadLine());
            area.AreaQuadrado(l);

            Console.WriteLine("informe o tamanho do lado do retangulo: ");
            l = int.Parse(Console.ReadLine());
            Console.WriteLine("informe o tamanho da altura do retangulo: ");
            a = int.Parse(Console.ReadLine());
            area.AreaRetangulo(l, a);

            Console.WriteLine("informe o raio do circulo: ");
            r = int.Parse(Console.ReadLine());
            area.AreaCirculo(r);

            Console.WriteLine("informe o numero 1: ");
            n1 = int.Parse(Console.ReadLine());
            Console.WriteLine("informe o numero 2: ");
            n2 = int.Parse(Console.ReadLine());
            Console.WriteLine("informe o numero 3: ");
            n3 = int.Parse(Console.ReadLine());

            //c.Maior(n1, n2, n3);
            Console.WriteLine("O maior numero é "+c.Maior(n1, n2, n3));


            /*Caneta caneta1, caneta2, caneta3;
            //instanciar - criar objeto
            caneta1 = new Caneta(); //objeto criado
            caneta2 = new Caneta();

            //caneta1.Escrever("caneta 1");
            //caneta2.Escrever("Caneta 02");

            Comparar x, y;
            x = new Comparar();*/

            /*int n1, n2;
            Console.WriteLine("n1: ");
            n1 = int.Parse(Console.ReadLine());
            Console.WriteLine("n2: ");
            n2 = int.Parse(Console.ReadLine());

            x.Menor(n1, n2);
            x.Maior(n1, n2);*/


            /*string nome;
            int idade;
            Console.WriteLine("Nome: ");
            nome = Console.ReadLine();
            Console.WriteLine("Idade: ");
            idade = int.Parse(Console.ReadLine());

            Console.WriteLine("---------------------------");
            Console.WriteLine(nome + " " + idade + " anos");*/
        }
    }

    class Area
    {
        public void AreaQuadrado(int l)
        {
            Console.WriteLine("area "+(l * l));
        }
        public void AreaRetangulo(int l, int a)
        {
            Console.WriteLine("area " + (l * a));
        }
        public void AreaCirculo(int r)
        {
            
            Console.WriteLine("area "+(Math.PI*(Math.Pow(r,2))));
        }
    }
    
    class Comparar
    {
        /*public int Menor(int n1, int n2)
        {
            if (n1 == n2)
            {
                return n1;

            }
            else if (n1 > n2)
            {
                return n2;
            }
            else
            {
                return n1;
            }
        }*/
        public int Maior(int n1, int n2, int n3)
        {

            if (n1 > n2 && n1 > n3)
            {
                //Console.WriteLine(n1);
                return n1;

            }
            else if (n2>n1 && n2>n3)
            {
                //Console.WriteLine(n2);
                return n2;
            }
            else
            {
                //Console.WriteLine(n3);
                return n3;
            }
        }
    }
    /*class Caneta
    {
        // atributos da classe
        string cor;
        int tamanho;
        double precoCompra, precoVenda;

        public void Pintar()
        {

        }
        public void Escrever(string texto)
        {
            Console.WriteLine("Escreva algo: ");
            Console.WriteLine(texto);
        }
    }*/

}

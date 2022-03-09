using System;

namespace projeto1302
{
    class Program
    {
        static void Main(string[] args)
        {
            Caneta caneta1, caneta2, caneta3;
            //instanciar - criar objeto
            caneta1 = new Caneta(); //objeto criado
            caneta2 = new Caneta();

            //caneta1.Escrever("caneta 1");
            //caneta2.Escrever("Caneta 02");

            Comparar x, y;
            x = new Comparar();
            
            int n1, n2;
            Console.WriteLine("n1: ");
            n1 = int.Parse(Console.ReadLine());
            Console.WriteLine("n2: ");
            n2 = int.Parse(Console.ReadLine());

            x.Menor(n1, n2);
            x.Maior(n1, n2);


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
    
    class Comparar
    {
        public int Menor(int n1, int n2)
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
        }
        public int Maior(int n1, int n2)
        {

            if (n1 == n2)
            {
                return n1;

            }
            else if (n1 > n2)
            {
                return n1;
            }
            else
            {
                return n2;
            }
        }
    }
    class Caneta
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
    }
}

using System;

namespace ex1
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] vet = new int[3];
            vet[0]=1;
            vet[1]=2;
            vet[2]=3;
            
            Console.WriteLine("Soma 2 valores: "+ calculadora.Somar(2,3));
            Console.WriteLine("\nSoma Vetor: "+ calculadora.Somar(vet, 3));
            Console.WriteLine("\nSomar as strings: "+ calculadora.Somar("5", "3"));
            
        }
    }
}

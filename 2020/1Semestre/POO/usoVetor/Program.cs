using System;
using LibVetor;
namespace UsoVetor
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] vetor = new int[5];
            vetor[0] = 1;
            vetor[1] = 5;
            vetor[2] = 3;
            vetor[3] = 4;
            vetor[4] = 5;

            int cont = 5;

            Console.WriteLine("Resultado da soma: " + LibVet.Somar(vetor, cont));

            Console.WriteLine("\nO maior numero do vetor: " + LibVet.MaiorValor(vetor, cont));

            Console.WriteLine("\nO menor numero do vetor: " + LibVet.MenorValor(vetor, cont));

            Console.WriteLine("\nA media do vetor: " + LibVet.Media(vetor, cont));

            Console.WriteLine("\nInforme um valor: ");
            int valor = int.Parse(Console.ReadLine());

            Console.WriteLine("\nO numero digitado foi repetido " + LibVet.ValorRepete(vetor, cont, valor) + "x");

            Console.WriteLine("\nInforme um valor: ");
            valor = int.Parse(Console.ReadLine());

            Console.WriteLine("\nPosição do vetor:  " + LibVet.Existe(vetor, cont, valor));

        }
    }
}
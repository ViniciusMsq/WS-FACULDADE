using System;
using FuncMatriz;
namespace Matriz
{
    class Program
    {
        static void Main(string[] args)
        {
            double[,] matriz = new double[2, 2];
            matriz[0, 0] = 16; matriz[0, 1] = 52;
            matriz[1, 0] = 39; matriz[1, 1] = 40;


            Console.WriteLine("Soma das Linhas e colunas: " + OpMatriz.Somar(matriz));

            OpMatriz.SomaSeparada(matriz);

            Console.WriteLine("\nDigite a linha desejada [1 ou 2]:");
            int linha = int.Parse(Console.ReadLine());
            Console.WriteLine("O maior valor da linha é: " + OpMatriz.MaiorLinha(matriz, linha));

            Console.WriteLine("\nDigite a coluna desejada [1 ou 2]:");
            int coluna = int.Parse(Console.ReadLine());
            Console.WriteLine("O maior valor da coluna é: " + OpMatriz.MaiorColuna(matriz, coluna));

        }
    }
}

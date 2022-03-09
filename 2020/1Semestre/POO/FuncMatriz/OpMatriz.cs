
using System;

namespace FuncMatriz
{
    public class OpMatriz
    {
        public static double Somar(double[,] matriz)
        {
            double resultado = 0;

            resultado += (matriz[0, 0]+matriz[0,1]+matriz[1,0]+matriz[1,1]);

            return resultado;
        }
        public static void SomaSeparada(double[,] matriz)
        {
            Console.WriteLine("|" + matriz[0, 0] + "|" + matriz[0, 1] + "|=" + (matriz[0, 0] + matriz[0, 1]) + "|");
            Console.WriteLine("|" + matriz[1, 0] + "|" + matriz[1, 1] + "|=" + (matriz[1, 0] + matriz[1, 1]) + "|");
            Console.WriteLine("|-|-|--|");
            Console.WriteLine("|" + (matriz[0, 0] + matriz[1, 0]) + "|" + (matriz[0, 1] + matriz[1, 1]) + "|");

        }
        public static double MaiorLinha(double[,] matriz, int numero)
        {
            double maior = 0;

            if(numero == 1)
            {
                if (matriz[0, 0] > matriz[0, 1])
                {
                    maior = matriz[0, 0];
                }
                else
                {
                    maior = matriz[0, 1];
                }
            }
            else if(numero == 2)
            {
                if (matriz[1, 0] > matriz[1, 1])
                {
                    maior = matriz[1, 0];
                }
                else
                {
                    maior = matriz[1, 1];
                }
            }

            return maior;
        }
        public static double MaiorColuna(double[,] matriz, int numero)
        {
            double maior = 0;

            if (numero == 1)
            {
                if (matriz[0, 0] > matriz[1, 0])
                {
                    maior = matriz[0, 0];
                }
                else
                {
                    maior = matriz[1, 0];
                }
            }
            else if (numero == 2)
            {
                if (matriz[0, 1] > matriz[1, 1])
                {
                    maior = matriz[0, 1];
                }
                else
                {
                    maior = matriz[1, 1];
                }
            }

            return maior;
        }
    }
}

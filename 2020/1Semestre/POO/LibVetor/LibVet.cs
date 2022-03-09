using System;

namespace LibVetor
{
    public class LibVet
    {
        public static double Somar(int[] vetor, int cont)
        {
            double resultado = 0;

            for (int i = 0; i < cont; i++)
            {
                resultado += vetor[i];
            }

            return resultado;
        }
        public static double MaiorValor(int[] vetor, int cont)
        {
            double maior = vetor[0];

            for (int i = 0; i < cont; i++)
            {
                if (vetor[i] > maior)
                {
                    maior = vetor[i];
                }
            }

            return maior;
        }
        public static double MenorValor(int[] vetor, int cont)
        {
            double menor = vetor[0];

            for (int i = 0; i < cont; i++)
            {
                if (vetor[i] < menor)
                {
                    menor = vetor[i];
                }
            }

            return menor;
        }
        public static double Media(int[] vetor, int cont)
        {
            double media = Somar(vetor, cont);

            return media / cont;
        }
        public static double ValorRepete(int[] vetor, int cont, int valor)
        {
            double contagem = 0;

            for (int i = 0; i < cont; i++)
            {
                if (vetor[i] == valor)
                {
                    contagem++;
                }
            }

            return contagem;
        }
        public static double Existe(int[] vetor, int cont, int valor)
        {
            double verficacao = -1;

            for (int i = 0; i < cont; i++)
            {
                if (valor == vetor[i])
                {
                    verficacao = i;
                    break;
                }
            }

            return verficacao;
        }
    }
}

using System;

namespace teste
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] vetor = new int[]{1,2,3,4,5,6};
            int resultado = 0;
            foreach(int x in vetor){
                resultado += x;
            }
            Console.WriteLine(resultado);
        }
    }
}

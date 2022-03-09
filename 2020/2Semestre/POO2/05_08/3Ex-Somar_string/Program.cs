using System;

namespace Aula0508C
{
    class Program
    {

        static void Main(string[] args)
        {
            string numeros;
            

            Console.Write("Informe numeros inteiros: ");
            numeros = Console.ReadLine();

            try{
                long soma = 0;

                for(int i = 0; i<numeros.Length; i++){
                    soma += int.Parse(numeros.Substring(i,1));
                }
                
                Console.WriteLine("{0} - ok (sua soma é {1})", numeros, soma);

            }catch{
                Console.WriteLine("{0} - não ok", numeros);
                Console.WriteLine("\nDigite apenas numeros!!!!");

            }
        }
    }
}

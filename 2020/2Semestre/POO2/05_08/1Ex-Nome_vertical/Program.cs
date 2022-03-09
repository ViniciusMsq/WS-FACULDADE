using System;

namespace Aula0508
{
    class Program
    {
        static void Main(string[] args)
        {
           string nome;
            int espaco;

            Console.Write("Digite seu nome completo: ");
            nome = Console.ReadLine();

            for (int i = 0; i < nome.Length; i++)
            {
                Console.WriteLine(nome[i]);
            }
            Console.WriteLine("-----------------");
            
            //segundo
            espaco = nome.IndexOf(" ");
            
            if(espaco == -1){
                Console.WriteLine("");
            }else{
                Console.WriteLine(nome.Substring(0, espaco));
            }
        }
    }
}

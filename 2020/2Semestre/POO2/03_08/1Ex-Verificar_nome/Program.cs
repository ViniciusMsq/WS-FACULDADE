using System;

namespace Aula0308
{
    class Program
    {
        static void Main(string[] args)
        {
            string nome;
            int espaco = 0;
            
            Console.Write("Informe seu nome completo: ");
            nome = Console.ReadLine();        

            if(nome.IndexOf(" ") == -1){
                Console.WriteLine("\nNome incompleto, Falta o sobrenome");
            }else{
                Console.WriteLine("\n{0} - Está OK", nome);

                while(nome.IndexOf(" ") != -1){
                    espaco = nome.IndexOf(" ");
                    nome = nome.Substring(espaco+1);
                }
                Console.Write(nome);
            }
            
        }
    }
}

using System;

namespace Aula0508B
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
                
                Console.Write(nome.Substring(0, nome.IndexOf(" ")+1));

                while(nome.IndexOf(" ") != -1){
                    espaco = nome.IndexOf(" ");
                    nome = nome.Substring(espaco+1);
                }
                Console.Write(nome);
            }
        }
    }
}

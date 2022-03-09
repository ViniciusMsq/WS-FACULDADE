using System;
namespace TrataString
{
    public class IMenu
    {
        public static int Menu(){//exibe o menu
            Console.Clear();
            Console.WriteLine("1 - Sobrenome");
            Console.WriteLine("2 - Nome e Sobrenome");
            Console.WriteLine("3 - Nome na vertical");
            Console.WriteLine("4 - Somar números da string");
            Console.WriteLine("5 - Validar CPF");
            Console.WriteLine("\nQualquer outro número para encerrar");

            Console.WriteLine("");
            Console.Write("Qual a opção desejada: ");
            int op = int.Parse(Console.ReadLine());

            return op;
        }

        public static string Nome(){
            Console.WriteLine("\nNome Completo: ");
            string nome =  Console.ReadLine();
            return nome;
        }
        public static string Numeros(){
            Console.WriteLine("\nDigite uma sequencia de numeros: ");
            string numeros =  Console.ReadLine();
            return numeros;
        }
        public static string LerCPF(){
            Console.Write("Informe seu CPF: ");
            string cpf = Console.ReadLine();
            return cpf;
        }
        public static string LerCNPJ(){
            Console.Write("Informe seu CNPJ: ");
            string cnpj = Console.ReadLine();
            return cnpj;
        }
    }
}
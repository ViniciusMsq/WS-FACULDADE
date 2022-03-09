using System;
using 
namespace Projeto_Estatico
{
    class Program
    {
        static void Main(string[] args)
        {
            Pessoa p = new Pessoa("Vinicius\n");
            Console.WriteLine(Pessoa.MostrarConta());
            Console.WriteLine(p.getNome());

            Pessoa p2 = new Pessoa("Julio\n");
            Console.WriteLine(Pessoa.MostrarConta());
            Console.WriteLine(p2.getNome());

            Pessoa p3 = new Pessoa("Alexandre\n");
            Console.WriteLine(Pessoa.MostrarConta());
            Console.WriteLine(p3.getNome());

        }
    }
}

using System;
namespace CadastroLivros
{
    public class IMenu
    {//Classe, que vai exibir interface do menu, para interação com usuario;

        public int Menu(){//exibe o menu
            Console.Clear();
            Console.WriteLine("1 - Cadastro de Livro");
            Console.WriteLine("2 - Consulta numero tombo");
            Console.WriteLine("3 - Consulta por Gênero");
            Console.WriteLine("4 - Lançar Empréstimo");
            Console.WriteLine("5 - Lançar Devolução do Livro");
            Console.WriteLine("6 - Finalizar");

            Console.WriteLine("");
            Console.Write("Qual a opção desejada: ");
            int op = int.Parse(Console.ReadLine());

            return op;
        }
        public int NumeroTombo(){
            Console.Clear();
            Console.WriteLine("Informe o numero do tombo");
            int numTombo = int.Parse(Console.ReadLine());

            return numTombo;
        }
        public string Genero(){
            Console.Clear();
            Console.WriteLine("Informe o genero que deseja pesquisar");
            string genero = Console.ReadLine();

            return genero;
        }
    }
}
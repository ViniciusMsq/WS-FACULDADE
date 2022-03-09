using System;
using System.Collections.Generic;
using System.Text;

namespace CadastroAluno
{
    class IMenu
    {
        private int escolha = 0;
        public int LeMenu()//Menu das opções oferecidas pelo programa
        {
            Console.Clear();
            Console.WriteLine("Informe a opção desejada");
            Console.WriteLine("1 - Cadastrar Aluno ");
            Console.WriteLine("2 - Pesquisar Aluno(RA) ");
            Console.WriteLine("3 - Listar Alunos Cadastrados ");
            Console.WriteLine("4 - Alterar dados de um aluno ");
            Console.WriteLine("5 - Listar aluno por curso  ");
            Console.WriteLine("6 - Finalizar");
            Console.WriteLine("Sua opção: ");
            escolha = int.Parse(Console.ReadLine());

            return escolha;//retorno da opção que o usuario optou
        }

        public string LeCurso(){//Metodo que vai fazer a leitura do curso criado no IMenu
            Console.Clear();
            Console.WriteLine("Informe o curso desejado:");
            string curso = Console.ReadLine();

            return curso;// retorna o curso
            
        }
        public int LeRa(){
            Console.Clear();
            Console.WriteLine("Informe o Ra do aluno: ");
            int ra = int.Parse(Console.ReadLine());
            return ra;
        }
    }
}

using System;
using System.Collections.Generic;
using System.Text;

namespace projetoInterface
{
    class IPessoa
    {
         public Pessoa ILePessoa()
        {
            Pessoa p;
            string nome, endereco;
            int idade;
            //le dados da pessoa
            Console.WriteLine("Nome: ");
            nome = Console.ReadLine();
            Console.WriteLine("Endrereço: ");
            endereco = Console.ReadLine();
            Console.WriteLine("Idade: ");
            idade = int.Parse(Console.ReadLine());
            p = new Pessoa(nome, endereco,idade);

            return p;
        }
        public void IMostraPessoa(Pessoa p)
        {
            //recebe uma pessoa e mostra os dados
            Console.WriteLine("Nome: " + p.getNome());
            Console.WriteLine("Endrereço: " + p.getEndereco());
            Console.WriteLine("Idade: " + p.getIdade());

        }
    }
}

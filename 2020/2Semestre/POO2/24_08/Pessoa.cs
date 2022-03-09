using System;

namespace _24_08
{
    public class Pessoa
    {
        string nome, endereco, cidade, cep, email;
        public Pessoa(string nome, string endereco, string cidade, string cep, string email)
        {
            this.nome = nome;
            this.endereco = endereco;
            this.cidade = cidade;
            this.cep = cep;
            this.email = email;
        }
        public string MontaLinha()
        {
            string linha = nome + ";" + endereco + ";" + cidade + ";" + cep + ";" + email;
            return linha;
        }
        public static Pessoa LerPessoa()
        {
            Console.Clear(); //limpar baffer da memoria
            Console.WriteLine("\n CADASTRAR PESSOA \n");
            Console.Write("Nome: ");
            string nome = Console.ReadLine();
            Console.Write("\nEndereco: ");
            string endereco = Console.ReadLine();
            Console.Write("\nCidade: ");
            string cidade = Console.ReadLine();
            Console.Write("\nCEP: ");
            string cep = Console.ReadLine();
            Console.Write("\nEmail: ");
            string email = Console.ReadLine();
            Pessoa pessoa = new Pessoa(nome, endereco, cidade, cep, email);
            
            return pessoa;
        }
    }
}

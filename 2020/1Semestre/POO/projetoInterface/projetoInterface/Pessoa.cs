using System;
using System.Collections.Generic;
using System.Text;

namespace projetoInterface
{
    class Pessoa
    {
        string nome, endereco;
        int idade;
        public Pessoa(string nome, string endereco, int idade)
        {
            this.nome = nome;
            this.endereco = endereco;
            this.idade = idade;
        }
        public string getNome()
        {
            return nome;
        }
        public string getEndereco()
        {
            return endereco;
        }
        public int getIdade()
        {
            return idade;
        }
    }
}

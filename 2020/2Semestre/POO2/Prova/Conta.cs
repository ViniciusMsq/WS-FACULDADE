using System;
namespace Prova
{
    public class Conta
    {
        public string Nome{get; private set;} 
        public string Endereco{get; private set;} 
        public string Cpf{get; private set;} 
        public string Telefone{get; private set;}
        public double Saldo{get; private set;}
        //public double Credito{get; private set;}
        public int Idade{get; private set;}  
        public int NumeroConta{get; private set;}

        public Conta(int numeroConta, string nome, int idade, string endereco, string cpf, string telefone){
            NumeroConta = numeroConta;
            Nome = nome;
            Idade = idade;
            Endereco = endereco;
            Cpf = cpf;
            Telefone = telefone;
            Saldo = 0.00;
            //Credito = 0.00;
        }
        public string MontaLinha()
        {
            string linha = NumeroConta + ";" + Nome +";" + Idade + ";" + Cpf + ";" + Telefone + ";" + Endereco + ";" + Saldo;
            return linha;
        }

    }
}
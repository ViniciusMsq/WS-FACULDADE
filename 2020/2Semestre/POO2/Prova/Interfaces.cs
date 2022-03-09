using System;
using Path;
namespace Prova
{
    public class Interfaces
    {
        public static int Menu(){

            Console.WriteLine("---------------MENU---------------");
            Console.WriteLine("1 - Cadastro de Contas");
            Console.WriteLine("2 - Registro de depósito");
            Console.WriteLine("3 - Registro de débito");
            Console.WriteLine("4 - Extrato por conta");
            Console.WriteLine("5 - Consulta Saldo de uma conta");
            Console.WriteLine("\nQualquer outro número para encerrar");

            Console.Write("\nQual a opção desejada: ");
            int op = int.Parse(Console.ReadLine());
            Console.Clear();
            return op;
        }//MENU
        public static int LerNumContaValidado(){
            int numeroConta;
            bool contaIgual;    
            try{
                do{
                    Console.Clear();
                    Console.Write("INFORME O NUMERO DA CONTA: ");
                    numeroConta = int.Parse(Console.ReadLine());
                    
                    contaIgual = Arquivo.validaConta(numeroConta);
                    if(contaIgual){
                        Console.WriteLine("Conta Existente");
                        Console.ReadKey();
                    }
                }while(contaIgual);

                return numeroConta;
            }catch{
                Console.WriteLine("Digite apenas numeros");
                Console.ReadKey();
                return 0;
            }
        }
        public static Conta LerConta(){
            Conta conta;
            string nome="", endereco="", cpf="", telefone="";
            int idade = 0, numeroConta = 0;

            numeroConta= LerNumContaValidado();
            if(!(numeroConta == 0)){    
                Console.Write("INFORME O SEU NOME: ");
                nome = Console.ReadLine();
                Console.Write("INFORME O SUA IDADE: ");
                idade = int.Parse(Console.ReadLine());
                Console.Write("INFORME O SEU ENDEREÇO: ");
                endereco = Console.ReadLine();
                Console.Write("INFORME O SEU CPF: ");
                cpf = Console.ReadLine();
                Console.Write("INFORME O SEU TELEFONE: ");
                telefone = Console.ReadLine();

                conta = new Conta(numeroConta, nome, idade, endereco, cpf, telefone);
                return conta;
            }else{
                return null;
            }
        }
        public static string LerDeposito(){
            int numeroConta;
            double valor=0;
                try{
                do{
                    Console.Clear();
                    Console.Write("Informe o numero da conta: ");
                    numeroConta = int.Parse(Console.ReadLine());
                    
                    if(!Arquivo.validaConta(numeroConta)){
                        Console.WriteLine("NUMERO DA CONTA INVALIDO");
                        Console.ReadKey();
                    }
                }while(!Arquivo.validaConta(numeroConta));
                do{
                    Console.Write("Informe o valor a ser depositado: ");
                    valor = double.Parse(Console.ReadLine());
                    
                    if(!(valor>0)){
                        Console. WriteLine("Valor inferior ou zero\n");
                        Console.ReadKey();
                    }
                    
                }while(!(valor>0));
                Console.WriteLine("Deposito aprovado!");
                Console.ReadKey();
                return numeroConta + ";" + valor;
            }catch{
                Console.WriteLine("Apenas numeros");
                Console.ReadKey();
                return "erro";
            }
        }
        public static string LerDebito(){
            int numeroConta;
            string tipoFatura;
            double valor;
            try{
                do{
                    Console.Clear();
                    Console.Write("Informe o numero da conta: ");
                    numeroConta = int.Parse(Console.ReadLine());
                    
                    if(!Arquivo.validaConta(numeroConta)){
                        Console.WriteLine("NUMERO DA CONTA INVALIDO");
                        Console.ReadKey();
                    }
                }while(!Arquivo.validaConta(numeroConta));

                Console.Write("Tipo da fatura: ");
                tipoFatura = Console.ReadLine();

                Console.Write("Informe o valor da fatura: ");
                valor = double.Parse(Console.ReadLine());
                
                double saldo = Registro.RetornaSaldo(Convert.ToString(numeroConta));
                
                if(saldo>=valor){
                    Console.Write("Debito aprovado!");
                    Console.ReadKey();
                    return numeroConta + ";" + tipoFatura +";" + valor;
                }else{
                    Console.Write("Debito negado, saldo insuficiente!");
                    Console.ReadKey();
                    return "erro";
                }
            }catch{
                    Console.WriteLine("Apenas numeros");
                    Console.ReadKey();
                    return "erro";
                }
        }
        public static string ContaExtrato(){
            int numeroConta;
            try{
                do{
                    Console.Clear();
                    Console.Write("Informe o numero da conta: ");
                    numeroConta = int.Parse(Console.ReadLine());
                    
                    if(!Arquivo.validaConta(numeroConta)){
                        Console.WriteLine("NUMERO DA CONTA INVALIDO");
                        Console.ReadKey();
                    }
                }while(!Arquivo.validaConta(numeroConta));

                return  Convert.ToString(numeroConta);     
            }catch{
                Console.WriteLine("Apenas numeros");
                Console.ReadKey();
                return "erro";
            }
        }
        public static void ExibirSaldo(){
            string conta = ContaExtrato();
            if(!(conta=="erro")){
                string linha = Arquivo.RetornaLinha(conta, Path.Path.registro);
                Arquivo.Exibir(linha);
                Console.ReadKey();
            }
        }
    }
}
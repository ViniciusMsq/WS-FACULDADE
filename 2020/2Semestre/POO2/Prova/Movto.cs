using System;
using System.IO;
using Path;
namespace Prova
{
    public class Movto
    {
        static string caminho = Path.Path.movimento;
        public static void MvDeposito(string linha){
            string[] elementos = linha.Split(";");
            string gravar = elementos[0] + ";Realizou um Depósito no valor de: R$ " + elementos[1];

            StreamWriter arquivo = Arquivo.AbreArquivo(caminho, true);
            Arquivo.GravaLinha(gravar, arquivo);

            arquivo.Close();
        }
        public static void MvDebito(string linha){
            string[] elementos = linha.Split(";");
            string gravar = elementos[0] + ";Pagou a fatura: "+elementos[1]+" no valor de: R$ " + elementos[2];

            StreamWriter arquivo = Arquivo.AbreArquivo(caminho, true);
            Arquivo.GravaLinha(gravar, arquivo);

            arquivo.Close();
        }
        
        public static void RetornaMovto(){
            string numConta = Interfaces.ContaExtrato();
            if(!(numConta=="erro")){
                string linha;
                StreamReader arquivo = new StreamReader(caminho);
                Console.WriteLine("EXTRATO CONTA {0}", numConta);
                while (!arquivo.EndOfStream){
                    linha = arquivo.ReadLine();
                    string[] exibir = linha.Split(";");
                    if(exibir[0]==numConta){
                        Console.WriteLine(exibir[1]);
                    }
                }
                arquivo.Close();
            }
        }
    }
}
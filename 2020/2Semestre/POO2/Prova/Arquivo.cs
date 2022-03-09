using System;
using System.IO;
using Path;
namespace Prova
{
    public class Arquivo
    {
        public static void Exibir(string linha){
            string[] exibir = linha.Split(";");
            string[] tela = {"Conta:", "Nome: ", "Idade: ", "Endereço: ", "CPF: ", "Telefone: ", "Saldo: "};
            Console.WriteLine("\n_______________________________");

            for(int i =0; i<exibir.Length; i++){
                Console.WriteLine(tela[i] + exibir[i]);
            }
        }
        public static bool VerificarExistencia(string caminho){
            try{
                StreamReader arq = new StreamReader(caminho);
                arq.Close();
                return true;
            }catch{
                
                return false;
            }
        }
        public static StreamWriter AbreArquivo(string caminho, bool tipoGracacao){
            try{   
                StreamWriter arquivo = new StreamWriter(caminho, tipoGracacao);
                return arquivo;
            }catch{
                return null;
            }
        }
        public static bool GravaLinha(string linha, StreamWriter grava)
        {   
            try{
                grava.WriteLine(linha);
                return true;
            }catch{
                return false;
            }
        }
        public static bool RetornaConta(string elemento, string caminho){
            StreamReader arq = new StreamReader(caminho);
            string linha = "";
            
            while(!arq.EndOfStream){
                linha = arq.ReadLine(); //lê a linha

                string[] exibir = linha.Split(";");
                
                if(exibir[0] == elemento){
                    arq.Close();
                    return true;
                }
            }
            arq.Close();
            return false;
        }
        public static string RetornaLinha(string elemento, string caminho){
            StreamReader arq = new StreamReader(caminho);
            string linha = "";
            int teste = 0;

            while(!arq.EndOfStream){
                linha = arq.ReadLine(); //lê a linha

                string[] exibir = linha.Split(";");
                
                if(exibir[0] == elemento){
                    teste++;
                    break;
                }
            }
            arq.Close();
            if(teste == 1){
                return linha;
            }else{
                return null;
            }
        }
        public static bool validaConta(int numeroConta){
            string caminho = Path.Path.registro;
            bool contaIgual =  false;

            bool ArquivoExiste = Arquivo.VerificarExistencia(caminho);
            
            if(ArquivoExiste){
                contaIgual = Arquivo.RetornaConta(Convert.ToString(numeroConta), caminho);
            }
            return contaIgual;
        }
    }
}
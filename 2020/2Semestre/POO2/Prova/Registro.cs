using System;
using System.IO;
using Path;
namespace Prova
{
    public class Registro
    {
        static string caminho = Path.Path.registro;
        static string caminhoAux = Path.Path.copiaAux;

        public static void RegistrarConta(){

            Conta conta = Interfaces.LerConta();

            if(!(conta==null)){
                string linha = conta.MontaLinha();

                StreamWriter arquivo = Arquivo.AbreArquivo(caminho, true);
                
                if (Arquivo.GravaLinha(linha, arquivo) == false){
                    Console.WriteLine("Erro na gravacao");
                    Console.ReadKey();
                }else{
                    Console.WriteLine("Registro gravado com sucesso !!");
                    Console.ReadKey();
                }
                arquivo.Close();
            }
        }
        public static void RegistrarDeposito(){
            string deposito = Interfaces.LerDeposito();
                if(!(deposito=="erro")){
                string[] elementos = deposito.Split(";");
                string linha = Arquivo.RetornaLinha(elementos[0], caminho);
                string[] aux = linha.Split(";");
                double novoSaldo = double.Parse(aux[6]) + double.Parse(elementos[1]);
                aux[6] = Convert.ToString(novoSaldo);
                linha = aux[0] + ";" + aux[1] + ";" + aux[2] + ";" + aux[3] + ";" + aux[4] + ";" + aux[5] + ";" + aux[6];
                
                StreamReader arquivoA = new StreamReader(caminho);
                StreamWriter arquivoB = Arquivo.AbreArquivo(caminhoAux, false);
                
                string linhaSub =""; 
                while(!arquivoA.EndOfStream){
                    linhaSub = arquivoA.ReadLine();
                    string[] verificar = linhaSub.Split(";");
                    if(elementos[0]==verificar[0]){
                        Arquivo.GravaLinha(linha, arquivoB);
                    }else{
                        Arquivo.GravaLinha(linhaSub, arquivoB);
                    }
                }
                arquivoB.Close();
                arquivoA.Close();

                StreamWriter arquivo = Arquivo.AbreArquivo(caminho, false);
                StreamReader copia = new StreamReader(caminhoAux);
                while(!copia.EndOfStream){
                    linhaSub = copia.ReadLine();

                    Arquivo.GravaLinha(linhaSub, arquivo);
                }
                arquivo.Close();
                copia.Close();

                Movto.MvDeposito(deposito);
            }
        }

        public static void RegistrarDebito(){
            string debito = Interfaces.LerDebito();

            if(!(debito == "erro")){
                string[] debitoSplit = debito.Split(";");
                string linha = Arquivo.RetornaLinha(debitoSplit[0], caminho);
                
                string[] aux = linha.Split(";");
                double novoSaldo = double.Parse(aux[6]) - double.Parse(debitoSplit[2]);
                aux[6] = Convert.ToString(novoSaldo);
                linha = aux[0] + ";" + aux[1] + ";" + aux[2] + ";" + aux[3] + ";" + aux[4] + ";" + aux[5] + ";" + aux[6];
                
                StreamReader arquivoA = new StreamReader(caminho);
                StreamWriter arquivoB = Arquivo.AbreArquivo(caminhoAux, false);
                
                string linhaSub =""; 
                while(!arquivoA.EndOfStream){
                    linhaSub = arquivoA.ReadLine();
                    string[] verificar = linhaSub.Split(";");
                    if(debitoSplit[0]==verificar[0]){
                        Arquivo.GravaLinha(linha, arquivoB);
                    }else{
                        Arquivo.GravaLinha(linhaSub, arquivoB);
                    }
                }
                arquivoB.Close();
                arquivoA.Close();

                StreamWriter arquivo = Arquivo.AbreArquivo(caminho, false);
                StreamReader copia = new StreamReader(caminhoAux);
                while(!copia.EndOfStream){
                    linhaSub = copia.ReadLine();

                    Arquivo.GravaLinha(linhaSub, arquivo);
                }
                arquivo.Close();
                copia.Close();

                Movto.MvDebito(debito);
            }
        }
        public static double RetornaSaldo(string numConta){
            string linha = Arquivo.RetornaLinha(numConta, caminho);
            string[] linhaSplit = linha.Split(";");
            return double.Parse(linhaSplit[6]);
        }
        public static void RetornaExtrato(){
            Movto.RetornaMovto();
            Console.ReadKey();
        }
    }
}
using System;
using System.IO;

namespace _24_08
{
    public static class Arquivo
    {   
        public static void Exibir(string linha){
            string[] exibir = linha.Split(";");
            string[] tela = {"Nome: ", "Endereço: ", "Cidade: ", " CEP: ", "Email: "};
            Console.WriteLine("\n_______________________________");

            for(int i =0; i<exibir.Length; i++){
                if(tela[i]=="Cidade: " && tela[i+1]==" CEP: "){
                    Console.Write(tela[i] + exibir[i]);
                }else{
                    Console.WriteLine(tela[i] + exibir[i]);
                }
            }
        }
        public static StreamWriter AbreArquivo(string caminho, bool op)
        {
            try{   
                StreamWriter arq = new StreamWriter(caminho, op);
                return arq;
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
        public static string RetornaLinha(string nome, string caminho){
            StreamReader arq = new StreamReader(caminho);
            string linha = "";
            int teste = 0;

            while(!arq.EndOfStream){
                linha = arq.ReadLine(); //lê a linha

                string[] exibir = linha.Split(";");
                
                if(exibir[0] == nome){
                    teste++;
                    break;
                }
            }
            arq.Close();
            Console.WriteLine(teste);
            if(teste == 1){
                return linha;
            }else{
                return null;
            }
        }          
    }
}
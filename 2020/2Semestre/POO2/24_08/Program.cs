using System;
using System.IO;
namespace _24_08
{
   class Program
    {   static void Main(string[] args)
        {
            Console.Clear();
            Pessoa pessoa;
            pessoa = Pessoa.LerPessoa();   // leu dados da pessoa e criou uma instância
            
            // 1) ter arquivo para gravação 
            StreamWriter grava = Arquivo.AbreArquivo(@"C:\Users\Vinic\DriveFai\2020\2Semestre\POO2\24_08\arquivoA.txt", true);
            if (grava == null)
            {   Console.WriteLine("Erro na abertura do arquivo");
                Console.ReadKey();
            }
            Console.WriteLine("PAUSE");
            Console.ReadKey();

            // 2) montar a linha para gravação "ana;rua abc;" ....
            string linha = pessoa.MontaLinha();

            // 3) escrever a linha
            if (Arquivo.GravaLinha(linha, grava) == false)
            {
                Console.WriteLine("Erro na gravacao");
            }
            else
            {
                Console.WriteLine("Registro gravado com sucesso !!");
            }

            grava.Close();
            Console.ReadKey();
            Console.Clear();
            Console.WriteLine("Exibindo pessoa cadastrada!");

            StreamReader arq2 = new StreamReader(@"C:\Users\Vinic\DriveFai\2020\2Semestre\POO2\24_08\arquivoA.txt");

            StreamWriter grava2 = Arquivo.AbreArquivo(@"C:\Users\Vinic\DriveFai\2020\2Semestre\POO2\24_08\arquivoB.txt", false);

            while(!arq2.EndOfStream){
                linha = arq2.ReadLine(); //lê a linha
                Arquivo.GravaLinha(linha, grava2);
                
                Arquivo.Exibir(linha);
            }
            arq2.Close();
            grava2.Close();
            Console.ReadKey();

            Console.Write("\nDigite o nome que deseja pesquisar no arquivo: ");
            string nome = Console.ReadLine();

            linha = Arquivo.RetornaLinha(nome, @"C:\Users\Vinic\DriveFai\2020\2Semestre\POO2\24_08\arquivoA.txt");

            Arquivo.Exibir(linha);
            
        }        
    }

    
}

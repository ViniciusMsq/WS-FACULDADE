using System;
using System.IO;

namespace Escrita_Leitura
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamWriter arq = new StreamWriter(@"C:\Users\Vinic\DriveFai\2020\2Semestre\POO2\17_08\Escrita_Leitura\arquivo.txt", true);
            arq.WriteLine("Escrevi no arquivo3");
            arq.WriteLine("Escrevi no arquivo 30");
            arq.Close();

            StreamReader arq2 = new StreamReader(@"C:\Users\Vinic\DriveFai\2020\2Semestre\POO2\17_08\Escrita_Leitura\arquivo.txt");

            while(!arq2.EndOfStream){
                string linha = arq2.ReadLine(); //lê a linha
                Console.WriteLine(linha);
            }
            arq2.Close();
        }
    }
}

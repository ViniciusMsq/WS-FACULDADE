using System;
using System.IO;

namespace _26_08
{
    public class TrataArquivo
    {
        public static StreamWriter AbreArquivo(string caminho)
        {
            try
            {   // StreamWriter arq = new StreamWriter(@"c:\teste\texto.txt", true);
                StreamWriter arq = new StreamWriter(caminho, true);
                return arq;
            }
            catch
            {
                return null;
            }
        }
        public static bool GravaLinha(string linha, StreamWriter grava)
        {   try
            {   grava.WriteLine(linha);
                return true;
            }
            catch
            {
                return false;
            }
        }
    }
}
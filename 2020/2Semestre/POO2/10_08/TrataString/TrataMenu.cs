using System;
namespace TrataString
{
    public static class TrataMenu
    {
        static string strTratamento="";
        public static void Tratamento(int op){
            switch(op){
               case 1:
                    strTratamento = IMenu.Nome();  
                    Console.WriteLine("\nSobrenome:\n" + TrataString.RetornaSobrenome(strTratamento));
                    Console.ReadKey();
                    break;
               case 2:
                    strTratamento = IMenu.Nome();   
                    Console.WriteLine("\nNome e Sobrenome:\n{0} {1}", TrataString.PrimeiroNome(strTratamento) ,TrataString.RetornaSobrenome(strTratamento));
                    Console.ReadKey();
                    break;
               case 3:
                    strTratamento = IMenu.Nome();
                    Console.WriteLine("\nNome na vertical:");
                    TrataString.ImprimeVertical(strTratamento);
                    Console.ReadKey();
                    break;
               case 4:
                    strTratamento = IMenu.Numeros();
                    Console.WriteLine("\nResultado da soma:");
                    Console.WriteLine(TrataString.Soma(strTratamento));
                    Console.ReadKey();
                    break;
               case 5:
                    strTratamento = IMenu.LerCPF();
                    Console.WriteLine("Resultado da validação:");
                    TrataString.ValidaCPF(strTratamento);
                    Console.ReadKey();
                    break;
               case 6:
                    strTratamento = IMenu.LerCNPJ();
                    Console.WriteLine("Resultado da validação:");
                    TrataString.ValidaCNPJ(strTratamento);
                    Console.ReadKey();
                    break;
               case 7:
                    break;
            }
        }
    }
}
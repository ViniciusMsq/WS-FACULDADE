using System;

namespace TrataString
{
    class Program
    {
        static void Main(string[] args)
        {  
            int op = 1;
            try{
                while ((op>0)&&(op<7)){
                    op = IMenu.Menu();

                    if((op>0)&&(op<7)){
                        TrataMenu.Tratamento(op);
                    }
                }
                
            }catch{
                Console.WriteLine("Opção invalida!");
            }
            
        }
    }
}

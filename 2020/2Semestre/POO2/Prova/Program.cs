using System;

namespace Prova
{ //TEMPO DE DESENVOLVIMENTO  =  10 HORAS;
    class Program
    {
        static void Main(string[] args)
        {
            try{
                int op;
                do{
                    Console.Clear();
                    op = Interfaces.Menu();

                    if(op>0 && op<7){
                        TrataMenu.Tratamento(op);
                    }
                }while(op>0 && op<7);
                
            }catch{
                Console.WriteLine("Programa Finalizado!");
            }
        }
    }
}

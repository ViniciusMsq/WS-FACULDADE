using System;
namespace Prova
{
    public class TrataMenu
    {
        public static void Tratamento(int op){

            switch(op){
               case 1: 
                    Registro.RegistrarConta();
                    break;
               case 2:
                    Registro.RegistrarDeposito();
                    break;
               case 3:
                    Registro.RegistrarDebito();
                    break;
               case 4:
                    Registro.RetornaExtrato();
                    break;
               case 5:
                    Interfaces.ExibirSaldo();
                    break;
            }
        }
    }
}
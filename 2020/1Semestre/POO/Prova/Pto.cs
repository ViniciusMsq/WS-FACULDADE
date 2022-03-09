using System;

namespace Prova
{
    public class Pto
    {
        int x = 0 , y = 0;
        static int conta = 0;

        public Pto(int x, int y){
            this.x = x;
            this.y = y;
            conta++;
        }
        public void TrocaPto(int x, int y){
            this.x = x;
            this.y = y;
        }
        public void Numeros(){
            Console.WriteLine("x: "+x+" y: "+y);
        }
        public static void InicializaConta(){
            conta = 0;
        }
        public static void InicializaConta(int valor){
            conta = valor;
        }
        public static int RetornaConta(){
            return conta;
        }

    }
}
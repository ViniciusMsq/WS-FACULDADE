using System;
namespace ex2
{
    public static class triangulo
    {
        public static double calculadora(int bases, int altura){
            return (bases*altura)/2;
        }
        public static double calculadora(int l1, int l2, int l3){
            double resultado = l1+l2+l3;
            resultado = resultado/2;
            double x = Math.Sqrt(resultado*(resultado-l1)*(resultado-l2)*(resultado-l3));
            return x;
        }
    }
}
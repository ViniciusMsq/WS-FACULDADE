using System;

namespace ex4
{
    public static class Figuras
    {
        public static double CalcularArea(Circunferencia x){
            return Math.PI*(Math.Pow(x.getRaio(),2));
        }
        public static double CalcularArea(Retangulo x){
            return (x.getAltura()*x.getLado());
        }
        public static double CalcularArea(Quadrado x){
            return Math.Pow(x.getLado(),2);
        }
    }
}
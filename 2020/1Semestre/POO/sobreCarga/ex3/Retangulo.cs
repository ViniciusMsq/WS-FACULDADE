using System;

namespace ex4
{
    public class Retangulo
    {
        private double altura, lado;
        public Retangulo(double altura, double lado){
            this.altura = altura;
            this.lado = lado;
        }
        public double getAltura(){
            return altura;
        }
        public double getLado(){
            return lado;
        }
    }
}
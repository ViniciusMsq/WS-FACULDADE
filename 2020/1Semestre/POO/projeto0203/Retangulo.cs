using System;
using System.Collections.Generic;
using System.Text;

namespace projeto0203
{
    class Retangulo
    {
        int lado, altura;
        public Retangulo(int lado, int altura)
        {
            this.lado = lado;
            this.altura = altura;
        }
        public void setLado(int lado)
        {
            this.lado = lado;
        }
        public void setAltura(int altura)
        {
            this.altura = altura;
        }
        public int getLado()
        {
            return lado;
        }
        public int getAltura()
        {
            return altura;
        }
        public double area()
        {
            return lado * altura;
        }
    }
}

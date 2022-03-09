using System;
using System.Collections.Generic;
using System.Text;

namespace Figuras
{
    class Retangulo
    {
        float lado, altura;

        public Retangulo(float lado, float altura)
        {
            this.lado = lado;
            this.altura = altura;
        }
        public float getLado()
        {
            return lado;
        }
        public float getAltura()
        {
            return altura;
        }
        public double area()
        {
            return lado * altura;
        }
    }
}

using System;
using System.Collections.Generic;
using System.Text;

namespace projeto0203
{
    class Quadrado
    {
        int lado;
        //metódos construtores
        //objetivo: inicialzar as variaveis do obj
        //caracteristicas:
        // tem o mesmo nome da classe,  nao devolve valor(sem void)
        //normalmente recebem parametros para serem atribuidos aos atributos da class
        //geralmente publicos
        //sao executados quando o objeto é instanciado

        public Quadrado(int lado)
        {
            this.lado = lado;
        }
        public void setLado(int lado)
        {
            this.lado = lado;
        }
        public int getLado()
        {
            return lado;
        }
        public double area()
        {
            return lado * lado;
        }
    }
}

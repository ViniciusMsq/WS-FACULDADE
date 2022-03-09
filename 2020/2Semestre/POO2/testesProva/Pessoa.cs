using System;
using System.Collections.Generic;
using System.Text;

namespace testesProva
{
    abstract class Pessoa
    {
        //private string nome;
        protected string nome;

        public Pessoa()
        {

        }
        public Pessoa(string nome)
        {
            this.nome = nome;
        }
        public abstract void MetodoAbstrato(int n1, int n2);
    }
}

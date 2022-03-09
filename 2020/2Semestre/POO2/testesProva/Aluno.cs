using System;
using System.Collections.Generic;
using System.Text;

namespace testesProva
{
    class Aluno : Pessoa
    {
        private string ra;
        public Aluno()
        {

        }
        public Aluno(string nome): base(nome)
        {

        }
        /*public Aluno(string nome, string ra):base(nome)
        {
            this.ra = ra;
        }*/
        public Aluno(string nome, string ra)
        {
            this.nome = nome;
            this.ra = ra;
        }
        public override void MetodoAbstrato(int n1, int n2)
        {
            Console.WriteLine("JESUS");
        }
    }
}

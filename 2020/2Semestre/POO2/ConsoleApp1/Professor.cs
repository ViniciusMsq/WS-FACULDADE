using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp1
{
    class Professor : Funcionario
    {
        private int aulas;
        
        public Professor(string nome, int id, double salario) : base(nome, id, salario)
        {

        }
        public Professor(string nome, int id, double salario, int aulas)
        {
            this.nome = nome;
            this.id = id;
            this.salario = salario;
            this.aulas = aulas;
        }
        public override double SalarioMes()
        {
            //return salario*aulas;
            return base.SalarioMes() * aulas;
        }
    }
}

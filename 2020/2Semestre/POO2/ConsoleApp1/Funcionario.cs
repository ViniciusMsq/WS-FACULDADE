using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp1
{
    class Funcionario
    {
        protected string nome;
        protected int id;
        protected double salario;

        public Funcionario()// É necessario implementar um contrutor base(sem parametros)
                            // em virtude de termos implementado uma sobrecarga de metodo
                            // funcionario( na classe professor) com parametros
        {

        }
        public Funcionario(string nome, int id, double salario)
        {
            this.nome = nome;
            this.id = id;
            this.salario = salario;
        }

        public virtual double SalarioMes()
        {
            return salario;
        }

    }
}

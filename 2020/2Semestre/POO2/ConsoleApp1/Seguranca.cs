using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp1
{
    class Seguranca : Funcionario
    {

        public Seguranca(string nome, int id, double salario ):base(nome, id, salario)
        {

        }
        public override double SalarioMes()
        {
            return base.SalarioMes() * 1.05;
            //return salario + (salario * 0.05); 
        }
    }
}

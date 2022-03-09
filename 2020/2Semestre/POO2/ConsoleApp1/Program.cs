using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            Comum c = new Comum("Vincius", 1, 1000);
            Console.WriteLine("SALARIO COMUM:");
            Console.WriteLine(c.SalarioMes());

            Console.WriteLine("----------------------");

            Seguranca s = new Seguranca("Mesquini", 2, 1000);
            Console.WriteLine("SALARIO SEGURANÇA:");
            Console.WriteLine(s.SalarioMes());

            Console.WriteLine("----------------------");

            Professor p = new Professor("Oliveira", 3, 30, 100);
            Console.WriteLine("SALARIO PROFESSOR:");
            Console.WriteLine(p.SalarioMes());
        }
    }
}

using System;
namespace Prova
{
    class Program
    {
        static void Main(string[] args)
        {
            Pto.InicializaConta();
            Pto ponto1 = new Pto(1,2);
            Pto ponto2 = new Pto(3,4);
            Pto ponto3 = new Pto(5,6);
            
            Pto.InicializaConta(3);
            Console.WriteLine("teste antes de alterar:");
            ponto2.Numeros();
            Console.WriteLine("teste depois de alterar:");
            ponto2.TrocaPto(6,3);
            ponto2.Numeros();
            Console.WriteLine("testando se conta recebeu parametro");
            Console.WriteLine(Pto.RetornaConta());
        }
    }
}

using System;

namespace projetoInterface
{
    class Program
    {
        static void Main(string[] args)
        {
            Pessoa p;
            IPessoa ip;
            ip = new IPessoa();
            p =  ip.ILePessoa();
            
            ip.IMostraPessoa(p);


        }
    }
}

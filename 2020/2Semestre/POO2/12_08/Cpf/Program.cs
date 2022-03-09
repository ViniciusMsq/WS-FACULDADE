using System;

namespace Cpf
{
    class Program
    {
        static void Main(string[] args)
        {
            
            string cpf = TrataCpf.LerCPF();
            cpf = TrataCpf.TirarFormCpf(cpf);

            if(TrataCpf.ValidarNumerosCpf(cpf)){

                bool valido = TrataCpf.CalculoCPF(cpf);

                if(valido){
                    Console.WriteLine(TrataCpf.PorFormCpf(cpf));
                    Console.WriteLine("Valido!");
                }else{
                    Console.WriteLine(TrataCpf.PorFormCpf(cpf));
                    Console.WriteLine("Invalido!");
                }
            }else{
                Console.WriteLine("Digite um cpf valido");
            }
            
        }
    }
}

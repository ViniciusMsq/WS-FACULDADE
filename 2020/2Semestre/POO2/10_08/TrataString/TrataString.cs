using System;

namespace TrataString
{
    public static class TrataString
    {
        public static int ValidarString(string nome){

            return nome.IndexOf(" ");//if nao achar retorna -1, caso contrario retorna posição
        }
        public static void ImprimeVertical(string nome){  
            
            for (int i = 0; i < nome.Length; i++)   // imprime na vertical
            {
                Console.WriteLine(nome.Substring(i, 1));
            }
            
        }
        public static string PrimeiroNome(string nome){  

            int ver = ValidarString(nome);

            if (ver == -1){
                return "Nome incompleto";
            }
            
            // monta o primeiro nome para retornar
            return nome.Substring(0, ver);
        }
        public static string RetornaSobrenome(string nome){
            
            if (ValidarString(nome) == -1){
                return "Nome Incompleto";
            }

            do{  
                nome = nome.Substring(1+ValidarString(nome));
            } while (ValidarString(nome) != -1);
            
            return nome;
        }
        public static string Soma(string numeros){

            try{
                long soma = 0;

                for(int i = 0; i<numeros.Length; i++){
                    soma += int.Parse(numeros.Substring(i,1));
                }
                
               return numeros + " - ok (sua soma é "+ soma +")";

            }catch{
                return numeros + " - não ok";
            }
        }
        public static void ValidaCPF(string cpf){
            
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
        public static void ValidaCNPJ(string cnpj){
            cnpj = TrataCnpj.TirarForm(cnpj);

            Console.WriteLine(TrataCnpj.Calculo(cnpj));
            
        }
    }
}
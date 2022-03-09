using System;
namespace Cpf
{
    public class TrataCpf
    {
        public static string LerCPF(){
            Console.Write("Informe seu CPF: ");
            string cpf = Console.ReadLine();
            return cpf;
        }
        public static bool ValidarNumerosCpf(string cpf){
            int diferente = 0;

            for(int i = 0; i<11; i++){
                if(cpf.Substring(i,1)!=cpf.Substring(i+1,1)){
                    diferente = 1;
                    break;
                }
            }

            if(diferente == 0){
                return false;
            }else{
                try{
                    long teste = Convert.ToInt64(cpf); 
                    return true;
                }catch{
                    return false;
                }
            }
        }
        public static string TirarFormCpf(string cpf){
            return cpf.Replace(".", string.Empty).Replace("-", string.Empty).Replace("/", string.Empty);
        }
        public static string PorFormCpf(string cpf){
            return Convert.ToUInt64(cpf).ToString(@"000\.000\.000\-00");

        }
        public static bool CalculoCPF(string cpf){

            string digitosSeparados = cpf.Substring(0,9);
            int soma = 0, resto=0, dv1 = 0, dv2 = 0;
            
            // Primeiro digito dv1 ----------------------------------------------
            for(int i = 10, cont=0; i>1 ;i--, cont++){
                soma+= i * int.Parse(digitosSeparados.Substring(cont, 1));
            }

            resto = soma %11;

            dv1 = 11 - resto;

            if(dv1 >= 10){
                dv1 = 0;
            }
            // -------------------------------------------------------------------
            if(Convert.ToString(dv1)!=cpf.Substring(9,1)){
                return false;
            }
            // segundo digito dv2 ------------------------------------------------
            digitosSeparados += Convert.ToString(dv1);
            soma= 0;
            for(int i = 11, cont=0; i>1 ;i--, cont++){
                soma+= i * int.Parse(digitosSeparados.Substring(cont, 1));
            }

            resto = soma %11;

            dv2 = 11 - resto;

            if(dv2 >= 10){
                dv2 =0;
            }
            // -------------------------------------------------------------------

            if(Convert.ToString(dv2)!=cpf.Substring(10,1)){
                return false;
            }else{
                return true;
            }
        }
    }
}
namespace TrataString
{
    public class TrataCnpj
    {
        /*  59.541.264/0001-03
            O primeiro bloco representa a inscrição do CNPJ: 59.541.264
            O segundo bloco representa um código para matriz ou filial: 0001-03
            O terceiro bloco são os dígitos verificadores: 03
        */
        public static string TirarForm(string cnpj){
            return cnpj.Replace(".", string.Empty).Replace("-", string.Empty).Replace("/", string.Empty);
        }
        // Pegar os 12 primeiros e inverter adicionar pesos 2 a 9
        public static string Calculo(string cnpj){
            string cnpjInvertido="";
            
            for(int i =13; i>-1; i--){
                cnpjInvertido += cnpj[i];
            }
            
            string digitosSeparados = cnpjInvertido.Substring(2);

            return digitosSeparados;
            
        }
        //somar o resultado

        // calcular resto por 11

        // subtrarir resultado de 11, se for 10 ou > = 0;
    }
}
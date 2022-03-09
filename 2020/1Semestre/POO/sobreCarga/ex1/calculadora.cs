namespace ex1
{
    public static class calculadora
    {   
        
        public static int Somar(int x, int y){
            return (x + y);
        }
        public static int Somar(int[] vet, int tam){
            int resultado=0;
            for(int i =0; i<tam; i++){
                resultado+=vet[i];
            }
            return resultado;
        }
        public static int Somar(string x, string y){
            return int.Parse(x)+int.Parse(y);
        }
    }
}
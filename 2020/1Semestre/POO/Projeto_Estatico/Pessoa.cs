namespace Projeto_Estatico
{
    public class Pessoa
    {
        static int conta = 0;
        string nome;
        public Pessoa(string nome){
            this.nome = nome;
            conta++;
        }

        public static int MostrarConta(){

            return conta;
        }

        public void setNome(string nome){
            this.nome = nome;
        }
        public string getNome(){
            return nome;
        }
    }
}
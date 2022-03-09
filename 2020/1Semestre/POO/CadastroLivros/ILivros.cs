using System;
namespace CadastroLivros
{
    public class ILivros
    {
        //Metodo para cadastrar os Livros
        public Livro CadLivros(){

            Livro livro;
            string titulo, autor, genero, status;
            int numTombo;
            Console.Clear();
            Console.WriteLine("informe o titulo do livro");
            titulo = Console.ReadLine();
            Console.WriteLine("Informe o nome do autor");
            autor = Console.ReadLine();
            Console.WriteLine("Informe o genero textual do livro");
            genero = Console.ReadLine();
            Console.WriteLine("Infome o Status (D/E)");
            status = Console.ReadLine();
            Console.WriteLine("Informe o numero do tombo");
            numTombo = int.Parse(Console.ReadLine());
            
            livro = new Livro(titulo, autor, genero, status, numTombo);

            return livro;
        }
        //consultando o livro pelo Tombo
        public void ConsTombo(Livro[] vLivros, int indice, int numTombo){

            Console.Clear();
            int verificação = 0;//usar para fazer um teste rapido se entra na condição de validade
            if(indice==0){
                Console.WriteLine("Nenhum foi cadastrado ainda!");
            }
            else{
                for(int i = 0; i<indice; i++){//for para revisar o vetor
                    if(vLivros[i].getNumTombo()==numTombo){// verificar igualdade do tombo
                        verificação ++;
                        Console.WriteLine("Titulo: " + vLivros[i].getTitulo());
                        Console.WriteLine("Autor: "+ vLivros[i].getAutor());
                        Console.WriteLine("Genero: "+ vLivros[i].getGenero());
                        Console.WriteLine("Status: "+ vLivros[i].getStatus());
                        Console.WriteLine("Numero Tombo: "+ vLivros[i].getNumTombo());
                        break;
                    }
                }
            }
            if(verificação == 0){//teste rapido para ver se entrou na condição anterior
                Console.WriteLine("Não existe nenhum livro com esse número!");
            }

            Console.ReadKey();
        }
        //Consultando todos os livros do mesmo genero
        public void ConsGenero(Livro[] vLivros, int indice, string genero){
            Console.Clear();
            int verificacao = 0;
            if(indice==0){
                Console.WriteLine("Nenhum foi cadastrado ainda!");
            }
            else{
                for(int i = 0; i<indice; i++){
                    if(vLivros[i].getGenero()==genero){
                        verificacao ++;
                        Console.WriteLine("Livro ["+(i+1)+"]");
                        Console.WriteLine("Titulo: " + vLivros[i].getTitulo());
                        Console.WriteLine("Autor: "+ vLivros[i].getAutor());
                        Console.WriteLine("Genero: "+ vLivros[i].getGenero());
                        Console.WriteLine("Status: "+ vLivros[i].getStatus());
                        Console.WriteLine("Numero Tombo: "+ vLivros[i].getNumTombo());
                        Console.WriteLine("---------------------------");
                    }
                }
            }
            if(verificacao == 0){
                Console.WriteLine("Não existe nenhum livro com esse genero!");
            }

            Console.ReadKey();
        }
        //Lançando o emprestimo 
        public void Emprestimo(Livro[] vLivros, int indice, int numTombo){
            Console.Clear();
            int verificacao = 0;
            if(indice==0){
                Console.WriteLine("Nenhum foi cadastrado ainda!");
            }
            else{
                for(int i = 0; i<indice; i++){
                    if(vLivros[i].getNumTombo()==numTombo){
                        verificacao ++;
                        if(vLivros[i].getStatus()=="D" || vLivros[i].getStatus()=="d"){
                            vLivros[i].setStatus("E");
                            Console.WriteLine("Emprestimo Lançado");
                        }else{
                            Console.WriteLine("Livro ja emprestado");
                        }
                    }
                }
            }
            if(verificacao == 0){
                Console.WriteLine("Não existe nenhum livro com esse número!");
            }

            Console.ReadKey();
        }
        //Lançando devolução
        public void Disponivel(Livro[] vLivros, int indice, int numTombo){
            Console.Clear();
            int verificacao = 0;
            if(indice==0){
                Console.WriteLine("Nenhum foi cadastrado ainda!");
            }
            else{
                for(int i = 0; i<indice; i++){
                    if(vLivros[i].getNumTombo()==numTombo){
                        verificacao ++;
                        if(vLivros[i].getStatus()=="E" || vLivros[i].getStatus()=="e"){
                            vLivros[i].setStatus("D");
                            Console.WriteLine("Devolução Lançada");
                        }else{
                            Console.WriteLine("Livro ja Disponivel");
                        }
                    }
                }
            }
            if(verificacao == 0){
                Console.WriteLine("Não existe nenhum livro com esse número!");
            }
           
            Console.ReadKey();
        }
    }
}
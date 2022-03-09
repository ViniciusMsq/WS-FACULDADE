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
        public void ConsTombo(Livro[] vLivros, int indice, int numTombo){

            Console.Clear();
            int verificação = 0;
            if(indice==0){
                Console.WriteLine("Nenhum foi cadastrado ainda!");
            }
            else{
                for(int i = 0; i<indice; i++){
                    if(vLivros[i].getNumTombo()==numTombo){
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
            if(verificação == 0){
                Console.WriteLine("Não existe nenhum livro com esse número!");
            }

            Console.ReadKey();
        }
        public void ConsGenero(Livro[] vLivros, int indice, string genero){
            Console.Clear();
            int verificação = 0;
            if(indice==0){
                Console.WriteLine("Nenhum foi cadastrado ainda!");
            }
            else{
                for(int i = 0; i<indice; i++){
                    if(vLivros[i].getGenero()==genero){
                        verificação ++;
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
            if(verificação == 0){
                Console.WriteLine("Não existe nenhum livro com esse número!");
            }

            Console.ReadKey();
        }
        public void Emprestimo(Livro[] vLivros, int pos){
            Console.Clear();

            if(pos == -1){
                Console.WriteLine("Numero de tombo nao cadastrado");
            }
            else if(vLivros[pos].getStatus()=="E"){
                Console.WriteLine("Livro ja emprestado ");
            }
            else{
                vLivros[pos].setStatus("E");
                Console.WriteLine("Emprestimo do livro lançado");
            }

            Console.ReadKey();
        }
        public void Disponivel(Livro[] vLivros, int pos){
            Console.Clear();

            if(pos == -1){
                Console.WriteLine("Numero de tombo nao cadastrado");
            }
            else if(vLivros[pos].getStatus()=="D"){
                Console.WriteLine("Livro Disponivel ");
            }
            else{
                vLivros[pos].setStatus("D");
                Console.WriteLine("Devolução do livro lançada");
            }
            Console.ReadKey();
        }
    }
}
using System;

namespace CadastroLivros
{
    class Program
    {
        static int indice=0;
        static Livro[] vLivros;
        static ILivros iL = new ILivros();
        static IMenu menu = new IMenu();//intancionado menu na program
        static void Main(string[] args)
        {
            
            vLivros = new Livro[10];//vetor para armazenar livros
            int op = 1;

            while((op>0)&&(op<6)){//repetição do menu enquanto o programa estiver ativo
                op = menu.Menu();//aguarda a opção do usuario pelo menu
                Console.Clear();
                if((op>0)&&(op<6)){
                tratamenu(op);//responsavel por chamar os metodos expecifico para cada op
                }
            }
            Console.ReadKey();
        }
        static int numTombo, pos;
        static void tratamenu(int op){//metodo trata menu
           
           switch(op){
               case 1:  
                    vLivros[indice] = iL.CadLivros();
                    indice++;
                    break;
               case 2:
                    numTombo = menu.NumeroTombo();
                    iL.ConsTombo(vLivros, indice, numTombo);
                    break;
               case 3:
                    string genero = menu.Genero();
                    iL.ConsGenero(vLivros, indice, genero);
                    break;
               case 4:
                    numTombo = menu.NumeroTombo();
                    pos = menu.verificar(vLivros, indice, numTombo);
                    iL.Emprestimo(vLivros, pos);
                    break;
               case 5:
                    numTombo = menu.NumeroTombo();
                    pos = menu.verificar(vLivros, indice, numTombo);
                    iL.Disponivel(vLivros, pos);
                    break;
               case 6:
                    break;
           }
        }
    }
}

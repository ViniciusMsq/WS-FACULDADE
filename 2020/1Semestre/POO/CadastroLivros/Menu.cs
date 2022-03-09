namespace CadastroLivros
{
    public class Menu
    {
        static int indice=0;
        static Livro[] vLivros = new Livro[10];
        static ILivros iL = new ILivros();
        static IMenu menu = new IMenu();
        static int numTombo;
        public void tratamenu(int op){//metodo trata menu
           
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
                    iL.Emprestimo(vLivros, indice, numTombo);
                    break;
               case 5:
                    numTombo = menu.NumeroTombo();
                    iL.Disponivel(vLivros, indice, numTombo);
                    break;
               case 6: 
                    break;
            }
        }   
    }
} 
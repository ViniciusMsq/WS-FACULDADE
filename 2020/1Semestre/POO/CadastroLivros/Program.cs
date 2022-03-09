using System;

namespace CadastroLivros
{
    class Program
    {
          static IMenu iMenu = new IMenu();//intancionado menu na program
          static Menu menu = new Menu(); 
          static void Main(string[] args){
               
               int op = 1;

               while((op>0)&&(op<6)){//repetição do menu enquanto o programa estiver ativo
                   
                    op = iMenu.Menu();//aguarda a opção do usuario pelo menu
                    Console.Clear();

                    if((op>0)&&(op<6)){
                    menu.tratamenu(op);//responsavel por chamar os metodos expecifico para cada op
                    }
               }
               Console.ReadKey();
          }
     }
}

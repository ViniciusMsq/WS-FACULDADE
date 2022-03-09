using System;

namespace CadastroAluno
{
    class Program
    {
        //variaveis globais
        static int indice;
        static IAluno Ia;
        static Aluno[] vAluno;
        static IMenu menu = new IMenu();
        static void Main(string[] args)
        {
            vAluno = new Aluno[5];//vetor dos alunos
            
            Ia = new IAluno();
            int op = 1;
            indice = 0;

            while ((op > 0) && (op < 6))//repetidor para o programa manter execução de varias opções
            {
                op = menu.LeMenu();
                Console.Clear();
                
                if ((op > 0) && (op < 6))
                {
                    trataMenu(op);
                }

            }
        }

        static void trataMenu(int op)//switch das opções para chamar os metodos escolhidos
        {
            
            switch (op)
            {
                case 1:
                    vAluno[indice] = Ia.ILeAluno();
                    indice++;//avança a posição do vetor
                    break;
                case 2:
                    int ra = menu.LeRa();
                    Ia.PesquisarRa(vAluno, indice, ra);
                    break;
                case 3:
                    Ia.MostrarAlunos(vAluno, indice);
                    break;
                case 4:
                    ra = menu.LeRa();
                    Ia.ModificarAluno(vAluno, indice, ra);
                    break;
                case 5:
                    string curso = menu.LeCurso();//string curso vai receber o que retornar
                    Ia.ListarAlunosCurso(vAluno, indice, curso);//passar esse curso como parametro
                    break;
                case 6:
                    break;
                    
            }
        }
    }
}

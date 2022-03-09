import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        
        Scanner ler = new Scanner(System.in);
        int op = 1;

        Controle controlElevador = new Controle();
        controlElevador.Inicializa(6, 10);

        do{
            //limpando terminal------
            System.out.print("\033[H\033[2J");  
            System.out.flush();
            //-----------------------
            System.out.println("ELEVADOR FUNCIONANDO");
            System.out.println("INFORME A OPÇÂO DESEJADA");
            System.out.println("\nInformações do elevador: andar atual/limite: " + controlElevador.getAndarAtual()+"/" +controlElevador.getTotalAndares()+"  pessoas/limite: "+controlElevador.getPessoasNoElvador()+"/"+controlElevador.getLimitePessoas());

            System.out.print("\n1- Entrar no elevador\n2- Sair do elevador\n3- Subir um andar\n4- Descer um andar\n5- Escolher Andar\n0- EXIT\n\n>>> ");
            op = ler.nextInt();
            
            if(op!=0){
                switch(op){
                    case 1: controlElevador.Entrar();
                        break;
                    case 2: controlElevador.Sair();
                        break;
                    case 3: controlElevador.Subir();
                        break;
                    case 4: controlElevador.Descer();
                        break;
                    case 5: System.out.print("informe o andar que deseja ir: ");
                            int x = ler.nextInt();
                            controlElevador.AndarEscolhido(x);
                        break;

                    default: System.out.println("Nenhuma opção valida escolhida!");
                }
                Thread.sleep(1500);
            }

        }while(op!=0);
        ler.close();
    }
}

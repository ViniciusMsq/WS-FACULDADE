import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {


        //Questão dos Digitos

        //limpando terminal------
        System.out.print("\033[H\033[2J");  
        System.out.flush();
        //-----------------------
        
        Scanner ler = new Scanner(System.in);

        String x, val;
        int c = 0;
        
        System.out.println("Digite a sequencia de numeros");
        x = ler.nextLine();
        ler.close();

        System.out.flush();

        do{
            
            switch(x.substring(c, (c+1))){
                case "0": System.out.print(" ZERO ");
                break;
                case "1": System.out.print(" UM ");
                break;
                case "2": System.out.print(" DOIS ");
                break;
                case "3": System.out.print(" TRES ");
                break;
                case "4": System.out.print(" QUATRO ");
                break;
                case "5": System.out.print(" CINCO ");
                break;
                case "6": System.out.print(" SEIS ");
                break;
                case "7": System.out.print(" SETE ");
                break;
                case "8": System.out.print(" OITO ");
                break;
                case "9": System.out.print(" NOVE ");
                break;
            }

            c++;

        }while(c!=x.length());



    }
}

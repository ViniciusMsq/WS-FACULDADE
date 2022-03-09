import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        //limpando terminal------
        System.out.print("\033[H\033[2J");  
        System.out.flush();
        //-----------------------
        
        Scanner ler = new Scanner(System.in);
        String date;
        
        System.out.print("Entre com uma data com o seguinte padrão: '27/04/2000':\n-> ");
        date = ler.nextLine();
        ler.close();

        Data data = new Data(date);
        System.out.print("\nComparação de datas - indice\n 0: Datas Iguais\n-1: Data de parametro superior\n 1: Data de parametro inferior\n");
        System.out.print("\nData objeto comparada com data corrente:   " + data.compara(data));
        System.out.println("\nData String comparadac com data corrente: " + data.compara("29/03/2021"));

        System.out.println("\n O ano corrente é bissexto: " + data.isBissexto());
    }
}

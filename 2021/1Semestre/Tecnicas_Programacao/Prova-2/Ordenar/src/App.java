import java.util.Scanner;
import java.util.Arrays;

public class App {
    public static void main(String[] args) throws Exception {

        // limpando terminal------
        System.out.print("\033[H\033[2J");
        System.out.flush();
        // -----------------------

        Scanner ler = new Scanner(System.in);
        int soma = 0, tamanho = 0;
        double media = 0.00;


        System.out.println("Quantas numeros ira digitar: ");
        tamanho = ler.nextInt();
        System.out.flush();


        int vet[] = new int[tamanho];

        

        for(int i = 0; i< tamanho; i++)
        {
            System.out.print("Insira o " + (i +1) +" Valor: ");
            vet[i] = (ler.nextInt());
            System.out.flush();
            soma += vet[i];
        }

        ler.close();
        Arrays.sort(vet);

        System.out.println("\nValores Ordenados");
        for(int i = 0; i< vet.length; i++)
        {
            System.out.print(vet[i] + ", ");
        }

        media = soma / tamanho;
        System.out.print("\n Media: " + media);
    
    }
}

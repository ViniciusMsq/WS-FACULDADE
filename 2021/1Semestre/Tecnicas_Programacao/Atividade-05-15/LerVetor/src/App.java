import java.util.Scanner;
public class App {
    public static void main(String[] args) throws Exception {
        //limpando terminal------
        System.out.print("\033[H\033[2J");  
        System.out.flush();
        //-----------------------

        Scanner ler = new Scanner(System.in);
        int x, maior=0, menor=0, imaior=0, imenor=0;

        System.out.println("Digite a quantidade de numeros");
        x = ler.nextInt();
        
        int[] vetor = new int[x];

        for(int i = 0; i<x; i++){
            System.out.print("\n" + (i+1) + "°: ");
            vetor[i] = ler.nextInt();
        }
        ler.close();
        menor = vetor[0];
        maior = vetor[0];

        System.out.println("-------------");
        for(int i = 0; i<x; i++){
            if(menor>vetor[i]){ 
                menor=vetor[i];
                imenor=i;
            }
            if(maior<vetor[i]){ 
                maior=vetor[i];
                imaior=i;
            }
        }
        
        System.out.println("maior: "+maior+" sua posição no vetor: "+(imaior+1)+"°(i="+imaior+")");
        System.out.println("menor: "+menor+" sua posição no vetor: "+(imenor+1)+"°(i="+imenor+")");
    }
}

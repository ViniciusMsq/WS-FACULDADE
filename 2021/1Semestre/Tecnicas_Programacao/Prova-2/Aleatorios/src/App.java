import java.util.Random;

public class App {
    public static void main(String[] args) throws Exception {

        /* bugou a saida dessa vez TT
        // limpando terminal------
        System.out.print("\033[H\033[2J");
        System.out.flush();
        // ----------------------- */

        Random random = new Random();

        int[] vet = new int[100];
        
        double media = 0.0;
        int abaixo[] = new int[100], acima[]=new int[100], soma=0, cb=0, ca=0;
        
        for(int i=0; i<100; i++){
            vet[i] = random.nextInt(100);
        }

        for(int val:vet){
            soma +=val;
        }
        media = soma/100;

        System.out.println("Soma: " + soma);
        System.out.println("Media: " + media);

        for(int val:vet){
            if(val<media){
                abaixo[cb] =val;
                cb++;
            }else{
                acima[ca]=val;
                ca++;
            }
        }

        System.out.println("Lista abaixo da media: ");
        for(int val:abaixo){
            if(val !=0){
                System.out.print(" " + val);
            }
        }

        System.out.println("\nLista acima da media: ");
        for(int val:acima){
            if(val !=0){
                System.out.print(" " + val);
            }
        }



    }
}

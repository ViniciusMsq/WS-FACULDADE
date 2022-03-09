import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        Scanner ler = new Scanner(System.in);
        Calculos calc = new Calculos();
        int matriz [][] = new int [3][3];

        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
            System.out.print("\ninforme o valor da matriz na posição: " + i +""+ j+": ");
            matriz[i][j] = ler.nextInt();
            }
        }
        System.out.println("\n\nMatriz");
        calc.ExibirMatriz(matriz);
        

        System.out.print("Soma Tudo: " + calc.SomarTudo(matriz));
        System.out.print("\n\nSoma Linha coluna:\n");
        calc.SomarLinhaColuna(matriz);

    }
}

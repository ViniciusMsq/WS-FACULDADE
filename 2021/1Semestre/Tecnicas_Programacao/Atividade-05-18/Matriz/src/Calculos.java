public class Calculos {
    int matriz [][] = new int [3][3];

    public Calculos(){
        //
    }

    public void ExibirMatriz(int mat[][]){
        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
            System.out.print(mat[i][j]+" ");
            }
            System.out.print("\n");
        }
    }
    public int SomarTudo(int mat[][]){
        int soma = 0;
        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                soma += mat[i][j];
            }
        }

        return soma;
    }
    public void SomarLinhaColuna(int mat[][]){
        int somaL = 0;
        int somaC = 0;
        int vet[] = new int [3];
        for(int i = 0; i<3; i++){
            somaL = 0;

            for(int j = 0; j<3; j++){
                somaL += mat[i][j];
                System.out.print(mat[i][j]+"  ");
            }
            System.out.print(": " + somaL);

            System.out.print("\n");
        }

        for(int i = 0; i<3; i++){
            somaC = 0;

            for(int j = 0; j<3; j++){
                somaC += mat[j][i];
            }
            vet[i] = somaC;
        }
        System.out.print("_  _  _\n");
        System.out.print(vet[0]+" "+ vet[1]+" "+ vet[2]+" ");

        
    }

}

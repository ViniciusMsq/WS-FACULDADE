import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Vinicius
 */
public class Main {
    /** 
     * 
     * @param args
     */
    public static void main(String[] args){
        try {
            Scanner in = new Scanner(System.in);
            Arquivo arquivoObj = new Arquivo();
            
            File arq = new File("MeuDiretorio\\pessoas.bin");
            arquivoObj.NovoArquivo(arq);

            FileOutputStream fos = new FileOutputStream(arq,true);
            ObjectOutputStream oos = new ObjectOutputStream(fos);

            Pessoa pessoa = new Pessoa();
            
            int resposta = 1;
            int cont = 0;

            while (resposta > 0) {


                System.out.print("\nCadastrar uma nova Pessoa (1(sim) ou 0(nao)): ");
                resposta = in.nextInt();

                if(resposta != 0)
                {
                    cont ++;
                    System.out.println("> CADASTRO - "+cont+"..");
                    pessoa = arquivoObj.CadastrarPessoa();
                    System.out.print("\n");
                    arquivoObj.Gravar(oos, pessoa);
                }
            }
            oos.close();
            fos.close();
            
            arquivoObj.LerArquivoPessoa(arq);
            arquivoObj.BuscarIndex(arq);

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
}

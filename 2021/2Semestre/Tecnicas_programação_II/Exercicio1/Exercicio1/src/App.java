import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        try {
            Scanner in = new Scanner(System.in);
            ArquivoObj arquivoObj = new ArquivoObj();
            
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
                    pessoa = Pessoa.CadastrarPessoa();
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

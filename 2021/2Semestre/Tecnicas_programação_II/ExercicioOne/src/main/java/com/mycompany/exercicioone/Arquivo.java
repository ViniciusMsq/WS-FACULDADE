/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
/

/**
 *
 * @author Vinicius
 */
public class Arquivo {

    public Arquivo(){

    }

    public static void NovoArquivo(File arq)
    {
        try 
        {
            FileOutputStream fos = new FileOutputStream(arq);
            fos.close();

        } catch (IOException e) {
            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, e);
        }
    }

    public static void Gravar(ObjectOutputStream oos, Pessoa p)
    {
        try 
        {
            oos.writeObject(p);
            System.out.println("\n Pessoas Gravada com Sucesso! \n");

        } catch (IOException e) {
            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, e);
        }
    }

    public static void LerArquivoPessoa(File arq)
    {
        try {

            FileInputStream fis = new FileInputStream(arq);
            ObjectInputStream ois = new ObjectInputStream(fis);

            Pessoa pessoaLida = new Pessoa();

            System.out.println("\n\nListanto as Pessoas");
            while (fis.available() > 0) {
                pessoaLida = (Pessoa) ois.readObject();
                System.out.println(pessoaLida.getPessoaStr());
            }
            ois.close();
            fis.close();

        } catch (IOException e) {
            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, e);
        } catch (ClassNotFoundException e) {
            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, e);
        }
    }

    public static void BuscarIndex(File arq)
    {
        Scanner in = new Scanner(System.in);
        int index = 0;

        System.out.print("\n> buscar a pessoa de Qual Index : ");
        index = in.nextInt();

        try {

            FileInputStream fis = new FileInputStream(arq);
            ObjectInputStream ois = new ObjectInputStream(fis);

            Pessoa pessoaLida = new Pessoa();
            int cont = 1;

            while (fis.available() > 0) {
                pessoaLida = (Pessoa) ois.readObject();

                if(cont == index)
                {
                   System.out.println(pessoaLida.getPessoaStr());
                   System.out.println("\n");
                }
                cont++;
            }
            ois.close();
            fis.close();

        } catch (IOException e) {
            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, e);
        } catch (ClassNotFoundException e) {
            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, e);
        }
    }
    
}

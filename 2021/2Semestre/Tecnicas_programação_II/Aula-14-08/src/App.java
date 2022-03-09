import java.util.Scanner;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

public class App {
    public static void main(String[] args) throws FileNotFoundException, IOException, ClassNotFoundException {
    
        File file = new File("teste.gcp");
        file.createNewFile();
        ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(file));


        Scanner ler = new Scanner(System.in);
        String option = "s";
        Pessoa p;

        String nome, nacionalidade, dataNascimento;
        String sexo;
        int idade;

        do{
            //limpando terminal------
            System.out.print("\033[H\033[2J");  
            System.out.flush();
            //-----------------------
            System.out.println("--cadastre uma pessoa--");
            
            System.out.print("\nDigite o nome da pessoa: ");
            System.out.flush();
            nome = ler.nextLine();
            

            System.out.print("\nDigite a data de nascimento da pessoa: ");
            System.out.flush();
            dataNascimento = ler.nextLine();
            

            System.out.print("\nDigite o sexo da pessoa (m/f): ");
            System.out.flush();
            sexo = ler.nextLine();
            

            System.out.print("\nDigite a nascionalidade da pessoa: ");
            System.out.flush();
            nacionalidade = ler.nextLine();
            

            System.out.print("\nDigite a idade da pessoa: ");
            System.out.flush();
            idade = ler.nextInt();

            p = new Pessoa(nome, nacionalidade, dataNascimento, sexo, idade);

            //System.out.println("\n" + p.ToSring());
            
            oos.writeObject(p);
            oos.close();

            System.out.println("\nDeseja fazer mais um cadastro? (s/n)");
            System.out.flush();
            option = ler.nextLine();
            
        }while(option != "n");

        System.out.println("\n--Lendo pessoas--");

        ObjectInputStream ois = new ObjectInputStream(new FileInputStream(file));
        Pessoa px = (Pessoa) ois.readObject();
        ois.close();


        System.out.println(px.toString());

    }
}

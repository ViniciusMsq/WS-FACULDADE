import java.io.Serializable;
import java.util.Scanner;

public class Pessoa implements Serializable{
    private String  Nome;
    private String  Sexo;
    private String  Nascionalidade;
    private String DataNascimento;
    private int  Rg;
    private int  Idade;
    private double  Cpf;

    public Pessoa(String nome, int rg, double cpf, int idade, String sexo, String nascionalidade, String dataNascimento) {
        Nome = nome;
        Idade = idade;
        Sexo = sexo;
        Nascionalidade = nascionalidade;
        DataNascimento = dataNascimento;
        Rg = rg;
        Cpf = cpf;
    }

    public Pessoa() {
    }

    public String getNome() {
        return Nome;
    }

    public void setNome(String nome) {
        Nome = nome;
    }

    public int getRg() {
        return Rg;
    }

    public void setRg(int rg) {
        Rg = rg;
    }

    public double getCpf() {
        return Cpf;
    }

    public String getSexo() {
        return Sexo;
    }

    public void setSexo(String sexo) {
        Sexo = sexo;
    }

    public String getNascionalidade() {
        return Nascionalidade;
    }

    public void setNascionalidade(String nascionalidade) {
        Nascionalidade = nascionalidade;
    }

    public String getDataNascimento() {
        return DataNascimento;
    }

    public void setDataNascimento(String dataNascimento) {
        DataNascimento = dataNascimento;
    }

    public int getIdade() {
        return Idade;
    }

    public void setIdade(int idade) {
        Idade = idade;
    }

    public void setCpf(double cpf) {
        Cpf = cpf;
    }

    public static Pessoa CadastrarPessoa()
    {
        Pessoa cadPessoa = new Pessoa();

        Scanner in = new Scanner(System.in);
        System.out.print("Digite o Nome: ");
        cadPessoa.setNome(in.nextLine());
        System.out.print("Digite a idade: ");
        cadPessoa.setIdade(in.nextInt());
        System.out.print("Digite o Sexo: ");
        cadPessoa.setSexo(in.nextLine());
        in.nextLine();
        System.out.print("Digite a Nascionalidade: ");
        cadPessoa.setNascionalidade(in.nextLine());
        System.out.print("Digite a Data Nascimento: ");
        cadPessoa.setDataNascimento(in.nextLine());
        System.out.print("Digite o Rg: ");
        cadPessoa.setRg(in.nextInt());
        in.nextLine();
        System.out.print("Digite o Cpf: ");
        cadPessoa.setCpf(in.nextDouble());
        in.nextLine();

        return  cadPessoa;
    }

    public String getPessoaStr() {
        String ret = "";
        ret += "\nNome: " + this.getNome();
        ret += "\nIdade: " + this.getIdade();
        ret += "\nSexo: " + this.getSexo();
        ret += "\nNascionalidade: " + this.getNascionalidade();
        ret += "\nDataNascimento: " + this.getDataNascimento();
        ret += "\nRg: " + this.getRg();
        ret += "\nCpf: " + this.getCpf();
        return ret;
    }
}

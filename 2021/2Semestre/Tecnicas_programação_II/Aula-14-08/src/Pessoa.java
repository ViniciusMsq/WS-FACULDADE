import java.io.Serializable;

public class Pessoa implements Serializable {
    private String nome, nacionalidade, dataNascimento;
    private String sexo;
    private int idade;

    public Pessoa() {
        //vazio
    }

    public Pessoa(String nome, String nacionalidade, String dataNascimento, String sexo, int idade ) {
        setNome(nome);
        setNacionalidade(nacionalidade);
        setSexo(sexo);
        setIdade(idade);
        setDataNascimento(dataNascimento);
    }

    public String getDataNascimento() {
        return dataNascimento;
    }
    public int getIdade() {
        return idade;
    }
    public String getNacionalidade() {
        return nacionalidade;
    }
    public String getNome() {
        return nome;
    }
    public String getSexo() {
        return sexo;
    }
    public void setDataNascimento(String dataNascimento) {
        this.dataNascimento = dataNascimento;
    }
    public void setIdade(int idade) {
        this.idade = idade;
    }
    public void setNacionalidade(String nacionalidade) {
        this.nacionalidade = nacionalidade;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    public void setSexo(String sexo) {
        this.sexo = sexo;
    }

    public String ToSring(){
        return getNome()+';'+getSexo()+';'+getIdade()+';'+getDataNascimento()+';'+getNacionalidade();
    }
}

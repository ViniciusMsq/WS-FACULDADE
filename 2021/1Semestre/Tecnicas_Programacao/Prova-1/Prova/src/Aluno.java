public class Aluno extends Pessoa {
    
    private int matricula, termo, anoMatricula;
    private String curso;

    public Aluno(String nome, String dataNascimento, int matricula, int termo, String curso, int anoMatricula){
        super(nome, dataNascimento);
        this.matricula = matricula;
        this.termo = termo;
        this.curso = curso;
        this.anoMatricula = anoMatricula;
    }

    public int getMatricula() {
        return matricula;
    }
    public int getAnoMatricula() {
        return anoMatricula;
    }
    public String getCurso() {
        return curso;
    }
    public int getTermo() {
        return termo;
    }

    public void setCurso(String curso) {
        this.curso = curso;
    }
    public void setAnoMatricula(int anoMatricula) {
        this.anoMatricula = anoMatricula;
    }
    public void setTermo(int termo) {
        this.termo = termo;
    }
    public void setMatricula(int matricula) {
        this.matricula = matricula;
    }

    Data dataAtual = new Data("16/04/2021");
    public String toString(){
        return 
        "-Informações Aluno-"
        +"\nNome: " + getNome() 
        +"\nIdade: " + getIdade(dataAtual)
        +"\nCurso: " + getCurso()
        +"\nTermo: " + getTermo()
        +"\nMatricula: " + getMatricula()
        +"\nAno da matricula: " + getAnoMatricula();
    }

}

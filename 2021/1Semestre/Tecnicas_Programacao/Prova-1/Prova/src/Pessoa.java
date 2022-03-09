public class Pessoa {
    
    private String nome;
    private Data dataNascimento;

    public Pessoa(String nome, String dataNascimento){
        this.nome = nome;
        this.dataNascimento = new Data(dataNascimento);
    }

    public String getNome() {
        return nome;
    }
    public Data getDataNascimento() {
        return dataNascimento;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    public void setDataNascimento(String dataNascimento) {
        this.dataNascimento = new Data(dataNascimento);
    }
    public void setDataNascimento(Data dataNascimento) {
        this.dataNascimento = dataNascimento;
    }
    public int getIdade(Data dataAtual){
        int res; 

        res = dataAtual.getAno() - this.getDataNascimento().getAno();

        if(dataAtual.getMes()<this.getDataNascimento().getMes()){
            res--;
        }else{
            if(dataAtual.getMes()==this.getDataNascimento().getMes()){
                if(dataAtual.getDia()<this.getDataNascimento().getDia()){
                    res--;
                }
            }
        }
        return res;
    }
    
}

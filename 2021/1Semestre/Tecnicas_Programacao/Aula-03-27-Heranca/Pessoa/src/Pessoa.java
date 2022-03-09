public class Pessoa {
    
    private String nome, endereco;
    private Data data_nasc;
    private int rg;

    public Pessoa(){
        //
    }

    public void setNome(String nome){
        this.nome = nome;
    }
    public void setEndereco(String endereco){
        this.endereco = endereco;
    }
    public void setData_nasc(String data){    
        this.data_nasc = new Data(data);
    }
    public void setData_nasc(Data data){    
        this.data_nasc = data;
    }
    public void setRg(int rg){
        this.rg = rg;
    }
    public String getNome(){
        return this.nome;
    }
    public String getEndereco(){
        return this.endereco;
    }
    public Data getData_nasc(){
        return this.data_nasc;
    }
    public int getRg(){
        return this.rg;
    }
    public int getIdade(Data dataAtual){
        int res; 

        res = dataAtual.getAno() - this.getData_nasc().getAno();

        if(dataAtual.getMes()<this.getData_nasc().getMes()){
            res--;
        }else{
            if(dataAtual.getMes()==this.getData_nasc().getMes()){
                if(dataAtual.getDia()<this.getData_nasc().getDia()){
                    res--;
                }
            }
        }
        return res;
    }
    public String getDadosPessoa(){
        String ret ="";
        ret += "Nome " + this.getNome();
        ret += "\nEndereco " + this.getEndereco();
        ret += "\nData Nascimento " + this.getData_nasc().getData();
        ret += "\nRG " + this.getRg();
        
        return ret;
    }

}

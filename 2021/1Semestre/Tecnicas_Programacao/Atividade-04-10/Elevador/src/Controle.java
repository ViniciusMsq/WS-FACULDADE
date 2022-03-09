public class Controle {
   
    private int andarAtual = 0, totalAndares , limitePessoas, pessoasNoElvador = 0;

    public Controle(){
        //
    }

    public void Inicializa(int capacidade, int AndaresTotais){
        this.totalAndares = AndaresTotais;
        this.limitePessoas = capacidade;
    }

    public void Entrar(){
        if(!(getLimitePessoas()==getPessoasNoElvador())){
            setPessoasNoElevador(1);
            System.out.println("Voce entrou no elevador");
        }else{

            System.out.println("Elevador cheio, aguarde a saida de uma pessoa...");
        }
    }
    public void Sair(){
        if(getPessoasNoElvador()<1){
            System.out.println("Não tem ninguem no elevador, quem está tentando sair?");
        }else{
            setPessoasNoElevador(-1);
            System.out.println("Voce saiu do elevador");
        }
    }   

    public void Subir(){
        if(!(getAndarAtual()==getTotalAndares())){
            setAndarAtual(1);
            System.out.println("voce chegou no "+ getAndarAtual()+"° andar!");
        }else{
            System.out.println("Se subir mais, vai acabar voando para fora do predio, não posso permitir!");
        }
    }

    public void Descer(){
        if(getAndarAtual()<1){
            System.out.println("Se descer mais, vai acabar chegando no nucleo da terra, ja estamos no Térreo!");
        }else{
            setAndarAtual(-1);
            if(getAndarAtual()!=0){
                System.out.println("voce chegou no "+ getAndarAtual()+"° andar!");
            }else{
                System.out.println("voce chegou no Terreo!");
            }
        }
    }

    public void AndarEscolhido(int andar){
        if(andar>=0 && andar<=getTotalAndares() && andar!=getAndarAtual()){

            if(andar>getAndarAtual()){
                setAndarAtual(andar-getAndarAtual());
            }else{
                setAndarAtual(-(getAndarAtual()-andar));
            }
            if(getAndarAtual()!=0){
                System.out.println("voce chegou no "+ getAndarAtual()+"° andar!");
            }else{
                System.out.println("voce chegou no Terreo!");
            }
        }else{
            System.out.println("não engane o sistema de andares");
        }
    }

    public void setAndarAtual(int andar){
        this.andarAtual += andar;
    }
    public void setPessoasNoElevador(int pessoas){
        this.pessoasNoElvador += pessoas;
    }

    public int getAndarAtual() {
        return andarAtual;
    }
    public int getPessoasNoElvador() {
        return pessoasNoElvador;
    }
    public int getLimitePessoas() {
        return limitePessoas;
    }
    public int getTotalAndares() {
        return totalAndares;
    }

}

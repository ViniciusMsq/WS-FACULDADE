public class Aviao {
    private int velocidade;

    public Aviao(){
        //construct
    }

    public void setVelocidade(int vel){
        if(vel>=0)
            this.velocidade = vel;
    }
    public int getVelocidade(){
        return this.velocidade;
    }

    public void acelerar(){
        this.velocidade++;
    }
    public void frear(){
        this.setVelocidade(this.getVelocidade()-1);
    }
}

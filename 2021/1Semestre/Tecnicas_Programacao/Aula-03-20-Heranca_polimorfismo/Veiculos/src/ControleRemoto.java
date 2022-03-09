public class ControleRemoto {
    private Brinquedo brinquedo;

    public ControleRemoto(Brinquedo b){
        this.brinquedo = b;
    }

    public void mover(){
        this.brinquedo.mover();
    }
    public void mover(double dist){
        //sobrecarga
    }
}

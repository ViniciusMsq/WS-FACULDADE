public class ControleRemoto {
    
    private Televisao TV;

    public ControleRemoto(Televisao tv){
        this.TV = tv;
    }

    public void volMais(){
        this.TV.setVolume(this.TV.getVolume()+1);
    }
    public void volMenos(){
        this.TV.setVolume(this.TV.getVolume()-1);
    }

}

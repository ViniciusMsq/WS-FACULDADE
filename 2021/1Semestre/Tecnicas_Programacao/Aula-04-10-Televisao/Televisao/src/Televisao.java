public class Televisao {
    
    int volume, canal, volMax, canalMax;

    public Televisao(int vMax, int cMax){
        this.volMax=vMax;
        this.canalMax=cMax;
        this.setCanal(1);
    }

    public void setCanal(int canal) {
        this.canal = canal;
    }
    public void setVolume(int volume) {
        if((volume <= this.volMax) && (volume >= 0)){
            this.volume = volume;
        }
    }
    public int getCanal() {
        return canal;
    }
    public int getVolume() {
        return volume;
    }
}

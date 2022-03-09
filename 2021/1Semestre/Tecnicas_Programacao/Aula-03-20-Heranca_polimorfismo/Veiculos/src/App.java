public class App {
    public static void main(String[] args) throws Exception {
        //limpando terminal------
        System.out.print("\033[H\033[2J");  
        System.out.flush();
        //-----------------------

        System.out.println("-------------------------");
        System.out.println("Polimorfismo aplicado");
        System.out.println("-------------------------");
        Brinquedo woody = new Brinquedo();
        woody.mover();
        
        Carro carro = new Carro();
        carro.mover();

        Barco barco = new Barco();
        barco.mover();

        Aviao aviao = new Aviao();
        aviao.mover();

        System.out.println("------------------------");
        System.out.println("------------------------");

        ControleRemoto cr = new ControleRemoto(woody);
        cr.mover();



    }
}

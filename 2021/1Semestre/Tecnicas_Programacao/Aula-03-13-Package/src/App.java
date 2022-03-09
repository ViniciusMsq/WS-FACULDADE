import pacote3.Teste;

public class App {
    public static void main(String[] args) throws Exception {
        Aviao aviao = new Aviao();

        aviao.setVelocidade(5);

        System.out.println(aviao.getVelocidade());

        aviao.setVelocidade(-1);

        System.out.println(aviao.getVelocidade());
        
        aviao.frear();

        System.out.println(aviao.getVelocidade());

        aviao.acelerar();

        System.out.println(aviao.getVelocidade());

        Teste teste = new Teste();

        teste.testandoImport();
    }
}

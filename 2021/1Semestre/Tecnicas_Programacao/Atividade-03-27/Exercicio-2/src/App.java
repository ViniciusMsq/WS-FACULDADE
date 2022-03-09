public class App {
    public static void main(String[] args) throws Exception {

        //limpando terminal------
        System.out.print("\033[H\033[2J");  
        System.out.flush();
        //-----------------------
        
        FiguraGeometrica fg = new FiguraGeometrica();
        Circulo c = new Circulo();
        Quadrado q = new Quadrado();
        Triangulo t = new Triangulo();
        TrianguloEquilatero te = new TrianguloEquilatero();

        Corinthians timao = new Corinthians();
        melhorTorcida gavioes = new melhorTorcida();

        fg.desenha();
        c.desenha();
        q.desenha();
        t.desenha();
        te.desenha();

        System.out.println("-----------------------");
        System.out.println(timao.descrever());
        System.out.println(gavioes.descrever());
        
        

    }
}

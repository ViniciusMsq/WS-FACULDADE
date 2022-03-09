public class App {
    public static void main(String[] args) throws Exception {
        //limpando terminal------
        System.out.print("\033[H\033[2J");  
        System.out.flush();
        //-----------------------

        Aluno aluno = new Aluno("Vinicius", "27/04/2000", 93, 5, "Ciencias da Computação", 19);

        System.out.println(aluno);

        System.out.println("\n\n");
        
        aluno.setNome("Vinicius Mesquini");
        aluno.setCurso("Ciência da computação");

        System.out.println(aluno);
    }
}

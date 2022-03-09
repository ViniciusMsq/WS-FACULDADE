public class App {
    public static void main(String[] args) throws Exception {
        //limpando terminal------
        System.out.print("\033[H\033[2J");  
        System.out.flush();
        //-----------------------
        
        Pessoa p = new Pessoa();

        Data data = new Data("27/04/2000");
        Data dataAtual = new Data("01/04/2021");

        p.setNome("Vinicius");
        p.setData_nasc(data);
        p.setEndereco("Tupi Paulista");
        p.setRg(551656505);
        System.out.println(p.getDadosPessoa());
        System.out.println(p.getIdade(dataAtual));
    }
}

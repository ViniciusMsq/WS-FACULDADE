namespace CadastroLivros
{
    public class Livro
    {
        private string titulo, autor, status, genero;
        private int numTombo;

        public Livro(string titulo, string autor, string genero, string status, int numTombo){
            this.titulo = titulo;
            this.autor = autor;
            this.genero = genero;
            this.status = status;
            this.numTombo = numTombo;
            //metodo construtor
        }

        public void setTitulo(string titulo){
            this.titulo = titulo;
        }
        public string getTitulo(){
            return titulo;
        }
        public void setAutor(string autor){
            this.autor = autor;
        }
        public string getAutor(){
            return autor;
        }
        public void setGenero(string genero){
            this.genero = genero;
        }
        public string getGenero(){
            return genero;
        }
        public void setStatus(string status){
            this.status = status;
        }
        public string getStatus(){
            return status;
        }
        public void setNumTombo(int isbn){
            this.numTombo = isbn;
        }
        public int getNumTombo(){
            return numTombo;
        }
        //fim dos getters e setters
    }
}
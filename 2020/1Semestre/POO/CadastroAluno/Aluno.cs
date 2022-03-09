using System;
using System.Collections.Generic;
using System.Text;

namespace CadastroAluno
{
    public class Aluno
    {
        string nome, endereco, curso;
        int anoIngresso, ra;
        
        public Aluno(string nome, string endereco, string curso, int anoIngresso, int ra)
        {
            this.nome = nome;
            this.endereco = endereco;
            this.curso = curso;
            this.anoIngresso = anoIngresso;
            this.ra = ra;
        }//metodo contrutor para criada dos alunos

        // todos os get e set, para fazer alteração ou requisitar informação
        public void setNome(string nome)
        {
            this.nome = nome;
        }
        public string getNome()
        {
            return nome;
        }
        public void setEndereco(string endereco)
        {
            this.endereco = endereco;
        }
        public string getEndereco()
        {
            return endereco;
        }
        public void setCruso(string curso)
        {
            this.curso = curso;
        }
        public string getCurso()
        {
            return curso;
        }
        public void setAnoIngresso(int anoIngresso)
        {
            this.anoIngresso = anoIngresso;
        }
        public int getAnoIngresso()
        {
            return anoIngresso;
        }
        public void setRa(int ra)
        {
            this.ra = ra;
           
        }
        public int getRa()
        {
            return ra;

        }

    }
}

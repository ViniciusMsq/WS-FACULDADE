/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Back;

import java.io.Serializable;

/**
 *
 * 
 */
public class Pessoa implements Serializable {
    
    public String nome,data_nascimento,nacionalidade,sexo;
    public int idade;

    public Pessoa ()
    {

    }

    public String getNome() {
        return nome;
    }

    public String getData_nascimento() {
        return data_nascimento;
    }

    public String getNacionalidade() {
        return nacionalidade;
    }

    public int getIdade() {
        return idade;
    }

    public String getSexo() {
        return sexo;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setData_nascimento(String data_nascimento) {
        this.data_nascimento = data_nascimento;
    }

    public void setNacionalidade(String nacionalidade) {
        this.nacionalidade = nacionalidade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public void setSexo(String sexo) {
        this.sexo = sexo;
    }
    
    public String getPessoa()
    {
        String str = "";
        str += ""+this.getNome();
        str += "-"+this.getIdade();
        str += "-"+this.getData_nascimento();
        str += "-"+this.getSexo();
        str += "-"+this.getNacionalidade();
        return str;
    }
   
}

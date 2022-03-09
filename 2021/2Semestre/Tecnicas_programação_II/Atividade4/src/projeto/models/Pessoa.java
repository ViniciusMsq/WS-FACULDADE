/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package projeto.models;

import java.io.Serializable;

/**
 *
 * @author Vinicius
 */
public class Pessoa implements Serializable {
    public String nome,dataNasc,sexo;
    public int idade,id;

    public Pessoa(String nome, String dataNasc, String sexo, int idade, int id) {
        this.nome = nome;
        this.dataNasc = dataNasc;
        this.sexo = sexo;
        this.idade = idade;
        this.id = id;
    }
   
    public Pessoa ()
    {

    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getDataNasc() {
        return dataNasc;
    }

    public void setDataNasc(String dataNasc) {
        this.dataNasc = dataNasc;
    }

    public String getSexo() {
        return sexo;
    }

    public void setSexo(String sexo) {
        this.sexo = sexo;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

  
    public String getPessoa()
    {
        String str = "Pessoa { ";
        str += "\nnome= "+this.getNome();
        str += "\nsexo= "+this.getSexo();
        str += "\ndataNasc= "+this.getDataNasc();
        str += "\nidade= "+this.getIdade();
        str+=" }";
        return str;
    }
}

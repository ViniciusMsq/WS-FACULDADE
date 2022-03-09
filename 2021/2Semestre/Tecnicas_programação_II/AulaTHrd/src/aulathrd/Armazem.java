/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aulathrd;

/**
 *
 * @author Vinicius
 */
public class Armazem {
    private int conteudo;
    
    public Armazem(){
    }
    
    public void put(int valor){
       this.conteudo = valor; 
    }
    
    public int get(){
        return this.conteudo;
    }
    
}

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
public class Produtor extends Thread{
    
    private Armazem armazem;
    
    public Produtor(Armazem a){
        this.armazem = a;
    }
    
    @Override
    public void run(){
        for (int i =0; i<10; i++){
            this.armazem.put(i);
            System.out.println("Produtor produziu valor: " + i);
        }
    }
}

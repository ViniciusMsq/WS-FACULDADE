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
public class Consumidor extends Thread{
    
    private Armazem armazem;
    
    public Consumidor(Armazem a){
        this.armazem = a;
    }
    
    @Override
    public void run(){
        int valor;
        for(int i= 0; i<10;i++){
            valor = this.armazem.get();
            System.out.println("Consumidor consumiu valor: " + valor);
        }
    }
    
}

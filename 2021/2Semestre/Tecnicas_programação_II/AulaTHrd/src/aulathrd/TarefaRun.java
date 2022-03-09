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
public class TarefaRun implements Runnable{
    
    @Override
    public void run(){
        for(int i=0; i<1000; i++){
            System.out.println("Utilizando Runable:" +i);
        }
    }
    
}

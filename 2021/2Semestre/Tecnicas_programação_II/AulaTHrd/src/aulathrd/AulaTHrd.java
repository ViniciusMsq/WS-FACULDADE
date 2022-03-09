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
public class AulaTHrd {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        Armazem armazem = new Armazem();
        Produtor p1 = new Produtor(armazem);
        Consumidor c1 = new Consumidor(armazem);
        
        p1.start();
        c1.start();
        
        
        
       /* Tarefa tar =  new Tarefa();
        tar.start();
        TarefaRun obRunnable = new TarefaRun();
        Thread thRunnable =  new Thread(obRunnable);
        thRunnable.start();
        
        for(int i=0; i<1000; i++){
            System.out.println("Vai Corinthians");
        }*/
    }
    
}

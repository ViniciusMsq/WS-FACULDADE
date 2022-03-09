/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mycompany.prova1;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JFrame;
import javax.swing.JOptionPane;

/**
 *
 * @author Vinicius
 */
public class Main {
    public static void gravar(File file, int valor){
    
        try {
            if(!file.exists()){
                file.createNewFile();
            }
            FileWriter fw =  new FileWriter(file, true); 
            BufferedWriter bw = new BufferedWriter(fw);
            
            bw.write(valor + "\n");

            bw.close();
            fw.close();
            
            
        }catch (IOException ex){
                Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    public static void main(String[] args) {
       String n; 
       int num;
       File file = new File("MeuDiretorio\\numeros.txt");
       JFrame frame = new JFrame();
       frame.setResizable(false);
       
       n = "";
       while(!"FIM".equals(n.toUpperCase())){
           n = JOptionPane.showInputDialog(null, "Informe um numero");
           if("FIM".equals(n.toUpperCase())){
                frame.dispose();
           }else{
                num = Integer.parseInt(n);
                gravar(file, num); 
           }  
       }
       
       /* Exercicio 1
       Object [] options = {"Claro","Mais ou menos","Não"};
       
       
       int i = JOptionPane.showOptionDialog(frame, "Gosta das aulas de LTP", "Opinião",
                                            JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE,null, 
                                            options, options[0]);*/
       //System.out.println(i);
       
       
             
       
    }
}

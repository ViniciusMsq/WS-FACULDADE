/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mycompany.mavenproject1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.OutputStream;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Vinicius
 */


public class Main {
    
    public static void gravarBinario(){
        try {
            int a = 57;
            OutputStream os = new FileOutputStream("MeuDiretorio\\arquivoBinario.bin");
        
            os.write(a);           
            os.close();
            
        } catch (IOException ex) {
            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
        }
    
    }
    public static void gravar(File file){
    
        try {
            if(!file.exists()){
            
                file.createNewFile();
            }
            FileWriter fw =  new FileWriter(file, true); 
            BufferedWriter bw = new BufferedWriter(fw);
            
            bw.write("Vinicius mesquini\n");
            bw.write("Alexandre\n");
            bw.write("Julio\n");

            bw.close();
            fw.close();
            
            
        }catch (IOException ex){
                Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    public static String ler(File file){
        
        if(!file.exists()){
            System.out.print("Não existe esse arquivo para leitura");
            return "";
        }
        
        String str = "";
        try {
            FileReader fr =  new FileReader(file);
            
            BufferedReader br = new BufferedReader(fr);
            while(br.ready()){
             str = str + ", " + br.readLine();
            }
            br.close();
            fr.close();
        } catch (FileNotFoundException ex) {
            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        return str;
    }
    /** 
     * 
     * @param args
     */
    public static void main(String[] args){
       
        /*USANDO ARQUIVOS
        File arq = new File("MeuDiretorio");
        
        
        if(arq.exists()){
                System.out.println("Diretorio já existe");
        }else{
            arq.mkdir();
            System.out.println("Diretorio criado");
        }
        if(arq.isDirectory()){ 
            System.out.println("É diretorio");
            
            String[] arquivos = arq.list();
            
            for(String arquivo : arquivos){
                File arq2 = new File("src\\"+arquivo);
                System.out.print(arquivo);
                if(arq2.isFile()) System.out.println(" - É arquivo");
                if(arq2.isDirectory()) System.out.println(" - É diretorio");

            }
        }
        if(arq.isFile()) System.out.println("É arquivo");
        System.out.println("Tamanho: " + arq.length());
        System.out.println("Caminho: " + arq.getPath());
        System.out.println("Caminho: " + arq.getAbsolutePath());
        */
        /* arq.delete();*/
        
        /*Arquivo texto*/
        
        //File file = new File("MeuDiretorio\\arquivoTeste2.txt");
        //gravar(file);
        //System.out.println(ler(file));
        
        gravarBinario();
    }
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Back;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * 
 */
public class Arquivo {
    private ObjectOutputStream OOS;
    
    public Arquivo(File arq) throws FileNotFoundException, IOException
    {
        OOS = new ObjectOutputStream(new FileOutputStream(arq));
    }
    
    public void gravarPessoa(Pessoa p) throws IOException
    {
        OOS.writeObject(p);
    }
    
    public void fecharArquivo() throws IOException
    {
        OOS.close();
    }
    
    public static String ListarPessoa(File arq) throws ClassNotFoundException, IOException
    {
        String strRet = "";
        
                FileInputStream fis = new FileInputStream(arq);
                ObjectInputStream ois = new ObjectInputStream(fis);
                
                Pessoa pessoaLido;
                
                while(fis.available() >0)
                {            
                pessoaLido = (Pessoa) ois.readObject();  
                strRet += pessoaLido.getPessoa() + "\n";
                }
                
                ois.close();
                fis.close();
                
                
        return strRet;
    }
    
    public static String ProcurarPessoa(File arq,String procurando) throws ClassNotFoundException
    {
        String strRet = "";
        try
            {
                FileInputStream fis = new FileInputStream(arq);
                ObjectInputStream ois = new ObjectInputStream(fis);
                
                Pessoa pessoaLido;
                int Encontro = 0;
                while(fis.available() >0)
                {
                pessoaLido = (Pessoa) ois.readObject();                
                String[] separador = pessoaLido.getPessoa().split("-");
                if(separador[0].equals(procurando))
                {
                    strRet += pessoaLido.getPessoa();
                    Encontro++;
                }
                
                }
                if(Encontro==0)
                {
                    strRet += "Nao foi encontrado esse cadastro";
                }
                
                ois.close();
                fis.close();
                
            }catch(IOException ex)
            {
              Logger.getLogger(Arquivo.class.getName()).log(Level.SEVERE, null, ex);
            }
        return strRet;
    }
}

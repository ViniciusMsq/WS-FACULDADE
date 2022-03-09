/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aulaserver;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.InetAddress;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.UnknownHostException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Vinicius
 */
public class AulaServer {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
//        

        
        try {
            
            InetAddress address = InetAddress.getByName("www.unifai.com.br");          
            System.out.println(address.getHostAddress());
            System.out.println(address.getHostName());
            
            
        } catch (UnknownHostException ex) {
            Logger.getLogger(AulaServer.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        
            //try {
//            // TODO code application logic here
//
//            URL url = new URL("https://www.youtube.com/channel/UCmI5qyXLlfKLCGs6jgHPNIA");
//            
//            InputStreamReader reader =  new InputStreamReader(url.openStream());
//            BufferedReader br =  new BufferedReader(reader);
//            String linha = "";
//            while((linha = br.readLine()) != null){
//                System.out.println(linha);
//            }
//            
//        } catch (MalformedURLException ex) {
//            Logger.getLogger(AulaServer.class.getName()).log(Level.SEVERE, null, ex);
//        } catch (IOException ex) {
//            Logger.getLogger(AulaServer.class.getName()).log(Level.SEVERE, null, ex);
//        }
    }
    
}

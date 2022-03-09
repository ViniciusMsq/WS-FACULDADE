/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package projeto;

import java.sql.*;

/**
 *
 * @author Vinicius
 */
public class ConnectionFactory {
    static String url = "jdbc:mysql://localhost:3306/prova";
    static String usuario ="root";
    static String senha = "";
    
    public Connection getConnection(){
        System.out.println("Conectando ao banco de dados");
        try {
            return DriverManager.getConnection(url, usuario, senha);
        } catch (SQLException ex) {
            throw new RuntimeException(ex);
            //Logger.getLogger(ConnectionFactory.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    public static void main (String[] args){
        
       ConnectionFactory minhaConexao = new ConnectionFactory();
       Connection conn = minhaConexao.getConnection();
       
       System.out.println("Success");
    }
}

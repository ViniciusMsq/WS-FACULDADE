/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package projeto;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.logging.Level;
import java.util.logging.Logger;
/**
 *
 * @author willi
 */
public class ConnectionFactory {
    static String url = "jdbc:mysql://localhost:3306/calculadora";
    static String usuario = "root";
    static String senha = "vertrigo";
    
    public Connection getConnection()
    {
        System.out.println("Conectando ao Banco de Dados");
        try {
            return DriverManager.getConnection(url, usuario, senha);
        } catch (SQLException ex) {
            throw new RuntimeException(ex);
            //Logger.getLogger(ConnectionFactory.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    public static void main (String[] args)
    {
        ConnectionFactory minhaConexao = new ConnectionFactory();
        Connection conn = minhaConexao.getConnection();
        System.out.println("Conexao estabelecida com sucesso!");
    }
}

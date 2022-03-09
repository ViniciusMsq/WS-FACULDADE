/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package prova;

import java.sql.ResultSet;
import java.sql.SQLException;
import projeto.DAO.notasDAO;
import projeto.models.notas;

/**
 *
 * @author Vinicius
 */
public class Prova {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws SQLException {
        // TODO code application logic here
        
        notas nt = new notas(12, 8);
        notasDAO ndao = new notasDAO();
        
        ndao.adicionar(nt);
        
        System.out.println("Adicionado maluco");
        
        
        System.out.println("\n\n - Agora aqui um historico -  ");
        
        ndao.getHistorico();
        
    }
    
}

package projeto.DAO;


import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import projeto.ConnectionFactory;
import projeto.models.notas;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Vinicius
 */
public class notasDAO {
   private Connection c;
    
    public notasDAO(){
        this.c = new ConnectionFactory().getConnection();
    }
    
    public void adicionar(notas ca){
        String sql = "INSERT INTO notas(ra,n) VALUES(";
        sql += ca.getRa()+","+ca.getN()+")";
        
        try {
            Statement stmt = this.c.createStatement();
            stmt.executeUpdate(sql);
        } catch (SQLException ex) {
            throw new RuntimeException(ex);
        }
    }
    
    public void adicionarPrepared(notas ca)
    {
        String sql = "insert into notas(ra,a) values(?,?)";
        try {
            PreparedStatement pstmt = this.c.prepareStatement(sql);
            
            pstmt.setDouble(1, ca.getRa());
            pstmt.setDouble(2, ca.getN());
            pstmt.execute();
        } catch (SQLException ex) {
            throw new RuntimeException(ex);
            //Logger.getLogger(calculosDAO.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    public void getHistorico() throws SQLException
    {
        String sql = "select ra,n from notas";
        Statement stmt;    
        ResultSet rs = null;
        try {
            stmt = this.c.createStatement();
            rs = stmt.executeQuery(sql);
        } catch (SQLException ex) {
            throw new RuntimeException(ex);
            //Logger.getLogger(calculosDAO.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        while(rs.next())
            {
                System.out.println(rs.getDouble("ra"));
                System.out.println(rs.getDouble("n"));
                System.out.println("\n");    
                
            }
    }
}

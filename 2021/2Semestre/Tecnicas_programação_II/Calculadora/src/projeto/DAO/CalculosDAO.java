/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package projeto.DAO;

import java.sql.*;
import java.util.logging.Level;
import java.util.logging.Logger;
import projeto.ConnectionFactory;
import projeto.modelo.Calculos;
/**
 *
 * @author Vinicius
 */
public class CalculosDAO {
    private Connection c;
    
    public CalculosDAO(){
        this.c = new ConnectionFactory().getConnection();
    }
    
    public void adicionar(Calculos ca){
        String sql = "INSERT INTO CALCULO(V1,V2,OP,RES) VALUES(";
        sql += ca.getV1()+","+ca.getV2()+",'"+ca.getOp()+"',"+ca.getRes()+")";
        
        try {
            Statement stmt = this.c.createStatement();
            stmt.executeUpdate(sql);
        } catch (SQLException ex) {
            throw new RuntimeException(ex);
        }
    }
    
    public void adicionarPrepared(Calculos ca)
    {
        String sql = "insert into calculo(v1,v2,op,res) values(?,?,?,?)";
        try {
            PreparedStatement pstmt = this.c.prepareStatement(sql);
            
            pstmt.setDouble(1, ca.getV1());
            pstmt.setDouble(2, ca.getV2());
            pstmt.setString(3, ca.getOp());
            pstmt.setDouble(4, ca.getRes());
            pstmt.execute();
        } catch (SQLException ex) {
            throw new RuntimeException(ex);
            //Logger.getLogger(calculosDAO.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    public ResultSet getHistorico()
    {
        String sql = "select v1,v2,op,res from calculo";
        Statement stmt;    
        ResultSet rs = null;
        try {
            stmt = this.c.createStatement();
            rs = stmt.executeQuery(sql);
        } catch (SQLException ex) {
            throw new RuntimeException(ex);
            //Logger.getLogger(calculosDAO.class.getName()).log(Level.SEVERE, null, ex);
        }
        return rs;
    }
}

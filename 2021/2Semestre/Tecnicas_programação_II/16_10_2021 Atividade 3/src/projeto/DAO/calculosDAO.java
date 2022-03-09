/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package projeto.DAO;

import java.sql.ResultSet;
import java.sql.PreparedStatement;
import java.sql.Connection;
import java.sql.SQLException;
import projeto.ConnectionFactory;
import projeto.modelo.calculos;
import java.sql.Statement;
import java.util.logging.Level;
import java.util.logging.Logger;
/**
 *
 * @author willi
 */
public class calculosDAO {
    
    private Connection c;

    public calculosDAO() {
        this.c = new ConnectionFactory().getConnection();
    }
    
    public void adicionar(calculos ca)
    {
        String sql = "insert into calculos(v1,v2,op,res) values(";
        sql += ca.getV1()+","+ca.getV2()+",'"+ca.getOp()+"',"+ca.getRes()+")";
        try {
            Statement stmt = this.c.createStatement();
            stmt.executeUpdate(sql);
        } catch (SQLException ex) {
            throw new RuntimeException(ex);
            //Logger.getLogger(calculosDAO.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    public void adicionarPrepared(calculos ca)
    {
        String sql = "insert into calculos(v1,v2,op,res) values(?,?,?,?)";
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
        String sql = "select v1,v2,op,res from calculos";
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

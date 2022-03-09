/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package projeto.DAO;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import projeto.ConnectionFactory;
import projeto.models.Pessoa;

/**
 *
 * @author Vinicius
 */
public class pessoaDAO {
     private Connection c;

    public pessoaDAO() {
        this.c = new ConnectionFactory().getConnection();
    }

    public void adicionar(Pessoa pessoa) {
        String sql = "insert into pessoa(nome,dataNasc,idade,sexo)values(";
        sql
                += pessoa.getNome()
                + ","
                + pessoa.getDataNasc()
                + ",'"
                + pessoa.getSexo()
                + "',"
                + pessoa.getIdade()
                + ")";
        try {
            Statement stmt = this.c.createStatement();
            stmt.executeUpdate(sql);
        } catch (SQLException ex) {
            throw new RuntimeException(ex);
        }
    }

    public void adicionarPrepared(Pessoa pessoa) {
        String sql = "insert into pessoa(nome,dataNasc,idade,sexo) values(?,?,?,?)";
        try {
            PreparedStatement pstmt = this.c.prepareStatement(sql);

            pstmt.setString(1, pessoa.getNome());
            pstmt.setString(2, pessoa.getDataNasc());
            pstmt.setInt(3, pessoa.getIdade());
            pstmt.setString(4, pessoa.getSexo());

            pstmt.execute();
        } catch (SQLException ex) {
            throw new RuntimeException(ex);
        }
    }

    public ResultSet getHistorico() {
        String sql = "select nome,dataNasc,idade,sexo from pessoa";
        Statement stmt;
        ResultSet rs = null;
        try {
            stmt = this.c.createStatement();
            rs = stmt.executeQuery(sql);
        } catch (SQLException ex) {
            throw new RuntimeException(ex);
        }
        return rs;
    }

    public ResultSet buscarNome(String nome) throws SQLException {
        
        String sql = "select * from pessoa where nome like ?";
        
        PreparedStatement stmt = null;
        ResultSet rs = null;
        try {

            stmt = this.c.prepareStatement(sql);
            stmt.setString(1, "%" + nome + "%");
            rs = stmt.executeQuery();
        } catch (SQLException ex) {
            throw new RuntimeException(ex);
        }
        
        return rs;
        
    }
}

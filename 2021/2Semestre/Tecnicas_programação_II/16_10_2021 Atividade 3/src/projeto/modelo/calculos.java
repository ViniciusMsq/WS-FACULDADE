/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package projeto.modelo;

/**
 *
 * @author willi
 */
public class calculos {
    private int id;
    private double v1,v2,res;
    private String op;
    

    public calculos(int id, double v1, double v2, double res, String op) {
        this.id = id;
        this.v1 = v1;
        this.v2 = v2;
        this.res = res;
        this.op = op;
    }

    public calculos() {
        
    }
     
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public double getV1() {
        return v1;
    }

    public void setV1(double v1) {
        this.v1 = v1;
    }

    public double getV2() {
        return v2;
    }

    public void setV2(double v2) {
        this.v2 = v2;
    }

    public double getRes() {
        return res;
    }

    public void setRes(double res) {
        this.res = res;
    }

    public String getOp() {
        return op;
    }

    public void setOp(String op) {
        this.op = op;
    }
    
    
}

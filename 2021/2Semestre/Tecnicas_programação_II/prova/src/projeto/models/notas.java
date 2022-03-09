/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package projeto.models;

/**
 *
 * @author Vinicius
 */
public class notas {
    
    private int id,ra;
    private double n;

    public notas() {
    }

    public notas(int ra, double n) {
        this.ra = ra;
        this.n = n;
        }
    
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getRa() {
        return ra;
    }

    public void setRa(int ra) {
        this.ra = ra;
    }


    public double getN() {
        return n;
    }

    public void setN(double n) {
        this.n = n;
    }
}

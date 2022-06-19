package com.example.provamobile;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;

import java.util.ArrayList;
import java.util.List;

public class ImovelDAO {

    private Conexao conexao;
    private SQLiteDatabase banco;

    public ImovelDAO (Context context) {
        conexao = new Conexao(context);
        banco = conexao.getWritableDatabase();
    }

    public long inserir(Imovel imovel){
        ContentValues values = new ContentValues();
        values.put("apelido", imovel.getApelido());
        values.put("local", imovel.getLocal());
        values.put("area", imovel.getArea());
        values.put("aluguel", imovel.getAluguel());
        values.put("comprar", imovel.getComprar());
        values.put("queroAlugar", imovel.getQueroAlugar());
        values.put("queroComprar", imovel.getQueroComprar());

        return banco.insert("imovel", null, values);
    }

    /*public List<Imovel> obterTodos(){
        List<Imovel> imoveis = new ArrayList<>();
        Cursor cursor = banco.query("imovel", new String[]{"idImovel", "apelido", "local", "area", "aluguel", "comprar", "queroAlugar", "queroComprar"},
                null, null, null, null, null);

        //Verfica se consegue mover para o proximo registro
        while (cursor.moveToNext()){
            Imovel imovel= new Imovel();
            imovel.setIdImovel(cursor.getInt(0));
            imovel.setApelido(cursor.getString(1));
            imovel.setLocal(cursor.getString(2));
            imovel.setArea(cursor.getString(3));
            imovel.setAluguel(cursor.getString(4));
            imovel.setComprar(cursor.getString(5));
            imovel.setQueroAlugar(cursor.getString(6));
            imovel.setQueroComprar(cursor.getString(7));

            imoveis.add(imovel);
        }
        return imoveis;
    }*/

    public List<Imovel> obterImoveis(String param){
        Cursor cursor;
        List<Imovel> imoveis;

        if(param == "todos") {

            imoveis = new ArrayList<>();
            cursor = banco.query("imovel", new String[]{"idImovel", "apelido", "local", "area", "aluguel", "comprar", "queroAlugar", "queroComprar"},
                    null, null, null, null, null);
        }else{
            imoveis = new ArrayList<>();
            cursor = banco.query("imovel", new String[]{"idImovel", "apelido", "local", "area", "aluguel", "comprar", "queroAlugar", "queroComprar"},
                    "apelido = ?", new String[]{param}, null, null, null);
        }

        //Verfica se consegue mover para o proximo registro
        while (cursor.moveToNext()){
            Imovel imovel= new Imovel();
            imovel.setIdImovel(cursor.getInt(0));
            imovel.setApelido(cursor.getString(1));
            imovel.setLocal(cursor.getString(2));
            imovel.setArea(cursor.getString(3));
            imovel.setAluguel(cursor.getString(4));
            imovel.setComprar(cursor.getString(5));
            imovel.setQueroAlugar(cursor.getString(6));
            imovel.setQueroComprar(cursor.getString(7));

            imoveis.add(imovel);
        }
        return imoveis;
    }
}

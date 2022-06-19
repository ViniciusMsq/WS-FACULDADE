package com.example.prova;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

public class PersistenceHelper extends SQLiteOpenHelper {

    public static final String NOME_BANCO = "ExemploBD";
    public static final int VERSAO = 1;

    private static PersistenceHelper instance;

    private PersistenceHelper(Context context) {
        super(context, NOME_BANCO, null, VERSAO);
    }

    public static PersistenceHelper getInstance(Context context) {
        if (instance == null)
            instance = new PersistenceHelper(context);

        return instance;
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        db.execSQL(ClienteDAO.scriptCriaCliente);
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int i, int i1) {
        db.execSQL(ClienteDAO.scriptDropCliente);
        onCreate(db);
    }
}

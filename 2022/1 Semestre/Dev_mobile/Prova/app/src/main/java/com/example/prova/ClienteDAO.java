package com.example.prova;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;

public class ClienteDAO implements interfaceDAO
{
    public static final String nomeTabela = "Cliente";
    public static final String colunaId   = "idCliente";
    public static final String colunaNome = "nomeCliente";
    public static final String colunaSobrenome = "sobrenomeCliente";

    public static final String scriptCriaCliente = "CREATE TABLE " + nomeTabela + "("
            + colunaId + " INTEGER PRIMARY KEY," + colunaNome + " TEXT,"
            + colunaSobrenome + " TEXT" + ")";

    public static final String scriptDropCliente=  "DROP TABLE IF EXISTS " + nomeTabela;

    private SQLiteDatabase dataBase = null;

    private static ClienteDAO instance;  // singleton
    public static ClienteDAO getInstance(Context context) {
        if(instance == null)
            instance = new ClienteDAO(context);
        return instance;
    }

    private ClienteDAO(Context context) {
        PersistenceHelper persistenceHelper = PersistenceHelper.getInstance(context);
        dataBase = persistenceHelper.getWritableDatabase();
    }

    public void salvar(Object obj) {
        Cliente cliente = (Cliente) obj;   // casting
        ContentValues values = gerarContentValuesCliente(cliente);
        dataBase.insert(nomeTabela, null, values);
    }
    private ContentValues gerarContentValuesCliente(Cliente cliente) {
        ContentValues values = new ContentValues();
        values.put(colunaNome, cliente.getNome());
        values.put(colunaSobrenome, cliente.getSobrenome());
        // Serve para linkar a coluna com o registro:
        return values;
    }
    public Cliente recuperarClienteNome(Cliente cliente) {
        // Este é um procedimento para recuperar um cliente no BD
        //  a partir do Nome
        String query = "SELECT * FROM " + nomeTabela + " where nomeCliente = "+"'"+cliente.getNome()+"'";
        Cursor cursor = dataBase.rawQuery(query, null);
        cliente = construirCliente(cursor);
        return cliente;
    }
    public Cliente recuperarClienteId(Cliente cliente) {
        // Este é um procedimento para recuperar um cliente no BD a partir do Nome
        String query = "SELECT * FROM " + nomeTabela + " where idCliente = "+Integer.toString(cliente.getIdCliente());
        Cursor cursor = dataBase.rawQuery(query, null);
        cliente = construirCliente(cursor);
        return cliente;
    }

    private Cliente construirCliente(Cursor cursor)
    {
        if (cursor == null)
            return null;
        try {
            cursor.moveToFirst();    // posiciona o cursor - recupera o primeiro que localizar
            // retorna a coluna do campo - inteiro
            int indexId        = cursor.getColumnIndex(colunaId);
            int indexNome      = cursor.getColumnIndex(colunaNome);
            int indexSobrenome =  cursor.getColumnIndex(colunaSobrenome);

            int id = cursor.getInt(indexId);
            String nome = cursor.getString(indexNome);
            String sobrenome = cursor.getString(indexSobrenome);
            // cria uma nova instancia do cliente e retorna o mesmo
            return new Cliente(nome, sobrenome, id);

        }
        catch (Exception e)
        {
            return null;
        }

    }
}


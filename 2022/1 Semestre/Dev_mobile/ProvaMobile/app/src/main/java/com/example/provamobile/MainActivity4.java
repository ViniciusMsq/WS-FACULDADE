package com.example.provamobile;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;
import android.widget.TextView;

import java.util.ArrayList;
import java.util.List;

public class MainActivity4 extends AppCompatActivity {


    private ListView lstImoveis;
    private ImovelDAO imovelDao;
    private List<Imovel> imoveis;
    TextView txtResult;
    Bundle params;
    Intent i;
    Button btnNovoCadastro;
    String pesquisar = "todos";
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main4);
        Bootstrap();
        Listar();

    }

    private void Bootstrap(){
        lstImoveis = findViewById(R.id.lstImoveis);
        btnNovoCadastro = findViewById(R.id.btnNovoCadastro);
        txtResult = findViewById(R.id.txtResult);

        i = getIntent();
        params = i.getExtras();

        if(params!=null)
        {
            pesquisar = params.getString("pesquisa");
        }

        txtResult.setText(pesquisar);

    }

    private void Listar(){

        imovelDao = new ImovelDAO(this);
        imoveis = imovelDao.obterImoveis(pesquisar);

        ArrayAdapter<Imovel> adaptador = new ArrayAdapter<Imovel>(this, android.R.layout.simple_list_item_1, imoveis);
        lstImoveis.setAdapter(adaptador);

    }

    public void OnClickNovoCadastro(View v){
        i = new Intent(this, MainActivity.class);
        startActivity(i);
    }
}
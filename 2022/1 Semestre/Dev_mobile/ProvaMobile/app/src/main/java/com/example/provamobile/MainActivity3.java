package com.example.provamobile;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity3 extends AppCompatActivity {

    Imovel imovel;
    ImovelDAO imovelDao;
    Intent i;
    Bundle params;
    EditText pesquisar;
    Button btnAvançar;
    String apelido, local, area, aluguel, comprar, queroAlugar, queroComprar, pesquisa;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main3);
        Bootstrap();
        salvar();
    }


    private void Bootstrap(){
        btnAvançar = findViewById(R.id.btnAvancarTela3);
        pesquisar = findViewById(R.id.edtPesquisar);
        //Pegando parametros tela 2
        i = getIntent();

        params = i.getExtras();

        if(params!=null)
        {
            apelido = params.getString("apelido");
            local = params.getString("local");
            area = params.getString("area");
            aluguel = params.getString("aluguel");
            comprar = params.getString("comprar");
            queroAlugar = params.getString("queroAlugar");
            queroComprar = params.getString("queroComprar");
        }
    }

    private void salvar(){
        imovel = new Imovel(apelido, local, area, aluguel, comprar, queroAlugar, queroComprar);
        imovelDao = new ImovelDAO(this);

        imovelDao.inserir(imovel);
    }

    public void OnClickAvancar(View v){
        pesquisa = pesquisar.getText().toString();

        if(pesquisa == null || pesquisa == "Pesquisar" || pesquisa == "pesquisar"){
            pesquisa = "todos";
        }

        i = new Intent(this, MainActivity4.class);
        params.putString("pesquisar", pesquisa);
        i.putExtras(params);
        startActivity(i);
    }
}
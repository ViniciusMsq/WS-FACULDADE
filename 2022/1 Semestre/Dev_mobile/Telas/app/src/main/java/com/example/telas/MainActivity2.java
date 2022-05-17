package com.example.telas;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

public class MainActivity2 extends AppCompatActivity {
    private static final String Categoria = "Script = ";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);
        Log.i(Categoria, getClassName()+"***onCreate");
        TextView txtparemetro = findViewById(R.id.txtParametro);

        edtTeste =(EditText)findViewById(R.id.edtTeste);

        Intent i= getIntent();

        Bundle params = i.getExtras();

        if(params!=null)

        {

            String mostraTexto = params.getString(“varmsg");

                    edtTeste.setText(mostraTexto);

        }
    }


    public void onStart()
    { super.onStart();
        Log.i(Categoria, getClassName()+"***onStart");
    }
    public void onRestart()

    { super.onRestart();
        Log.i(Categoria,getClassName()+"***onRestart");
    }

    public void onResume()
    { super.onResume();
        Log.i(Categoria, getClassName()+"***onResume");
    }

    public void onPause()
    {
        super.onPause();
        Log.i(Categoria, getClassName()+"onPause");
    }

    private String getClassName(){
        String aux = getClass().getName();
        return (aux.substring(aux.lastIndexOf(".")+ 1));
    }
}
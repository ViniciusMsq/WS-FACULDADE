package com.example.telas;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;

public class MainActivity extends AppCompatActivity {

    private static final String Categoria = "Script = ";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Log.i(Categoria, getClassName()+"***onCreate");

        Intent i = new Intent(this, MainActivity2.class);
        Bundle params = new Bundle();
        params.putString("varmsg", "Vinicius");
        i.putExtras(params);
        startActivity(i);
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
package com.example.sharedprefence;

import androidx.appcompat.app.AppCompatActivity;

import android.content.SharedPreferences;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    private final static String ARQ_PREF = "PREF";
    Preferencia pref;
    TextView txtHello;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        bootstrap();
    }

    protected void bootstrap(){
        txtHello = findViewById(R.id.txtHello);
        //SharedPreferences pref = getSharedPreferences(ARQ_PREF, 0);

        pref = new Preferencia(getApplicationContext());
        //pref.salvarDados("93-19");

        txtHello.setText(pref.retornarDados());

        //permite alteração

        /*SharedPreferences.Editor editor = pref.edit();
        editor.putString("ra", "0093-19");
        editor.commit();

        if (pref.contains("ra")){
            txtHello.setText(pref.getString("ra", ""));
        }*/

    }

}
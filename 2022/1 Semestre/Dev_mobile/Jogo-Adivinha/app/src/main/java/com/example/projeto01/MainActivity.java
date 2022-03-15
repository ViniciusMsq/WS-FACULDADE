package com.example.projeto01;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import java.util.Random;

public class MainActivity extends AppCompatActivity {
    TextView txtTexto;
    TextView txtContagem;
    Button btnOk;
    Button btnNewGame;
    EditText edtChute;

    int ValorRandom;
    int ValorDigitado;
    int Contador = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        bootStrap();
        NewGame();
        edtChute.requestFocus();
    }

    public void btnOkClick(View v){
         //txtTexto.setText("Vinicius Mesquini click");
        // Toast.makeText(this, "Graças a Deus PAI", Toast.LENGTH_SHORT).show();
       // txtTexto.setText(edtChute.getText().toString());

        if (edtChute.getText().toString().equalsIgnoreCase("")){
            ValorDigitado = 0;
        }else {
            ValorDigitado = Integer.parseInt((edtChute.getText().toString()));
        }
        Contador = Contador + 1;
        txtContagem.setText("+" + Contador);
        ValidaValor(ValorDigitado, ValorRandom);
    }

    public void btnNewGameClick(View v){
        NewGame();
    }

    private void bootStrap(){
        txtTexto = findViewById(R.id.txtTexto);
        txtContagem = findViewById(R.id.txtContagem);
        btnOk = findViewById(R.id.BtnOk);
        edtChute = findViewById(R.id.edtChute);
        btnNewGame = findViewById(R.id.btnNewGame);
    }

    private void ValidaValor(int Vdigitado, int Vrandom){
        edtChute.setText("");
        edtChute.requestFocus();

        if(Vdigitado > Vrandom){txtTexto.setText(Vdigitado + " > X"); Toast.makeText(this, "Valor errado: tente uma valor menor", Toast.LENGTH_SHORT).show();}
        else if(Vdigitado < Vrandom){txtTexto.setText(Vdigitado + " < X"); Toast.makeText(this, "Valor errado: tente uma valor maior", Toast.LENGTH_SHORT).show();}
        else {
            txtTexto.setText("valor: " + Vrandom);
            Toast.makeText(this, "Valor Correto, Parabéns!", Toast.LENGTH_SHORT).show();
            btnOk.setEnabled(false);
            btnNewGame.setEnabled(true);
            btnNewGame.requestFocus();
        }
    }

    private void NewGame(){
        edtChute.setText("");
        txtTexto.setText("Começou chute um valor");
        btnOk.setEnabled(true);
        btnNewGame.setEnabled(false);
        Contador = 0;
        txtContagem.setText("0");
        Random number = new Random();
        ValorRandom =  number.nextInt(100);
        edtChute.requestFocus();
    }
}
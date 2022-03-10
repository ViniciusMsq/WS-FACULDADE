package com.example.projeto01;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import com.google.android.material.textfield.TextInputEditText;

public class MainActivity extends AppCompatActivity {
    TextView txtTexto;
    Button btnOk;
    EditText edtNome;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        bootStrap();
    }

    public void btnOkClick(View v){
        //txtTexto.setText("Vinicius Mesquini click");
        Toast.makeText(this, "Graças a Deus PAI", Toast.LENGTH_SHORT).show();

        txtTexto.setText(edtNome.getText().toString());
    }

    private void bootStrap(){
        txtTexto = findViewById(R.id.txtTexto);
        btnOk = findViewById(R.id.BtnOk);
        edtNome = findViewById(R.id.edtNome);

    }
}
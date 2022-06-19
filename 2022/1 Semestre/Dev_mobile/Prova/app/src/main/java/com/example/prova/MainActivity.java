package com.example.prova;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    TextView txtNome;
    TextView txtSobrenome;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        txtNome = findViewById(R.id.txtNome);
        txtSobrenome = findViewById(R.id.txtSobrenome);

        ClienteDAO clienteDAO = ClienteDAO.getInstance(getBaseContext());
        Cliente cliente = new Cliente("ana", "Oliveira");

        clienteDAO.salvar(cliente);

        cliente = new Cliente("beto","medeiros");
        clienteDAO.salvar(cliente);

        // atribui valores ao cliente para ser pesquisado
        cliente = new Cliente("ana","Oliveira");
        cliente = clienteDAO.recuperarClienteNome(cliente);
    }
}
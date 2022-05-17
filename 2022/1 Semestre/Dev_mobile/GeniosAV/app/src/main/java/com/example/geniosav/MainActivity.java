package com.example.geniosav;

import androidx.appcompat.app.AppCompatActivity;

import android.content.res.ColorStateList;
import android.graphics.Color;
import android.os.Bundle;
import android.os.Handler;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.Random;
import java.lang.Math;

public class MainActivity extends AppCompatActivity {

    //Cores iniciais
    String corGreen_Initial = "#027007";
    String corYellow_Initial = "#918201";
    String corBlue_Initial = "#044891";
    String corRed_Initial = "#730202";
    //Cores Acesas
    String corGreen_Lit = "#00FD0C";
    String corYellow_Lit = "#FFE503";
    String corBlue_Lit = "#02A6FF";
    String corRed_Lit = "#FF0202";

    //Componentes
    TextView txtvRecord, txtvRound;
    Button btnGreen, btnYellow, btnBlue, btnRed, btnNewGame;

    //controle de delay
    Handler handler = new Handler();

    //SharedPreference
    private final static String ARQ_PREF = "PREF";
    Preference pref;

    //variaveis de controle
    int point = 0;
    int delay = 1;
    int speed = 500;
    int indexClick = 0;
    int timerClick = 0;
    double difficulty = 0.95;

    //Listas
    ArrayList<Integer> sequenceRandom = new ArrayList();
    ArrayList<Integer> sequencePlayer = new ArrayList();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Bootstrap();
    }

    public void btnNewGameClick(View v) throws InterruptedException {
        NewGame();
    }
    public void btnGreenClick(View v) throws InterruptedException {
        playerClickButtons(0);
    }
    public void btnYellowClick(View v) throws InterruptedException{
        playerClickButtons(1);
    }
    public void btnBlueClick(View v) throws InterruptedException{
        playerClickButtons(2);
    }
    public void btnRedClick(View v) throws InterruptedException{
        playerClickButtons(3);
    }

    private void Bootstrap(){
        btnGreen = findViewById(R.id.btnGreen);
        btnYellow = findViewById(R.id.btnYellow);
        btnBlue = findViewById(R.id.btnBlue);
        btnRed = findViewById(R.id.btnRed);

        btnNewGame = findViewById(R.id.btnNewGame);

        txtvRound = findViewById(R.id.txtvRound);
        txtvRecord = findViewById(R.id.txtvRecord);

        salvaRecord(0);

    }

    private void setValuesDefault(){
        point = 0;
        delay = 1;
        speed = 500;
        indexClick = 0;

        sequencePlayer.clear();
        sequenceRandom.clear();

        txtvRound.setText("00");
    }

    private void setColorsInitials(){
        btnGreen.setBackgroundTintList(ColorStateList.valueOf(Color.parseColor(corGreen_Initial)));
        btnYellow.setBackgroundTintList(ColorStateList.valueOf(Color.parseColor(corYellow_Initial)));
        btnBlue.setBackgroundTintList(ColorStateList.valueOf(Color.parseColor(corBlue_Initial)));
        btnRed.setBackgroundTintList(ColorStateList.valueOf(Color.parseColor(corRed_Initial)));
    }

    private void lockColorButtons(boolean isLock){
        btnGreen.setEnabled(isLock);
        btnYellow.setEnabled(isLock);
        btnBlue.setEnabled(isLock);
        btnRed.setEnabled(isLock);
    }

    private int generateRandomNumber(){
        Random random = new Random();
        return random.nextInt(4);
    }

    private void NewGame() throws InterruptedException {
        btnNewGame.setEnabled(false);
        setValuesDefault();
        round();
    }



    private void round() throws InterruptedException {

        sequenceRandom.add(generateRandomNumber());

        for (int i = 0; i < sequenceRandom.size(); i++) {

            handler.postDelayed(new Runnable() {
                public void run() {
                    setColorsInitials();
                }
            }, delay * speed);
            delay++;

            switch (sequenceRandom.get(i)) {
                case 0: handler.postDelayed(new Runnable() {
                            public void run() {
                                btnGreen.setBackgroundTintList(ColorStateList.valueOf(Color.parseColor(corGreen_Lit)));
                            }
                        },  delay*speed);
                        delay++;
                    break;
                case 1: handler.postDelayed(new Runnable() {
                            public void run() {
                                btnYellow.setBackgroundTintList(ColorStateList.valueOf(Color.parseColor(corYellow_Lit)));
                            }
                        }, delay * speed);
                        delay++;
                    break;
                case 2: handler.postDelayed(new Runnable() {
                            public void run() {
                                btnBlue.setBackgroundTintList(ColorStateList.valueOf(Color.parseColor(corBlue_Lit)));
                            }
                        }, delay * speed);
                        delay++;
                    break;
                case 3: handler.postDelayed(new Runnable() {
                            public void run() {
                                btnRed.setBackgroundTintList(ColorStateList.valueOf(Color.parseColor(corRed_Lit)));
                            }
                        }, delay * speed);
                        delay++;
                    break;
            }

            if (sequenceRandom.size() - 1 == i) {
                handler.postDelayed(new Runnable() {
                    public void run() {
                        indexClick = 0;
                        setColorsInitials();
                        sequencePlayer.clear();
                        lockColorButtons(true);
                    }
                }, delay * speed);
            }
        }
    }



    private void playerClickButtons(int colorButton) throws InterruptedException {
        indexClick++;
        timerClick++;
        sequencePlayer.add(colorButton);
        comparingSequence();
    }

    private void comparingSequence() throws InterruptedException {

        for (int index = 0; index < indexClick; index++) {

            if (sequenceRandom.get(index) != sequencePlayer.get(index)) {
                salvaRecord(point);
                btnNewGame.setEnabled(true);
                lockColorButtons(false);
                Toast.makeText(this, "Sequencia errada, você está eliminado", Toast.LENGTH_LONG).show();
            } else {
                if (index == sequenceRandom.size()-1) {
                    point++;
                    delay = 1;
                    speed = (int) Math.floor(speed * difficulty);
                    txtvRound.setText(""+point);
                    lockColorButtons(false);
                    Toast.makeText(this, "Sequencia correta, vamos para proxima rodada", Toast.LENGTH_LONG).show();
                    round();
                }
            }
        }
    }

    public void salvaRecord(int qtAcertos){
        pref = new Preference(getApplicationContext());

        String recordAtual = pref.recuperarDados();

        if(recordAtual == ""){
            recordAtual = "0";
        }

        if(qtAcertos > Integer.parseInt(recordAtual)){
            pref.salvarDados(Integer.toString(qtAcertos));
        }
        txtvRecord.setText(pref.recuperarDados());
    }


    /*private void timeOfPlay() {
        handler.postDelayed(new Runnable() {
            public void run() {
                if(timerClick != 0){
                    System.out.println("teste");
                    timerClick = 0;
                }else{
                    timerClick = 0;
                    //endGame();
                    System.out.println("teste2");
                }
            }
        }, delay*1000);
    }*/

    /*private void endGame(){
        salvaRecord(point);
        btnNewGame.setEnabled(true);
        lockColorButtons(false);
        Toast.makeText(this, "Sequencia errada, você está eliminado", Toast.LENGTH_LONG).show();
    }*/
}
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
    Button btnGreen, btnYellow, btnBlue, btnRed, btnNewGame, btnSendGame;
    TextView txtvRecord;

    Handler handler = new Handler();




    //variaveis de controle
    int ValueRandom;
    int ValueRecord;
    int indexClick = 0;
    int point = 0;
    int delay = 1;
    int speed = 500;

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

        txtvRecord = findViewById(R.id.txtvRecord);
    }

    private void setColorsInitials(){
                btnGreen.setBackgroundTintList(ColorStateList.valueOf(Color.parseColor(corGreen_Initial)));
                btnYellow.setBackgroundTintList(ColorStateList.valueOf(Color.parseColor(corYellow_Initial)));
                btnBlue.setBackgroundTintList(ColorStateList.valueOf(Color.parseColor(corBlue_Initial)));
                btnRed.setBackgroundTintList(ColorStateList.valueOf(Color.parseColor(corRed_Initial)));
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
                case 0:
                    handler.postDelayed(new Runnable() {
                        public void run() {
                            btnGreen.setBackgroundTintList(ColorStateList.valueOf(Color.parseColor(corGreen_Lit)));
                        }
                    }, delay * speed);
                    delay++;
                    break;
                case 1:
                    handler.postDelayed(new Runnable() {
                        public void run() {
                            btnYellow.setBackgroundTintList(ColorStateList.valueOf(Color.parseColor(corYellow_Lit)));
                        }
                    }, delay * speed);
                    delay++;
                    break;
                case 2:
                    handler.postDelayed(new Runnable() {
                        public void run() {
                            btnBlue.setBackgroundTintList(ColorStateList.valueOf(Color.parseColor(corBlue_Lit)));
                        }
                    }, delay * speed);
                    delay++;
                    break;
                case 3:
                    handler.postDelayed(new Runnable() {
                        public void run() {
                            btnRed.setBackgroundTintList(ColorStateList.valueOf(Color.parseColor(corRed_Lit)));
                        }
                    }, delay * speed);
                    delay++;
                    break;
            }

            /*if(arrayNum[i] == 0){
                handler.postDelayed(new Runnable() { public void run(){
                    btnGreen.setBackgroundTintList(ColorStateList.valueOf(Color.parseColor(corGreen_Lit)));
                }}, delay * speed);
                delay++;
            }

            if(arrayNum[i] == 1){
                handler.postDelayed(new Runnable() { public void run(){
                    btnYellow.setBackgroundTintList(ColorStateList.valueOf(Color.parseColor(corYellow_Lit)));
                }}, delay * speed);
                delay++;
            }

            if(arrayNum[i] == 2){
                handler.postDelayed(new Runnable() { public void run(){
                    btnBlue.setBackgroundTintList(ColorStateList.valueOf(Color.parseColor(corBlue_Lit)));
                }}, delay * speed);
                delay++;
            }

            if(arrayNum[i] == 3){
                handler.postDelayed(new Runnable() { public void run(){
                    btnRed.setBackgroundTintList(ColorStateList.valueOf(Color.parseColor(corRed_Lit)));
                }}, delay * speed);
                delay++;
            }

            if(arrayNum.length-1 == i){
                handler.postDelayed(new Runnable() { public void run(){
                    btnGreen.setBackgroundTintList(ColorStateList.valueOf(Color.parseColor(corGreen_Initial)));
                    btnYellow.setBackgroundTintList(ColorStateList.valueOf(Color.parseColor(corYellow_Initial)));
                    btnBlue.setBackgroundTintList(ColorStateList.valueOf(Color.parseColor(corBlue_Initial)));
                    btnRed.setBackgroundTintList(ColorStateList.valueOf(Color.parseColor(corRed_Initial)));
                }}, delay * speed);
            }*/


            if (sequenceRandom.size() - 1 == i) {
                handler.postDelayed(new Runnable() {
                    public void run() {
                        setColorsInitials();
                        unlockColorButtons();
                        indexClick = 0;
                        sequencePlayer.clear();
                    }
                }, delay * speed);

            }
        }
    }

    private void NewGame() throws InterruptedException {
        btnNewGame.setEnabled(false);
        delay = 1;
        indexClick = 0;
        point = 0;
        sequencePlayer.clear();
        sequenceRandom.clear();
        round();
    }

    private void unlockColorButtons(){
        btnGreen.setEnabled(true);
        btnYellow.setEnabled(true);
        btnBlue.setEnabled(true);
        btnRed.setEnabled(true);

    }

    private void lockColorButtons(){
        btnGreen.setEnabled(false);
        btnYellow.setEnabled(false);
        btnBlue.setEnabled(false);
        btnRed.setEnabled(false);

    }

    private int generateRandomNumber(){
        Random random = new Random();
        return random.nextInt(4);
    }

    private void comparingSequence() throws InterruptedException {

        for (int index = 0; index < indexClick; index++) {

            System.out.println("IndexClick: "+indexClick);
            System.out.println("Player("+index+")"+sequencePlayer.get(index));
            System.out.println("Radoom("+index+")"+sequenceRandom.get(index));
            System.out.println(sequencePlayer.toString() + " --- " + sequenceRandom.toString());

            if (sequenceRandom.get(index) != sequencePlayer.get(index)) {
                ValueRecord = point;
                lockColorButtons();
                btnNewGame.setEnabled(true);
                Toast.makeText(this, "Sequencia errada, você está eliminado", Toast.LENGTH_LONG).show();

            } else {
                point++;

                if (index == sequenceRandom.size()-1) {
                    Toast.makeText(this, "Sequencia correta, vamos para proxima rodada", Toast.LENGTH_LONG).show();
                    lockColorButtons();
                    txtvRecord.setText(""+point);
                    round();
                }

            }
        }
    }

    private void playerClickButtons(int colorButton) throws InterruptedException {
        indexClick++;
        sequencePlayer.add(colorButton);
        comparingSequence();

    }


}
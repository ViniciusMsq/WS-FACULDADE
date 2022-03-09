#include <Servo.h>
#define servoPin 3
#define btnE 11
#define btnD 10
#define potPin 0

Servo braco;

int valor = 90;

void setup()
{
  Serial.begin(9600);
  braco.attach(servoPin);
  pinMode(btnE, INPUT_PULLUP);
  pinMode(btnD, INPUT_PULLUP);
  braco.write(valor);
  Serial.println("iniciando...");
  
}

void loop()
{
  int valPot = analogRead(potPin);
  valPot = map(valPot, 0, 1023, 0, 180);
  
  int estadoE = digitalRead(btnE);
  int estadoD = digitalRead(btnD);
  delay(200);
  
  if(estadoE == 0){
    valor = valor + valPot;
    if(valor>180){
      valor = 180;
    }
    braco.write(valor);
  }
  
  if(estadoD == 0){
    valor = valor - valPot;
    if(valor<0){
      valor = 0;
    }
    braco.write(valor);
  }
  
  Serial.println(valor);
  Serial.println(valPot);
}
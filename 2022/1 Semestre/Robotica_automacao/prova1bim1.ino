#include <LiquidCrystal.h>

#define pinTrig 10
#define pinEcho 13

#define ledPinR 9
#define ledPinY 3
#define ledPinG 2

LiquidCrystal led(12, 11, 4, 5, 6, 7);

const float velSom = 0.000340;

void setup()
{
  led.begin(16,2);
  led.setCursor(0,0);
  
  pinMode(pinEcho, INPUT);
  pinMode(pinTrig, OUTPUT);
  
  pinMode(ledPinR, OUTPUT); 
  pinMode(ledPinY, OUTPUT); 
  pinMode(ledPinG, OUTPUT); 
  
  Serial.begin(9600); 
}

void loop()
{
  DispararPulso();
  
  float tempoEcho = pulseIn(pinEcho, HIGH);
  Serial.println(Distancia(tempoEcho));
  
  float dist = Distancia(tempoEcho);
  
  led.setCursor(0,0);
  led.print(dist);
  
  if ( dist <= 1 ) 
  {
    digitalWrite(ledPinR, HIGH);
    digitalWrite(ledPinY, LOW);
    digitalWrite(ledPinG, LOW);
    Serial.println("led VERMELHO...");
    led.setCursor(0,1);
    led.print("PARE...");
  }
  else if ( dist <= 2 and dist > 1 ) 
  {
    digitalWrite(ledPinR, LOW);
    digitalWrite(ledPinY, HIGH);
    digitalWrite(ledPinG, LOW);
    Serial.println("led AMARELO...");
    led.setCursor(0,1);
    led.print("ATENCAO...");
  }
  else
  {
    digitalWrite(ledPinR, LOW);
    digitalWrite(ledPinY, LOW);
    digitalWrite(ledPinG, HIGH); 
    Serial.println("led VERDE...");
    led.setCursor(0,1);
    led.print("SIGA...");
  }
  
  delay(500);
}

void DispararPulso(){
 	
  	digitalWrite(pinTrig, HIGH);
  	delayMicroseconds(10);
    digitalWrite(pinTrig, LOW);
}

float Distancia(float tempo){

	return((tempo*velSom)/2);
}
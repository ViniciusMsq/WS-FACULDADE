#define LedVerm 12
#define LedAzul 10
#define LedVerd 8

void setup()
{
  Serial.begin(9600);
  pinMode(LedVerm, OUTPUT);
  pinMode(LedAzul, OUTPUT);
  pinMode(LedVerd, OUTPUT);
  digitalWrite(LedVerm, LOW);
  digitalWrite(LedAzul, LOW);
  digitalWrite(LedVerd, LOW);

}

void loop()
{
  char led = Serial.read();
  Serial.println(led);
  switch(led){
	case 'r': 
    	digitalWrite(LedVerm, HIGH);
  		digitalWrite(LedAzul, LOW);
  		digitalWrite(LedVerd, LOW);
   		break;
    case 'g':
    	digitalWrite(LedVerm, LOW);
  		digitalWrite(LedAzul, LOW);
  		digitalWrite(LedVerd, HIGH);
        break;
    case 'b':
    	digitalWrite(LedVerm, LOW);
  		digitalWrite(LedAzul, HIGH);
  		digitalWrite(LedVerd, LOW);
        break;
    case 'y':
    	digitalWrite(LedVerm, HIGH);
  		digitalWrite(LedAzul, LOW);
  		digitalWrite(LedVerd, HIGH);
        break;
    case 'm':
    	digitalWrite(LedVerm, HIGH);
  		digitalWrite(LedAzul, HIGH);
  		digitalWrite(LedVerd, LOW);
        break;
    case 'c':
    	digitalWrite(LedVerm, LOW);
  		digitalWrite(LedAzul, HIGH);
  		digitalWrite(LedVerd, HIGH);
        break;
    case 'w':
    	digitalWrite(LedVerm, HIGH);
  		digitalWrite(LedAzul, HIGH);
  		digitalWrite(LedVerd, HIGH);
        break;
    case 'o':
    	digitalWrite(LedVerm, LOW);
  		digitalWrite(LedAzul, LOW);
  		digitalWrite(LedVerd, LOW);
        break;
    
  }
  delay(1000);
}
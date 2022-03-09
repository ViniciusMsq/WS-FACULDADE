#define LedVerm 4
#define LedAmar 3
#define LedVerd 2

void setup()
{
  Serial.begin(9600);
  pinMode(LedVerm, OUTPUT);
  pinMode(LedAmar, OUTPUT);
  pinMode(LedVerd, OUTPUT);
  digitalWrite(LedVerm, LOW);
  digitalWrite(LedAmar, LOW);
  digitalWrite(LedVerd, LOW);

}

void loop()
{
  char led = Serial.read();
  Serial.println(led);
  switch(led){
	case 'a': 
    	digitalWrite(LedVerm, HIGH);
  		digitalWrite(LedAmar, LOW);
  		digitalWrite(LedVerd, LOW);
   		break;
    case 'b':
    	digitalWrite(LedVerm, LOW);
  		digitalWrite(LedAmar, HIGH);
  		digitalWrite(LedVerd, LOW);
        break;
    case 'c':
    	digitalWrite(LedVerm, LOW);
  		digitalWrite(LedAmar, LOW);
  		digitalWrite(LedVerd, HIGH);
        break;
  }
  delay(1000);
}
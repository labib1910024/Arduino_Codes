int pir = 2;
int buzzer = 9;

void setup()
{
  pinMode(pir,INPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int motionDetect = digitalRead(pir);
  
  if(motionDetect == HIGH)
  {
    Serial.println(" Detected ");
    digitalWrite( buzzer,HIGH);
    delay(500);
    digitalWrite(buzzer,LOW);
  }

  else
  {
    Serial.println(" Detected ");
  }

  delay(500);
}

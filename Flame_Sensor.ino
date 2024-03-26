int buzzer = 12;
int flame = 11;
int red = 5;
int green = 6;
int Flame = HIGH;
void setup() {
  pinMode(buzzer,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(flame,INPUT);

  Serial.begin(9600);

}

void loop() {
  Flame = digitalRead(flame);
  if(Flame == LOW)
  {
    digitalWrite(buzzer,HIGH);
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
  }

  else
  {
    digitalWrite(buzzer,LOW);
    digitalWrite(red,LOW);
    digitalWrite(green,HIGH);
  }

}

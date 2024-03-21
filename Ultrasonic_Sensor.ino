int trigPin = 9;
int echoPin = 10;

long duration;
int distance;

void setup() {
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

   Serial.begin(9600);
}

void loop() {
  
  digitalWrite(trigPin, LOW);
  delay(2000);
 
  digitalWrite(trigPin, HIGH);
  delay(10000);
  digitalWrite(trigPin, LOW);
  
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  
 
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  
  delay(1000);
}

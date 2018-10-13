#define trigPin 7
#define echoPin 6


 
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
 
void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance <= 0 || distance >= 20)
  {
    Serial.println("no error");
  }
  else 
  {
    Serial.println("Error of depth ");
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);
}

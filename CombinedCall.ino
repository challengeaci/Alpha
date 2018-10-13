#include <dht.h>
const int pingPin = 6;
const int echoPin = 7;
dht DHT;

#define DHT11_PIN 8

void setup() {
  // put your setup code here, to run once:

pinMode(11,OUTPUT);

Serial.begin(9600);
}

void loop() {
Infrared();
Ultrasonic();
Humidity();
Serial.println();
delay(1000);
}
void Infrared(){
   
Serial.println(analogRead(A0));
if(analogRead(A0) < 250){
digitalWrite(11,HIGH);
}
else{
digitalWrite(11,LOW);
}
}
void Ultrasonic() 
{
  long duration, inches, cm;
  pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   Serial.print(inches);
   Serial.print("in, ");
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
  
}
long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
void Humidity()
{
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
}

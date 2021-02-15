#include <Arduino.h>

const int ledPin = 13;
const int SensorPin = 2;

void setup(){
  pinMode(ledPin,OUTPUT);
  pinMode(SensorPin,INPUT);
  digitalWrite(SensorPin, HIGH);
}

void loop(){
  int digitalVal = digitalRead(SensorPin);
  if(HIGH == digitalVal){
    digitalWrite(ledPin,LOW);
    }
  else{
    digitalWrite(ledPin,HIGH);
    }
}
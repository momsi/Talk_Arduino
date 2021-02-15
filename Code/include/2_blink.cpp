#include <Arduino.h>

int red = 2;
int time = 200;

void setup(){
  pinMode(red, OUTPUT);
}

void loop(){
  digitalWrite(red, HIGH);
  delay(time);
  digitalWrite(red, LOW);
  delay(time);
}
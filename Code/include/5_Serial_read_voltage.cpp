#include <Arduino.h>

int potPin = A0;
int val = 0;
float volt = 0.0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  val = analogRead(potPin);
  volt = (val * 5.0/1023.0);
  Serial.println(volt);
  delay(333);
}
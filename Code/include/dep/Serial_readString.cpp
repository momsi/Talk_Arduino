#include <Arduino.h>

String text = "";

void setup() {
  Serial.begin(9600);
}

void loop() {
if (Serial.available() > 0) {
  text = Serial.readString();
  Serial.print(" I received:");
  Serial.println(text);
  }
}
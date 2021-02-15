#include <Arduino.h>

int green = 12;
int yellow = 5;
int red = 2;
int switchpin = A0;
bool isgreen = false;

void switch_lights(){
  if (isgreen)
  {
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    delay(1500);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    isgreen = false;
  }
  else
  {
    digitalWrite(yellow, HIGH);
    delay(1500);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    isgreen = true;
  }
}

void setup(){
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  digitalWrite(green, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);
  pinMode(switchpin, INPUT_PULLUP);
}

void loop(){
  if (digitalRead(switchpin) == LOW)
  {
    switch_lights();
  }
}
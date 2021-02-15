#include <Arduino.h>

int i = 0;

void setup() {
    Serial.begin(9600);
    Serial.println("Hello AG Lorke, \nI can count to (2^31)-1");
}

void loop() {
    delay(1000);
    Serial.println(i);
    i++;
}
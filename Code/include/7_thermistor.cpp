#include <Arduino.h>

int tempPin = A0;

void setup(){
    Serial.begin(9600);
}

void loop(){
    int tempReading = analogRead(tempPin);
    double tempK = log(10000.0 * ((1024.0 / tempReading - 1)));
    tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * tempK * tempK )) * tempK ) - 4.0;
    float tempC = tempK - 273.15;
    //Serial.print("Temperatur: ");
    Serial.print(tempC);
    Serial.println("°C");
    delay(500);
}
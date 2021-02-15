#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

void display_update(String str){
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(12, 10);
  display.print(str); display.println(" C");
  display.display();
}

int tempPin = A0;
const int ledPin = 13;
const int SensorPin = 2;

void setup(){
    pinMode(ledPin,OUTPUT);
    pinMode(SensorPin,INPUT);
    digitalWrite(SensorPin, HIGH);
    Serial.begin(9600);
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.clearDisplay();
}

void loop(){
    int digitalVal = !digitalRead(SensorPin);
    if(HIGH == digitalVal){
        int tempReading = analogRead(tempPin);
        double tempK = log(10000.0 * ((1024.0 / tempReading - 1)));
        tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * tempK * tempK )) * tempK ) - 4.0;
        float tempC = tempK - 273.15;
        Serial.print(tempC);
        Serial.println(" °C");
        display_update(String(tempC));
        delay(500);
        }
  else{
        display_update("42");
        delay(500);
    }
}
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

void display_update(String str){
  display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(10, 7);
  display.print(str); display.println(" V");
  display.display();
}

int potPin = A0;
int val = 0;
float volt = 0.0;

void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}

void loop() {
  val = analogRead(potPin);
  volt = (val * 5.0/1023.0);
  Serial.println(volt);
  display_update(String(volt));
  delay(333);
}
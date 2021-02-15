#include <Arduino.h>
#include <Stepper.h>

/*
Black   --  GND
White   --  +5V

IN 1 (white)    -- 11
IN 1 (black)    -- 10
IN 1 (brown)    --  9
IN 1 (red)      --  8
*/

String angle = "";
int steps = 0;
const int stepsPerRevolution = 2048;
const int rolePerMinute = 15;
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);


void setup() {
    Serial.begin(9600);
    myStepper.setSpeed(rolePerMinute);
}

void loop(){
    if (Serial.available() > 0) {
        angle = Serial.readString();
        steps = angle.toInt()*5.8; // 360/2048
        Serial.print("Winkel: ");
        Serial.println(angle);
        myStepper.step(steps);
        }
}
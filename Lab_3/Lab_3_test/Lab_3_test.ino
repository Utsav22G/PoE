#include <Keyboard.h>

// Include libraries
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

// Defining pins
#define LEFT_SENSOR A0
#define RIGHT_SENSOR A1

// Defining global variables
String input = "";
String speed = "medium";
String status = "stop";

int left_ir = 0;
int right_ir = 0;
const int default_speed = 150;
unsigned long time = 0;
bool flag = false;
int check = 0;

// Creating motor object
Adafruit_MotorShield AFMS = Adafruit_MotorShield();

// getMotor(port#)  -->   look at the motor shield
Adafruit_DCMotor *left_motor = AFMS.getMotor(4);
Adafruit_DCMotor *right_motor = AFMS.getMotor(3);


void setup() {
  analogReference(DEFAULT);

  Serial.begin(115200);   // set Baud rate
  AFMS.begin();   // start powering the motorshield
}

void loop() {
  time = millis();

  left_ir = analogRead(LEFT_SENSOR);
  right_ir = analogRead(RIGHT_SENSOR);

  // conditions to set speed
  left_motor -> setSpeed((left_ir/right_ir)*40);
  right_motor -> setSpeed((right_ir/left_ir)*40);

  if (check < 99) {
    Serial.print(time);
    Serial.print(",");
    Serial.print(left_ir);
    Serial.print(",");
    Serial.print(right_ir);
    Serial.print(",");
    Serial.print((left_ir/right_ir)*40);
    Serial.print(",");
    Serial.print((right_ir/left_ir)*40);
    Serial.print(",");
    Serial.println(flag);

    left_motor -> run(FORWARD);
    right_motor -> run(FORWARD);
  }
  else if (check == 99) {
    flag = true;

    Serial.print(time);
    Serial.print(",");
    Serial.print(left_ir);
    Serial.print(",");
    Serial.print(right_ir);
    Serial.print(",");
    Serial.print((left_ir/right_ir)*40);
    Serial.print(",");
    Serial.print((right_ir/left_ir)*40);
    Serial.print(",");
    Serial.println(flag);

    left_motor -> run(RELEASE);
    right_motor -> run(RELEASE);

  }
  else if (check == 100) {
    Serial.println("Successfully sent data..");
  }

  delay(100);

  check += 1;
}

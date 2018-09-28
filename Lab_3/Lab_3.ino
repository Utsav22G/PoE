// Include libraries
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

// Defining pins
#define LEFT_SENSOR A0
#define RIGHT_SENSOR A1


// Creating motor object
Adafruit_MotorShield AFMS = Adafruit_MotorShield();

// getMotor(port#)  -->   look at the motor shield
Adafruit_DCMotor *left_motor = AFMS.getMotor(4);
Adafruit_DCMotor *right_motor = AFMS.getMotor(3);

void setup() {
  analogReference(DEFAULT);

  Serial.begin(115200);
  AFMS.begin();


}

void loop() {
  int left_ir = analogRead(LEFT_SENSOR);
  int right_ir = analogRead(RIGHT_SENSOR);

  left_motor -> setSpeed((left_ir/right_ir)*500);
  right_motor -> setSpeed((right_ir/left_ir)*500);

  left_motor -> run(FORWARD);
  right_motor -> run(FORWARD);


}

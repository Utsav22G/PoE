#include <Keyboard.h>

// Include libraries
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

// Defining pins
#define LEFT_SENSOR A0
#define RIGHT_SENSOR A1

// Defining variables
String speed = "medium";
String status = "stop";
int left_ir = 0;
int right_ir = 0;
int default_speed = 150;
String input = "";

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
  left_ir = analogRead(LEFT_SENSOR);
  right_ir = analogRead(RIGHT_SENSOR);

  // conditions to check Serial input
  if (Serial.available() > 0) {
    input = Serial.readString();
    if (input.substring(0,-1) == "fast") {
      speed = "fast";
    }
    if (input.substring(0,-1) == "slow") {
      speed = "slow";
    }
    if (input.substring(0,-1) == "medium") {
      speed = "medium";
    }
    if (input.substring(0,-1) == "start") {
      status = "start";
    }
    if (input.substring(0,-1) == "stop") {
      status = "stop";
    }
  }

  // conditions to set speed
  if (speed == "fast") {
    left_motor -> setSpeed((left_ir/right_ir)*120);
    right_motor -> setSpeed((right_ir/left_ir)*120);
  }
  else if (speed == "slow") {
    left_motor -> setSpeed((left_ir/right_ir)*80);
    right_motor -> setSpeed((right_ir/left_ir)*80);
  }
  else if (speed == "medium") {
    left_motor -> setSpeed((left_ir/right_ir)*60);
    right_motor -> setSpeed((right_ir/left_ir)*60);
  }
  else {
    Serial.println("Error occurred while setting speed..");
  }

  // conditions to set status
  if (status == "start") {
    left_motor -> run(FORWARD);
    right_motor -> run(FORWARD);
  }
  else if (status == "stop") {
    left_motor -> run(RELEASE);
    right_motor -> run(RELEASE);
  }
  else {
    Serial.println("Error occurred while setting status..");
  }

  delay(50);
}

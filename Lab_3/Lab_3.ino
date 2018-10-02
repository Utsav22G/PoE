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

  Serial.begin(115200);
  AFMS.begin();

  // Serial.println("Set the speed for robot (fast, medium, slow):");
  // while (Serial.available()==0) {
  //
  //
  // }
  // speed = Serial.readString();

}

void loop() {
  if (Serial.available() > 0) {
    input = Serial.readString();
    // Serial.println(Serial.readString());
    Serial.println(input.substring(0,1));
    if (input.substring(0,1) == "fa") {
      Serial.println(input.substring(0,1));
      speed = "fast";
    }
    if (Serial.readString() == "slow") {
      speed = "slow";
    }
    if (Serial.readString() == "medium") {
      speed = "medium";
    }
    if (Serial.readString() == "start") {
      status = "start";
    }
    if (Serial.readString() == "stop") {
      speed = "stop";
    }
  }

  left_ir = analogRead(LEFT_SENSOR);
  right_ir = analogRead(RIGHT_SENSOR);

  if (speed == "fast") {
    left_motor -> setSpeed((left_ir/right_ir)*255);
    right_motor -> setSpeed((right_ir/left_ir)*255);
  }
  else if (speed == "medium") {
    left_motor -> setSpeed((left_ir/right_ir)*150);
    right_motor -> setSpeed((right_ir/left_ir)*150);
  }
  else if (speed == "slow"){
    left_motor -> setSpeed((left_ir/right_ir)*80);
    right_motor -> setSpeed((right_ir/left_ir)*80);
  }

  // Serial.println("Enter \"start\" to run the robot and \"stop\" to stop it:");

  if (status == "start") {
      left_motor -> run(FORWARD);
      right_motor -> run(FORWARD);
  }
  else if (status == "stop") {
    left_motor -> run(RELEASE);
    right_motor -> run(RELEASE);
  }
}

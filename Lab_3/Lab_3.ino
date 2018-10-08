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
float left_ir = 0;
float right_ir = 0;
float sensitivity = 200.0;
float factor = 20; // default speed = 20
float speedy_left = (pow(left_ir/right_ir, 3) - 1)*sensitivity + factor;
float speedy_right = (pow(right_ir/left_ir, 3) - 1)*sensitivity + factor;
String input = "";

// Creating motor object
Adafruit_MotorShield AFMS = Adafruit_MotorShield();

// getMotor(port#)  -->   look at the motor shield
Adafruit_DCMotor *left_motor = AFMS.getMotor(4);
Adafruit_DCMotor *right_motor = AFMS.getMotor(3);

void run_robo(float left, float right) {
  left_motor -> setSpeed(abs(left));
  right_motor -> setSpeed(abs(right));

  if (left >= 0 && right >= 0) {
    left_motor -> run(FORWARD);
    right_motor -> run(FORWARD);
  }
  else if (left < 0 && right < 0) {
    left_motor -> run(BACKWARD);
    right_motor -> run(BACKWARD);
  }
  else if (left >= 0 && right < 0) {
    left_motor -> run(FORWARD);
    right_motor -> run(BACKWARD);
  }
  else if (left < 0 && right > 0) {
    left_motor -> run(BACKWARD);
    right_motor -> run(FORWARD);
  }
  else {
    Serial.println("Error in F/W & B/W loop, check < 499");
  }
}

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
    sensitivity = 400;
    factor = 40;
    speedy_left = (pow(left_ir/right_ir, 3) - 1)*sensitivity + factor;
    speedy_right = (pow(right_ir/left_ir, 3) - 1)*sensitivity + factor;
  }
  else if (speed == "slow") {
    sensitivity = 200;
    factor = 20;
    speedy_left = (pow(left_ir/right_ir, 3) - 1)*sensitivity + factor;
    speedy_right = (pow(right_ir/left_ir, 3) - 1)*sensitivity + factor;
  }
  else if (speed == "medium") {
    sensitivity = 300;
    factor = 30;
    speedy_left = (pow(left_ir/right_ir, 3) - 1)*sensitivity + factor;
    speedy_right = (pow(right_ir/left_ir, 3) - 1)*sensitivity + factor;
  }
  else {
    Serial.println("Error occurred while setting speed..");
  }

  // conditions to set status
  if (status == "start") {
    run_robo(speedy_left, speedy_right);
  }
  else if (status == "stop") {
    left_motor -> run(RELEASE);
    right_motor -> run(RELEASE);
  }
  else {
    Serial.println("Error occurred while setting status..");
  }

  delay(20);
}

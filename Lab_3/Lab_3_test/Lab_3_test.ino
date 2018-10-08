#include <Keyboard.h>

// Include libraries
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

// Defining pins
#define LEFT_SENSOR A0
#define RIGHT_SENSOR A1

// Defining global variables
float left_ir = 0;
float right_ir = 0;
// default speed = 20
float speedy_left = ((left_ir/right_ir) - 1)*100.0 + 20;
float speedy_right = ((right_ir/left_ir) - 1)*100.0 + 20;
unsigned long time = 0;
bool flag = false;
int check = 0;

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
  time = millis();

  left_ir = analogRead(LEFT_SENSOR);
  right_ir = analogRead(RIGHT_SENSOR);

  // conditions to set speed
  speedy_left = (pow(left_ir/right_ir, 3) - 1)*200.0 + 20;
  speedy_right = (pow(right_ir/left_ir, 3) - 1)*200.0 + 20;

  if (check < 199) {
    Serial.print(time);
    Serial.print(",");
    Serial.print(left_ir);
    Serial.print(",");
    Serial.print(right_ir);
    Serial.print(",");
    Serial.print(speedy_left);
    Serial.print(",");
    Serial.print(speedy_right);
    Serial.print(",");
    Serial.println(flag);
    run_robo(speedy_left, speedy_right);
  }
  else if (check == 199) {
    flag = true;

    Serial.print(time);
    Serial.print(",");
    Serial.print(left_ir);
    Serial.print(",");
    Serial.print(right_ir);
    Serial.print(",");
    Serial.print(speedy_left);
    Serial.print(",");
    Serial.print(speedy_right);
    Serial.print(",");
    Serial.println(flag);

    left_motor -> run(RELEASE);
    right_motor -> run(RELEASE);
  }
  else if (check == 200) {
    Serial.println("Successfully sent data..");
  }

  delay(20);

  check += 1;
}

#include<Servo.h>

//  define sensor pin
#define SENSOR A0

//  define hobby servos
#define PAN 3
#define TILT 9

float sensorValue, inches, cm;    //Must be of type float for pow()

Servo pan_servo;
Servo tilt_servo;

void setup() {
  analogReference(DEFAULT);
  Serial.begin(9600);  
}

void loop() {
  // put your main code here, to run repeatedly:
  int sense = analogRead(SENSOR);
//  Serial.println(sense);

  inches = 4192.936 * pow(sense,-0.935) - 3.937;
  cm = 10650.08 * pow(sensorValue,-0.935) - 10;
  delay(100);
  Serial.print("Inches: ");
  Serial.println(inches);
}

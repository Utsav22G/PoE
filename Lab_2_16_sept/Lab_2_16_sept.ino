#include<Servo.h>

//  define sensor pin
#define SENSOR A0

//  define hobby servos
#define PAN 6
#define TILT 3

float sensorValue, inches, cm;    //Must be of type float for pow()

Servo pan_servo;
Servo tilt_servo;

int pos = 0;

void setup() {
  analogReference(DEFAULT);
  Serial.begin(9600);

  pan_servo.attach(PAN);
  tilt_servo.attach(TILT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sense = analogRead(SENSOR);
//  Serial.println(sense);

  Serial.println(sense);
  delay(100);


// for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
// // in steps of 1 degree
//   pan_servo.write(pos);              // tell servo to go to position in variable 'pos'
//   delay(15);                       // waits 15ms for the servo to reach the position
// }
// for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
//   pan_servo.write(pos);              // tell servo to go to position in variable 'pos'
//   delay(15);                       // waits 15ms for the servo to reach the position
// }
//
// for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
//   // in steps of 1 degree
//   tilt_servo.write(pos);              // tell servo to go to position in variable 'pos'
//   delay(15);                       // waits 15ms for the servo to reach the position
// }
// for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
//   tilt_servo.write(pos);              // tell servo to go to position in variable 'pos'
//   delay(15);                       // waits 15ms for the servo to reach the position
// }

}

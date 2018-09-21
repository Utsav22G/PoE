#include <Servo.h>

//  define sensor pin
#define SENSOR A0

//  define hobby servos
#define PAN 3
#define TILT 6

float sensorValue, inches, cm;    //Must be of type float for pow()

Servo pan_servo;
Servo tilt_servo;

int pan_pos = 0;
int tilt_pos = 0;
int pan_init = 0;
int tilt_init = 0;
int done = 0;
int sense = 0;

void setup() {
  analogReference(DEFAULT);
  Serial.begin(115200);
  pan_servo.attach(PAN);
  tilt_servo.attach(TILT);

  pan_init = 93-25;
  pan_pos = pan_init;
  pan_servo.write(pan_init);

  tilt_init = 93-25;
  tilt_pos = tilt_init;
  tilt_servo.write(tilt_init);
}

void loop() {
  if (pan_pos <= pan_init + 50){
    pan_pos += 1;
    pan_servo.write(pan_pos);
    delay(100);

    for(tilt_pos = tilt_init+1; tilt_pos <= tilt_init +45; tilt_pos += 1){
      tilt_servo.write(tilt_pos);
      delay(100);
      sense = analogRead(SENSOR);
      cm = 118.68 * pow(0.9966, sense);

      Serial.print(cm);
      Serial.print(",");
      Serial.print(pan_pos);
      Serial.print(",");
      Serial.print(tilt_pos);
      Serial.print(",");
      Serial.println(done);
      delay(100);
    }

  }
  else if (done == 0) {
    done = 1;
    Serial.print(cm);
    Serial.print(",");
    Serial.print(pan_pos);
    Serial.print(",");
    Serial.print(tilt_pos);
    Serial.print(",");
    Serial.println(done);
    delay(100);
    pan_servo.write(pan_init);
    Serial.print("END");
  }
  tilt_servo.write(tilt_init);
  delay(500);

}

#include<Servo.h>

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
int sense = 0;
void setup() {
  analogReference(DEFAULT);
  Serial.begin(9600);  
  pan_servo.attach(PAN);
  tilt_servo.attach(TILT);

  pan_init = 93-45;
  pan_pos = pan_init;
  pan_servo.write(pan_init);

  tilt_init = 93-45;
  tilt_pos = tilt_init;
  tilt_servo.write(tilt_init);
}

void loop() {
  if (pan_pos <= pan_init + 75){
    pan_pos += 5;
    pan_servo.write(pan_pos);
    delay(500);

    for(tilt_pos = tilt_init+5; tilt_pos <= tilt_init +75; tilt_pos += 5){
      tilt_servo.write(tilt_pos);
      delay(500);
      sense = analogRead(SENSOR);
      cm = 118.68 * pow(0.9966, sense);
     
      Serial.print(cm);
      Serial.print(",");
      Serial.print(pan_pos);
      Serial.print(",");
      Serial.println(tilt_pos);
      delay(100);
    }

  }
  else{
    pan_servo.write(pan_init);
    Serial.print('END');
  }
  tilt_servo.write(tilt_init);
  delay(500);

}

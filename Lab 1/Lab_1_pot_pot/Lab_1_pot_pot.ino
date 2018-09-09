/*  Uses potentiometer to light the LEDs according to the
 scaled analog output during configVal < 51.  */

const int redLED = 11;
const int yellowLED = 10;
const int greenLED = 9;
const int configPin = 0;  // Potentiometer controlling LED configuration
const int brightPin = 1;  // Potentiometer controlling LED brightness

void brightFunc(int potVal, int led1, int led2, int led3) {
  // Controls the brightness of the LED when (configVal < 51) and (brightVal > 51)
  // Sets LED brightness to brightVal
  if (potVal > 51) {
    analogWrite(led1, potVal);
    analogWrite(led2, potVal);
    analogWrite(led3, potVal);
  }
}

void setup() {
  Serial.begin(9600);
  analogReference(DEFAULT);

  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
}

void loop() {
  int brightVal = analogRead(brightPin);
  brightVal = map(brightVal, 0, 1023, 0, 255);  // Scale analog input to 0-255

  int configVal = analogRead(configPin);
  configVal = map(configVal, 0, 1023, 0, 255);  // Scale analog input to 0-255

  if (configVal < 51) {
    // Turn all LEDs ON
    if (brightVal > 51) {   //  all ON, full brightness
      brightFunc(brightVal, redLED, yellowLED, greenLED);
    }
    else {    //  all ON, brightness depends on potentiometer resistance
      digitalWrite(redLED, HIGH);
      digitalWrite(yellowLED, HIGH);
      digitalWrite(greenLED, HIGH);
    }
  }
  else if (configVal >= 51 && configVal < 102) {
    // Turn all LEDs OFF
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);
  }
  else if (configVal >= 102 && configVal < 153) {
    // Turns red LED On for 100ms, waits for 300ms and turns green LED
    // ON for 50ms
      digitalWrite(redLED, HIGH);
      delay(100);
      digitalWrite(redLED, LOW);
      delay(300);
      digitalWrite(greenLED, HIGH);
      delay(50);
      digitalWrite(greenLED, LOW);
  }
  else if (configVal >= 153 && configVal < 204) {
    // Blinks red, yellow, green LEDs for 500ms each
    digitalWrite(redLED, HIGH);
    delay(500);
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, HIGH);
    delay(500);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, HIGH);
    delay(500);
    digitalWrite(greenLED, LOW);
  }
  else if (configVal >= 204) {
    //  Turns red LED ON, then blinks yellow and green LEDs, then turns red OFF
    // Next turns yellow LED ON, blinks green and red, turns yellow OFF
    // Next tuns green LED ON, blinks red and yellow, turns green OFF
    digitalWrite(redLED, HIGH);
    for (int i = 0; i < 3; i++) {
      digitalWrite(yellowLED, HIGH);
      delay(200);
      digitalWrite(greenLED, HIGH);
      digitalWrite(yellowLED, LOW);
      delay(200);
      digitalWrite(greenLED, LOW);
    }
    digitalWrite(redLED, LOW);

    digitalWrite(yellowLED, HIGH);
    for (int i = 0; i < 3; i++) {
      digitalWrite(greenLED, HIGH);
      delay(200);
      digitalWrite(redLED, HIGH);
      digitalWrite(greenLED, LOW);
      delay(200);
      digitalWrite(redLED, LOW);
    }
    digitalWrite(yellowLED, LOW);

    digitalWrite(greenLED, HIGH);
    for (int i = 0; i < 3; i++) {
      digitalWrite(redLED, HIGH);
      delay(200);
      digitalWrite(yellowLED, HIGH);
      digitalWrite(redLED, LOW);
      delay(200);
      digitalWrite(redLED, LOW);
    }
    digitalWrite(greenLED, LOW);
  }
  else {
    Serial.println("Error in configVal..");
  }
}

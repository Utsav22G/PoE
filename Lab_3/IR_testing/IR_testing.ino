#define IR_SENSOR A0

void setup() {
  Serial.begin(115200);
  analogReference(DEFAULT);
}

void loop() {
  int sensorValue = analogRead(IR_SENSOR);
  Serial.println(sensorValue);
  delay(500);
}

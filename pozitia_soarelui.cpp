#include <Servo.h>

Servo servoAzimuth;
Servo servoInclination;
const int pinAzimuth = 10;
const int pinInclination = 9;

int currentAzimuth = 90;
int currentInclination = 45;

void setup() {
  Serial.begin(9600);
  servoAzimuth.attach(pinAzimuth);
  servoInclination.attach(pinInclination);
  servoAzimuth.write(currentAzimuth);
  servoInclination.write(currentInclination);
  Serial.println("Servo tracking system ready.");
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim();

    float azimuth = 0;
    float inclination = 0;

    int commaIndex = input.indexOf(',');

    if (commaIndex > 0) {
      azimuth = input.substring(0, commaIndex).toFloat();
      inclination = input.substring(commaIndex + 1).toFloat();

      int targetAzimuth = map((int)azimuth, 0, 360, 0, 180);
      targetAzimuth = constrain(targetAzimuth, 0, 180);

      int targetInclination = constrain((int)inclination, 0, 90);

      if (targetAzimuth != currentAzimuth) {
        int step = (targetAzimuth > currentAzimuth) ? 1 : -1;
        for (int pos = currentAzimuth; pos != targetAzimuth; pos += step) {
          servoAzimuth.write(pos);
          delay(15);
        }
        currentAzimuth = targetAzimuth;
      }

      if (targetInclination != currentInclination) {
        int step = (targetInclination > currentInclination) ? 1 : -1;
        for (int pos = currentInclination; pos != targetInclination; pos += step) {
          servoInclination.write(pos);
          delay(15);
        }
        currentInclination = targetInclination;
      }

      Serial.print("Azimuth: ");
      Serial.print(azimuth);
      Serial.print(" -> Servo: ");
      Serial.println(targetAzimuth);

      Serial.print("Inclination: ");
      Serial.print(inclination);
      Serial.print(" -> Servo: ");
      Serial.println(targetInclination);
      Serial.println("-------------------------------");
      Serial.println("OK");
    }
  }
}

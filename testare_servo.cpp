#include <Servo.h>

Servo servo90;
Servo servo180;
const int pinServo90 = 10;
const int pinServo180 = 9;

const int pinSenzorCurent = A0;
float VCC = 5.0;
float sensibilitateSenzor = 0.100;

const int intarziereMiscareServo = 100;

void setup() {
  Serial.begin(9600);

  servo90.attach(pinServo90);
  servo180.attach(pinServo180);

  Serial.println("Initializare sistem fotovoltaic...");
  Serial.print("Senzor curent conectat la pinul: A");
  Serial.println(pinSenzorCurent - A0);
  Serial.print("Sensibilitate senzor setata pentru (mV/A): ");
  Serial.println(sensibilitateSenzor * 1000);
  Serial.println("------------------------------------");
}

void loop() {
  Serial.println("Miscare servo 90 grade (0 -> 90)...");
  for (int pos = 0; pos <= 90; pos++) {
    servo90.write(pos);
    delay(intarziereMiscareServo);
  }

  Serial.println("Miscare servo 180 grade (0 -> 180)...");
  for (int pos = 0; pos <= 180; pos++) {
    servo180.write(pos);
    delay(intarziereMiscareServo);
  }

  delay(500);

  Serial.println("Miscare servo 90 grade inapoi (90 -> 0)...");
  for (int pos = 90; pos >= 0; pos--) {
    servo90.write(pos);
    delay(intarziereMiscareServo);
  }

  Serial.println("Miscare servo 180 grade inapoi (180 -> 0)...");
  for (int pos = 180; pos >= 0; pos--) {
    servo180.write(pos);
    delay(intarziereMiscareServo);
  }

  delay(500);

  int valoareADC = analogRead(pinSenzorCurent);
  float tensiuneSenzor = (valoareADC / 1024.0) * VCC;
  float curentPanou = (tensiuneSenzor - (VCC / 2.0)) / sensibilitateSenzor;

  Serial.println("--- Masurare Curent Panou Solar ---");
  Serial.print("Valoare ADC senzor: ");
  Serial.println(valoareADC);
  Serial.print("Tensiune citita de la senzor: ");
  Serial.print(tensiuneSenzor, 3);
  Serial.println(" V");
  Serial.print("Curent generat de panou: ");
  Serial.print(curentPanou, 2);
  Serial.println(" A");
  Serial.println("------------------------------------");

  delay(2000);
}

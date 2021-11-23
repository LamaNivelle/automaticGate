
// créer une fonction pour ouvrir la porte
// allumer la led verte avant le code du moteur
// 

#include <Servo.h>

int Green_LED = 1;
int Red_LED = 2;

void setup() {
  // create the code to run once
  pinMode(1, OUTPUT);
}

void loop() {
  // create the code to run repeatedly
  digitalWrite(1, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(1, LOW);    // turn the LED off (make the voltage LOW)
  delay(1000);                       // wait for a second
}

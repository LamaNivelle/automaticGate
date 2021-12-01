#include <LiquidCrystal_I2C.h> //including all the librairies we need
#include <Wire.h>
#include <Password.h>
#include <Keypad.h>
#include <Servo.h>
#include "pitches.h"    //including all the headers we need
#include "digicode.h"
#define trigPin 13    //define the pins
#define echoPin 12

//**********************************************************Hector

int password=0;   //initialize and declare the variable i'll need in my functions
int admin=0511;
int accepted=0;
int confirmDigit=1;

byte currentLength = 0 ;
const byte ROWS = 4;    //initialize the keypad size
const byte COLS = 3; 
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};    //initialize the pins used by the keypad
byte colPins[COLS] = {5, 4, 3}; 
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);   //define the customKeypad function

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

Password password = Password("0000");

//**********************************************************Agathe

int RGB_LED = 1;
int Yellow_LED = 2;

void night(){
  
}

void light(int night) {
  if (night == 1){
    digitalWrite(1, HIGH);
    delay(15);
  }
}

//**********************************************************Clem
/*
  int pos; // call the actual position of the gate
  int servoPin=9;
  
  int servo_open(int pos) { //OPENING FUNCTION
    Servo servo; // creation of the object the servo
    bool actual_angle = false; // send to serie support the position of the servo
    Servo.attach(servoPin); // attach the servo to the pin

    for(pos ; pos <= 90; pos++) {
      Servo.write(pos); // ask to servo to move to the new position
      delay(50); // delay of 0,05 seconds between each new position
      if (pos=90){
        // STOPPER LA ROTATION
      }
    }
  }

  int servo_close(int pos) { //CLOSING FUNCTION
    Servo.attach(servoPin); // attach the servo to the pin
    for(pos ; pos >= 90; pos--) {
      Servo.write(pos); // ask to servo to move to the new position
      delay(50); // delay of 0,05 seconds between each new position
      if (pos=0){
        // STOPPER LA ROTATION
      }
    }
  }
*/

//**********************************************************Antoine

// creation of the function that will permit to detect movement below the gate
  int safety() { 
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  
  if (distance >= 200 || distance <= 0)
    {
      //continue the closing protocol
     
    }
  else {
      // write a function to go to the opening function
    } 
  delay(500);
}
// must repeat the function as long as the gate is not fully closed. 
int protocolSafety(){
  
}


// must add a buzzer to warn of the closing procedure=part of the safety procedure


// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};


void setup() {
  Serial.begin(9600);   //setup the serial monitor
  
  //Hector
  lcd.init();    //initialize the lcd screen
  lcd.backlight();
  
  //Agathe
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);

  //Antoine
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }

}

void loop() {
  initialization(password);   //call function initialization
}

#include <Servo.h>
#include <LiquidCrystal.h>
#include <Keypad.h>
#include "pitches.h"
#include "digicode.h"
#include "Arduino.h"
#define trigPin 13
#define echoPin 12

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const byte ROWS = 4; 
const byte COLS = 3; 

int password[Password_Length]={0,0,0,0};
int admin[Password_Length]={0,5,1,1};
int accepted=0;


int confirmDigit=1;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3}; 
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
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

//**********************************************************Antoine

// creation of the function tht will permit to detect movement below the gate
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
  Serial.begin(9600);
  
  //Hector
  lcd.begin(16,2);
  
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
  initialization(password);
}

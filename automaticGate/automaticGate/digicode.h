#ifndef DIGICODE_H
#define DIGICODE_H
#include "Arduino.h"
#define Password_Length 4

extern int password[Password_Length];
extern int admin[Password_Length];
extern int accepted;
extern LiquidCrystal lcd;
extern Keypad customKeypad;

int initialization(int password[Password_Length]);
int confirmPassword(int password[Password_Length]);
int changePassword();

#endif

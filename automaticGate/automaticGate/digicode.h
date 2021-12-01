#ifndef DIGICODE_H
#define DIGICODE_H
#include "Arduino.h"

extern int admin;
extern int accepted;
extern LiquidCrystal_I2C lcd;
extern Keypad customKeypad;
extern Password password;

int initialization();
int confirmPassword();
int changePassword();

#endif

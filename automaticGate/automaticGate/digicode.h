#ifndef DIGICODE_H
#define DIGICODE_H
#include <LiquidCrystal.h>
#include <Keypad.h>
#include "Arduino.h"
#define Password_Length 4

int initialization(int password[Password_Length]);
int confirmPassword(int password[Password_Length]);
int changePassword();

#endif

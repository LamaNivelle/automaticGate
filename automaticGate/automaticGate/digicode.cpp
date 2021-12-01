#include <Password.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include "digicode.h"
#include "Arduino.h"

// Define initialization function
int initialization(){
  lcd.clear();
  confirmPassword();   
}

// Define confirmPassword function
int confirmPassword(){ //confirm the password enter by the user
  int accepted=0, errorCounter=0;
  char input = customKeypad.getKey();

  
  switch (input){
    case '#': //reset password
    password.reset();
    //currentLength = 0;
    lcd.clear();
    lcd.print("reset pswd");
    delay(3000);
    lcd.clear();
    break;
    case '*': //evaluate password
    while(accepted!=1){
      if(errorCounter==3){    //if too many errors have been made
        for(int i=0;i<3;i++){     //make the user wait for 3 seconds
          lcd.clear();
          lcd.setCursor(2,0);
          lcd.print("Too many errors, wait for ");
          lcd.print(3-i);
          lcd.print(" seconds");
          delay(1000);
        }
    }
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print("Enter password:");   //ask the user to enter the password
    if(password.evaluate()){
      lcd.clear();
      lcd.setCursor(2,0);
      lcd.print("Correct pswd");
      delay(3000);
      lcd.clear();
      accepted=1;
    }
    else {
      lcd.clear();
      lcd.setCursor(2,0);
      lcd.print("Wrong pswd");
      delay(3000);
      lcd.clear();
      errorCounter++;
    }
  }
  }
}

int changePassword(){ //user can change the password
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Choose a new 4-digits password");
  lcd.setCursor(5,1);
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print("To confirm password : tap 0");
    lcd.setCursor(2,1); 
    lcd.print("else, tap any other number");
  }

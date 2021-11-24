
#include "digicode.h"
#include "Arduino.h"


int initialization(int password[Password_Length]){
  lcd.clear();
  confirmPassword(password);   
}

int confirmPassword(int password[Password_Length]){ //confirm the password enter by the user
  int verifyPassword[4], i, accepted=0, errorCounter=0;
  
  while(accepted!=1){
    if(errorCounter==3){
      for(i=0;i<3;i++){
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
    lcd.print("Enter password:");
    lcd.setCursor(5,1);
    for(i=0;i<4;i++){
      verifyPassword[i]=customKeypad.getKey();
      lcd.print("*");
    }
    if(verifyPassword[1]==password[1] && verifyPassword[2]==password[2] && verifyPassword[3]==password[3] && verifyPassword[4]==password[4])
      accepted=1;
      else if(verifyPassword[1]==admin[1] && verifyPassword[2]==admin[2] && verifyPassword[3]==admin[3] && verifyPassword[4]==admin[4])
              changePassword();
              else errorCounter++;
  }
}

int changePassword(){ //user can change the password
  int confirmDigit=1;
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Choose a new 4-digits password");
  lcd.setCursor(5,1);
  while(confirmDigit==1){
    int i;
    for(i=0;i<4;i++){
      password[i]=customKeypad.getKey();
    }
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print("To confirm password : tap 0");
    lcd.setCursor(2,1); 
    lcd.print("else, tap any other number");
    confirmDigit=customKeypad.getKey();
  }
}

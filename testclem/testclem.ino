
#include <Servo.h>

int pos = 0; // position of the gate
int servoPin = 3;

int servo_open(int pos) { //OPENING FUNCTION
  Servo servo; // creation of the object the servo

  int increment = 1 ; // increment between each position
  bool actual_angle = false; // send to serie support the position of the servo

  servo.attach(servoPin); // attach the servo to the pin

  for(pos ; pos <= 90; pos += increment) {
    servo.write(pos); // ask to servo to move to the new position
    delay(50); // delay of 0,05 seconds between each new position
    if (pos=90){
      // STOPPER LA ROTATION
    }
  }
}


int servo_close(int pos) { //CLOSING FUNCTION
  Servo servo; // creation of the object the servo

  int increment = 1 ; // increment between each position
  bool actual_angle = false; // send to serie support the position of the servo

  servo.attach(servoPin); // attach the servo to the pin

  for(pos ; pos >= 90; pos -= increment) {
    servo.write(pos); // ask to servo to move to the new position
    delay(50); // delay of 0,05 seconds between each new position
    if (pos=0){
      // STOPPER LA ROTATION
    }
  }
}

void setup() {
  Serial.begin(9600);
  
  //CLEM
  int pos = 0; // position of the gate
  int servoPin = 3;
  pinMode(servoPin, OUTPUT);

  
  }

void loop() {
  servo_open;
  servo_close;
}

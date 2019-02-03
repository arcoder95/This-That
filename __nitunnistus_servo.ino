#include <Servo.h>

Servo myServo;

const int redPin = 4;
byte COM = 0;
int refAngle= 90;

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  myServo.attach(9);
  delay(2000);
  Serial.write(0xAA);
  Serial.write(0x37);
  delay(1000);
  Serial.write(0xAA);
  Serial.write(0x21);
  delay(1000);
  myServo.write(refAngle);
  digitalWrite(redPin, HIGH);
  delay(1000);
  digitalWrite(redPin, LOW);
  delay(1000);
  digitalWrite(redPin, HIGH);
  

}

void loop() {
  while(Serial.available()){
    COM = Serial.read();
    switch(COM){
      case 0x11:
      refAngle-=45;
      if(refAngle < 0){
        myServo.write(0);
        refAngle = 0;
      }
      else{
        myServo.write(refAngle);
      }
      digitalWrite(redPin, LOW);
      delay(1000);
      digitalWrite(redPin, HIGH);
      break;
      case 0x12:
      refAngle+=45;
      if (refAngle > 180){
        myServo.write(180);
        refAngle = 180;
      }
      else{
        myServo.write(refAngle);
      }
      digitalWrite(redPin, LOW);
      delay(500);
      digitalWrite(redPin, HIGH);
      break;
      case 0x13:
      myServo.write(90);
      digitalWrite(redPin, LOW);
      delay(500);
      digitalWrite(redPin, HIGH);
      refAngle = 90;
      break;
      case 0x14:
      break;
      case 0x15:
      if(refAngle < 90){
        myServo.write(0);
        delay(1500);
        myServo.write(180);
        delay(1500);
        myServo.write(0);
        refAngle = 0;  
      }
      else{
        myServo.write(180);
        delay(1500);
        myServo.write(0);
        delay(1500);
        myServo.write(180);
        refAngle = 180; 
      }
      digitalWrite(redPin, LOW);
      delay(500);
      digitalWrite(redPin, HIGH);
      break;
      
    }

      
    }
    
   
    
    

}

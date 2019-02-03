   # include <Servo.h>

   Servo myServo;
   
   // This code receives data via bluetoothmodule, and opens/ closes venetians blind by using servo motor.
   
    int const  Servopin = 9;
    int state = 0;
    
    void setup() {
      
      myServo.attach(Servopin);
      Serial.begin(9600); 
    }
    void loop() {
      if(Serial.available() > 0){ 
        state = Serial.read();
     }
     if (state == '1') {
      myServo.write(90);
      state = 0;
     }
     else if (state == '3') {
      myServo.write(180);
     
      state = 0;
     } 
     else if (state == '4'){
      myServo.write(0);
      
      state = 0;
     }
    }

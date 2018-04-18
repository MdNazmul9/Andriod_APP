#include <Servo.h>
Servo myservo;


void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);

}

void loop() {
  // put your main code here, to run repeatedly:
  myservo.writeMicroseconds(800);
  delay(1000);
   myservo.writeMicroseconds(1500);
   delay(1000);
   myservo.writeMicroseconds(2000);
   delay(2000);

}

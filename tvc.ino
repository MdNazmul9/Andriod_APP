#include <Servo.h>

#include<SoftwareSerial.h>
SoftwareSerial BT(10,11); //TX, RX respectively
String readvoice;
Servo myservo;

void setup()
{
  BT.begin(9600);
  Serial.begin(9600);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT); //water pump
  pinMode(8,OUTPUT); //clean motor
  
  
  myservo.attach(9);


}

//................................................

void loop()
{
    while(BT.available()){
    delay(10);
    char c=BT.read();
    readvoice += c;
    }
    
      if(readvoice.length() > 0) {
       Serial.println(readvoice);
       
     
       
       if(readvoice == "forward")
       {
         digitalWrite(3,HIGH);
         digitalWrite(4,HIGH);
         digitalWrite(5,LOW);
         digitalWrite(6,LOW);
         digitalWrite(8,HIGH);
         delay(100);
         myservo.writeMicroseconds(800);
         delay(1000);
         
       }
       
       //111111111111111111111111111111111111111111111
       
       else  if(readvoice == "reverse")
       {
         digitalWrite(3,LOW);
         digitalWrite(4,LOW);
         digitalWrite(5,HIGH);
         digitalWrite(6,HIGH);
         //digitalWrite(8,HIGH);
         delay(100);
       }
       
     //2222222222222222222222222222222222222222222222
     
     else  if(readvoice == "right")
       {
         digitalWrite(3,HIGH);
         digitalWrite(4,LOW);
         digitalWrite(5,LOW);
         digitalWrite(6,LOW);
        // digitalWrite(8,HIGH);
         delay(100);
       }
       
     //333333333333333333333333333333333333333333333
     
      else  if(readvoice == "left")
       {
         digitalWrite(3,LOW);
         digitalWrite(4,HIGH);
         digitalWrite(5,LOW);
         digitalWrite(6,LOW);
         //digitalWrite(8,HIGH);
         delay(100);
       }

        else  if(readvoice == "water")
       {
        
         digitalWrite(7,HIGH);
         digitalWrite(8,HIGH);
        
         delay(100);
       }


       else  if(readvoice == "off")
       {
        
         digitalWrite(7,LOW);
         digitalWrite(8,HIGH);
        
         delay(100);
       }

        else  if(readvoice == "of")
       {
        
         digitalWrite(7,LOW);
         digitalWrite(8,HIGH);
        
         delay(100);
       }
       
      //44444444444444444444444444444444444444444444
      
      
       else  if(readvoice == "stop")
       {
         digitalWrite(3,LOW);
         digitalWrite(4,LOW);
         digitalWrite(5,LOW);
         digitalWrite(6,LOW);
         digitalWrite(7,LOW);
         digitalWrite(8,LOW);
         delay(100);
         myservo.writeMicroseconds(2000);
         delay(2000);

       }
       
       //--------------------------------------------
       
       readvoice=""; //Reset the variable
     
    }
}


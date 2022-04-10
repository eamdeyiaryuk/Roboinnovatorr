#include "DtUltra.h"

DtUltra Ultra;

int count=0;
int Limit = 3;
boolean buttonState;
boolean lastState;
boolean state = HIGH;
boolean Reading1;
boolean Check1 = 1;

int DistanceUltra;
int solenoid = 2;
int Trigpin = 42;
int Echopin = 43;

void setup() {
  Serial.begin(9600);
  pinMode(solenoid,OUTPUT);
  pinMode(Limit,INPUT_PULLUP);
  Ultra.setPin(Trigpin,Echopin);
  // put your setup code here, to run once:

}

void loop() {
  DistanceUltra = Ultra.Distance(Trigpin,Echopin);
  Reading1 = digitalRead(Limit);
  while(Reading1==LOW)
   {     Serial.println(DistanceUltra);
    if(DistanceUltra < 15){
    digitalWrite(solenoid,HIGH);
    delay(1000);
    digitalWrite(solenoid,LOW);
    delay(1000);    }
    break;
   }
    lastState = Reading1;
}
  
  

  // put your main code here, to run repeatedly:

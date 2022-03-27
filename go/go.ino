#include "DtUltra.h"

int trigPin = 24;
int echoPin = 22;
int distance;
long duration;
DtUltra Ultra;

int motor1pin1 = 35; // Front
int motor1pin2 = 37; 
int motor2pin1 = 39; // back
int motor2pin2 = 41; 

int motor3pin1 = 34; // Right
int motor3pin2 = 36; 
int motor4pin1 = 38; // Left
int motor4pin2 = 40; 




void setup() {
  Serial.begin(9600);
  Ultra.setPin(trigPin,echoPin);
  openmotor();

  // put your setup code here, to run once:

}

void loop() {
  distance = Ultra.Distance(trigPin,echoPin);
  Serial.println(distance);
  motorgo();
  if(distance < 25)
  {
    motorLeft();
  }

  // put your main code here, to run repeatedly:

}

void openmotor() {
  // put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(motor3pin1, OUTPUT);
  pinMode(motor3pin2, OUTPUT);
  pinMode(motor4pin1, OUTPUT);
  pinMode(motor4pin2, OUTPUT);
  pinMode(2, OUTPUT);  //ENB pin
  pinMode(3, OUTPUT);  //ENA pin 
  pinMode(4, OUTPUT);  //ENA pin
  pinMode(5, OUTPUT);  //ENB pin
}
void motortest()
{
  analogWrite(2, 30); //ENA pin
  analogWrite(3, 30); //ENB pin
  analogWrite(4, 30); //ENA pin
  analogWrite(5, 30); //ENB pin
  digitalWrite(motor1pin1, LOW);   //ตามเข็ม
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin1, LOW);   //ตามเข็ม
  digitalWrite(motor2pin2, HIGH);
  digitalWrite(motor3pin1, LOW);   //ตามเข็ม
  digitalWrite(motor3pin2, HIGH);
  digitalWrite(motor4pin1, LOW);   //ตามเข็ม
  digitalWrite(motor4pin2, HIGH);

  
}
void motorgo() {
  // put your main code here, to run repeatedly:   

  //Controlling speed (0 = off and 255 = max speed):
  analogWrite(2, 50); //ENA pin
  analogWrite(3, 50); //ENB pin
  analogWrite(4, 50); //ENA pin
  analogWrite(5, 50); //ENB pin

  //Controlling spin direction of motors:
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW); 
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);

  digitalWrite(motor3pin1, LOW); //ตาม
  digitalWrite(motor3pin2, HIGH); 
  digitalWrite(motor4pin1, HIGH);//ทวน
  digitalWrite(motor4pin2, LOW);
  
}
void motorRight() {
  // put your main code here, to run repeatedly:   

  //Controlling speed (0 = off and 255 = max speed):
  analogWrite(2, 50); //ENA pin
  analogWrite(3, 50); //ENB pin
  analogWrite(4, 50); //ENA pin
  analogWrite(5, 50); //ENB pin

  //Controlling spin direction of motors:

  digitalWrite(motor1pin1, HIGH); //ตาม
  digitalWrite(motor1pin2, LOW); 
  digitalWrite(motor2pin1, LOW);//ทวน
  digitalWrite(motor2pin2, HIGH);
  
  digitalWrite(motor3pin1, LOW); 
  digitalWrite(motor3pin2, LOW); 
  digitalWrite(motor4pin1, LOW);
  digitalWrite(motor4pin2, LOW);
}
void motorLeft(){
  analogWrite(2, 50); //ENA pin
  analogWrite(3, 50); //ENB pin
  analogWrite(4, 50); //ENA pin
  analogWrite(5, 50); //ENB pin
  digitalWrite(motor1pin1, LOW); //ตาม
  digitalWrite(motor1pin2, HIGH); 
  digitalWrite(motor2pin1, HIGH);//ทวน
  digitalWrite(motor2pin2, LOW);
  
  digitalWrite(motor3pin1, LOW); //ตาม
  digitalWrite(motor3pin2, LOW); 
  digitalWrite(motor4pin1, LOW);//ทวน
  digitalWrite(motor4pin2, LOW);
}

void motorstop(){
  digitalWrite(motor1pin1, HIGH);   //ตามเข็ม
  digitalWrite(motor1pin2, HIGH);  //ตามเข็ม
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, HIGH);
  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, HIGH);
  digitalWrite(motor4pin1, HIGH);
  digitalWrite(motor4pin2, HIGH);  
}

#include "DtUltra.h"

int trigPin = 24;
int echoPin = 22;
int distance;
long duration;
DtUltra Ultra;

void setup() {
  Serial.begin(9600);
  Ultra.setPin(trigPin,echoPin);
  // put your setup code here, to run once:

}

void loop() {
  distance = Ultra.Distance(trigPin,echoPin);
  Serial.println(distance);

}

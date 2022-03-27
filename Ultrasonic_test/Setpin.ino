#define echoPin 2 //pin Echo
#define trigPin 3 //pin Trig
unsigned long timer1=0;
unsigned long timer2=0;
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
void UltraSetup(){
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600); 
}
void SetTrigpin(){
  if(millis() - timer1 >= 0.002) // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  {
    digitalWrite(trigPin, LOW);
    timer1 = millis();
  }
  if(millis() - timer2 >= 0.01)
  {
    digitalWrite(trigPin, HIGH);
    timer2 = millis();
  }
  digitalWrite(trigPin, LOW);
}
void DistUltra(){
  SetTrigpin();
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 /2; // Speed of sound wave divided by 2 (go and back)
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
//   if(distance < 10)
// {
//  Serial.println("K-----U-----Y");
// }
}

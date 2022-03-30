int Limit = 2;
int count=0;
boolean buttonState;
boolean lastState;
boolean state = HIGH;
boolean reading1;

void setup() {  
  Serial.begin(9600);
  pinMode(Limit,INPUT_PULLUP);  
}

void loop() {
 reading1 = digitalRead(Limit);  
  if(reading1==LOW&&lastState==HIGH)  
   {     delay(10);    
          if(digitalRead(Limit)==LOW){ 
          count++;
        Serial.println(count);}
    }  
//  if(state==LOW)  
//  { 
//    count++;   
//    Serial.println(count); 
//  }   
    lastState = reading1;  
}

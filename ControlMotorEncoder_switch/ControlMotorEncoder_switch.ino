volatile long int  encoder_pos1;
int n = 500; // pulse ของระยะ n1 ถึง n2 ค่อยๆจูนค่า
#define ENA 5
#define IN2 27 //4
#define IN1 26 //3
#define ENCA 2
#define ENCB 3
#define Switch1 28
#define Switch2 29

void setup() {

  pinMode(ENCA, INPUT);    //1EncoderMotor2 *A-pin2 *B-pin3
  pinMode(ENCB, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), encoder1, RISING);

  ///////////////////////////////////////////////

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(Switch1, INPUT_PULLUP);
  pinMode(Switch2, INPUT_PULLUP);
  Serial.begin (9600);
  Serial.println("start");
}

void loop() {
  int Enaspeed = 50;
  int dir=0;
  
  setMotor(dir, Enaspeed, ENA, IN1, IN2);

   if(digitalRead(Switch1) == HIGH){
    dir=-1; setMotor(dir, Enaspeed, ENA, IN1, IN2);
    while(encoder_pos1<=n) Serial.println(encoder_pos1); dir=0; setMotor(dir, Enaspeed, ENA, IN1, IN2); encoder_pos1=0;
    }
   else if(digitalRead(Switch2)==HIGH){
    dir=1; setMotor(dir, Enaspeed, ENA, IN1, IN2);
    while(encoder_pos1>=-n) Serial.println(encoder_pos1); dir=0; setMotor(dir, Enaspeed, ENA, IN1, IN2); encoder_pos1=0;

    }
    else{
      dir=0; setMotor(dir, Enaspeed, ENA, IN1, IN2);
   }

}


void setMotor(int dir, int enaspeed, int ena, int in1, int in2) {
  analogWrite(ena, enaspeed);
  if (dir == 1) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  }
  else if (dir == -1) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  }
  else {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
  }
}

void encoder1() {
  if (digitalRead(3) == HIGH) {
    encoder_pos1++;
  } else {
    encoder_pos1--;
  }
  
}

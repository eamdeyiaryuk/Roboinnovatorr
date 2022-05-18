
volatile long int  encoder_pos1;

volatile long  pos = 0;


#define ENA 4
#define IN2 23
#define IN1 22
int dir = 1 ;

void setup() {
  
  pinMode(2, INPUT);    //1EncoderMotor2 *A-pin2 *B-pin3
  pinMode(3, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), encoder1, RISING);

  ///////////////////////////////////////////////


  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  Serial.begin (9600);
  Serial.println("start");
}

void loop() {
  int Enaspeed = 50;
  setMotor(dir, Enaspeed, ENA, IN1, IN2);

  Serial.print("En1 -- Value: "); Serial.println(encoder_pos1);
  if(encoder_pos1 >= 500){
    dir = 0;
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

int MotorL1 = 34;
int MotorL2 = 36;
void setup() {
  Serial.begin(9600);
  pinMode(MotorL1, OUTPUT);
  pinMode(MotorL2, OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(MotorL1,HIGH);
  digitalWrite(MotorL2,LOW);
  // put your main code here, to run repeatedly:

}

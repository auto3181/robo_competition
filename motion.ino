#define M1_DIR 4
#define M1_PWM 5
#define M2_DIR 7
#define M2_PWM 6

void Init() {
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}
void Forward(int pwm) {
  digitalWrite(M1_DIR, 0);
  digitalWrite(M2_DIR, 0);
  analogWrite(M1_PWM, pwm);
  analogWrite(M2_PWM, pwm);
}

void Backward(int pwm){
  digitalWrite(M1_DIR, 1);
  digitalWrite(M2_DIR, 1);
  analogWrite(M1_PWM, pwm);
  analogWrite(M2_PWM, pwm);
}

void Stop(){
  digitalWrite(M1_DIR, 0);
  digitalWrite(M2_DIR, 0);
  analogWrite(M1_PWM, 0);
  analogWrite(M2_PWM, 0);
}

void Right(int pwm){
  digitalWrite(M1_DIR, 0);
  digitalWrite(M2_DIR, 1);
  analogWrite(M1_PWM, pwm);
  analogWrite(M2_PWM, pwm);
}

void Left(int pwm){
  digitalWrite(M1_DIR, 1);
  digitalWrite(M2_DIR, 0);
  analogWrite(M1_PWM, pwm);
  analogWrite(M2_PWM, pwm);
}
void setup() {
  Init();
}


void loop() {

}

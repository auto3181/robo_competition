#define M1_DIR 4
#define M1_PWM 5
#define M2_DIR 7
#define M2_PWM 6

void Init() {
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600);
}
void Backward(int pwm = 250) {
  digitalWrite(M1_DIR, 0);
  digitalWrite(M2_DIR, 0);
  analogWrite(M1_PWM, pwm);
  analogWrite(M2_PWM, pwm);
}

void Forward(int pwm = 150) {
  digitalWrite(M1_DIR, 1);
  digitalWrite(M2_DIR, 1);
  analogWrite(M1_PWM, pwm);
  analogWrite(M2_PWM, pwm);
}

void Stop() {
  digitalWrite(M1_DIR, 0);
  digitalWrite(M2_DIR, 0);
  analogWrite(M1_PWM, 0);
  analogWrite(M2_PWM, 0);
}

void Right(int pwm = 120) {
  //120
  digitalWrite(M1_DIR, 0);
  digitalWrite(M2_DIR, 1);
  analogWrite(M1_PWM, pwm);
  analogWrite(M2_PWM, pwm);
  delay(100);
  Stop();
  delay(15);
}

void Left(int pwm = 120) {
  digitalWrite(M1_DIR, 1);
  digitalWrite(M2_DIR, 0);
  analogWrite(M1_PWM, pwm);
  analogWrite(M2_PWM, pwm);
  delay(100);
  Stop();
  delay(15);
}
void Reverse() {
  Backward(100);
  delay(200);
  for (int i = 0 ; i < 15; i++) {
    Right();
  }
}

void TurnRight() {
  for (int i = 0 ; i < 9; i++) {
    Right();
  }
}

void TurnLeft() {
  for (int i = 0 ; i < 9; i++) {
    Left();
  }
}
void setup() {
  Init();
}


void loop() {
  Forward(255);
  delay(2000);
  Forward(150);
  delay(2000);
  Forward(80);
  delay(2000);
}

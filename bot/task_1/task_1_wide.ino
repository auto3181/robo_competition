#define M1_DIR 4
#define M1_PWM 5
#define M2_DIR 7
#define M2_PWM 6
#define LS A1
#define RS A0

#define BLACK_LEVEL_LOW 700
#define BLACK_LEVEL_HIGH 950
#define WHITE_LEVEL_LOW 500
#define WHITE_LEVEL_HIGH 580

void Init() {
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600);
}
void Backward(int pwm1 = 250, int pwm2 = 250) {
  digitalWrite(M1_DIR, 0);
  digitalWrite(M2_DIR, 0);
  analogWrite(M1_PWM, pwm1);
  analogWrite(M2_PWM, pwm2);
}

void Forward(int pwm1 = 250, int pwm2 = 250) {
  digitalWrite(M1_DIR, 1);
  digitalWrite(M2_DIR, 1);
  analogWrite(M1_PWM, pwm1);
  analogWrite(M2_PWM, pwm2);
}
void Stop() {
  digitalWrite(M1_DIR, 0);
  digitalWrite(M2_DIR, 0);
  analogWrite(M1_PWM, 0);
  analogWrite(M2_PWM, 0);
}

void Right(int pwm1 = 250, int pwm2 = 250) {
  //120
  digitalWrite(M1_DIR, 0);
  digitalWrite(M2_DIR, 1);
  analogWrite(M1_PWM, pwm1);
  analogWrite(M2_PWM, pwm2);
}

void Left(int pwm1 = 250, int pwm2 = 250) {
  digitalWrite(M1_DIR, 1);
  digitalWrite(M2_DIR, 0);
  analogWrite(M1_PWM, pwm1);
  analogWrite(M2_PWM, pwm2);
}
void setup() {
  Init();
}

bool isBlack( int pin) {
  if ((analogRead(pin) > BLACK_LEVEL_LOW) && (analogRead(pin) < BLACK_LEVEL_HIGH))
    return true;
  return false;
}




void loop() {
  bool L = isBlack(LS);
  bool R = isBlack(RS);
  
  if (L and R){ //all black
    Forward(120, 120);
  }
  else if(!L and R){ //L - white, R - black
    Right(250, 250);
  }
  else if(L and !R){
    Left(250, 250);
  }  
  //white 513-580
  //black 800-950
  Serial.print(L);
  Serial.print(", ");
  Serial.println(R);
}

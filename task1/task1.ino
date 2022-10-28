#define M1_DIR 4
#define M1_PWM 5
#define M2_DIR 7
#define M2_PWM 6
#define LS A0
#define RS A1
#define BUZ 8
#define BLACK_LEVEL_LOW 700
#define BLACK_LEVEL_HIGH 950
#define WHITE_LEVEL_LOW 500
#define WHITE_LEVEL_HIGH 580

int t1 = 1330;
int t2 = 8030 + 800;
int t3 = 2560;
int t4 = 1100;
int t5 = 2010;
int x_time = 0;
int error = 500;
int turn = 0; // 1 - влево, 2 - вправо
int timer = 0;
int lap1 = 14900, lap2 = lap2 * 2, lap3 = lap1 * 3;
int lap = 1;
void Init() {
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
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
  timer = millis() - x_time;
  Serial.println(timer);
  if ((timer > lap1 - 20 and timer < lap1 + 20 ) or (timer > lap2 - 20 and timer < lap2 + 20 ) or (timer > lap3 - 20 and timer < lap3 + 20 )) {
    x_time = timer;
    lap++;
    tone(BUZ, 1000, 300);
  }
  if (L and R) { //all black
    if (lap == 1) {
      if ((timer > t1 + t2 + error and timer < t1 + t2 + t3 - error)) { //or (timer>t1_2 and timer < t2_2) or (timer > t1_3 and timer < t2_3)){
        Forward(255, 255);
      }

      else if ((timer >= t1 + t2 + t3 + t4 + error and timer <= t1 + t2 + t3 + t4 + t5 - error)) { //or (timer >= 27000 and timer <= 28000) or (timer >= 42000 and timer <= 43000)){
        Forward(255, 255);
      }
      else if ((timer > t1 + t2 + t3 - error and timer <= t1 + t2 + t3) or
               (timer > t1 + t2 + t3 + t4 + t5 - error and timer <= t1 + t2 + t3 + t4 + t5)) {
        Forward(100, 100);
        tone(BUZ, 1000, 300);
      }
      else {
        Forward(185, 185);
      }
    }
    else if (lap == 2 or lap == 3){
      if ((timer > t2 + error and timer < t2 + t3 - error)) { //or (timer>t1_2 and timer < t2_2) or (timer > t1_3 and timer < t2_3)){
        Forward(255, 255);
      }

      else if ((timer >= t2 + t3 + t4 + error and timer <= t2 + t3 + t4 + t5 - error)) { //or (timer >= 27000 and timer <= 28000) or (timer >= 42000 and timer <= 43000)){
        Forward(255, 255);
      }
      else if ((timer > t2 + t3 - error and timer <= t2 + t3) or
               (timer > t2 + t3 + t4 + t5 - error and timer <= t2 + t3 + t4 + t5)) {
        Forward(100, 100);
        tone(BUZ, 1000, 300);
      }
      else {
        Forward(185, 185);
      }
    }
  }
  else if (!L and R) { //L - white, R - black
    Right(100, 255);
    turn = 2;
  }
  else if (L and !R) {
    Left(255, 100);
    turn = 1;
  }
  else if (!L and !R) {
    if (turn == 1) {
      Left(255, 120);
      //tone(BUZ, 1000, 300);
    }
    else if (turn == 2) {
      Right(120, 255);
      //tone(BUZ, 1000, 300);
    }
  }
  //white 513-580
  //black 800-950
  Serial.print(L);
  Serial.print(", ");
  Serial.println(R);
}

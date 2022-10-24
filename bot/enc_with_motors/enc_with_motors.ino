/*
 * 25 ticks to 90 deg //120 speed
 * 48 ticks to wheel turn
 * 60 ticks to 180 deg // 120 speed
 */
#include <Servo.h>
Servo grab;
Servo up;
#define M1_DIR 4
#define M1_PWM 5
#define M2_DIR 7
#define M2_PWM 6

volatile long Position1 = 0;
volatile long Position2 = 0;
long oldPosition1 = 0;
long oldPosition2 = 0;
void Encoder1Rotate() {
    Position1++;
}
void Encoder2Rotate() {
    Position2++;
}


void setup() {
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  attachInterrupt(0, Encoder1Rotate, CHANGE);//change 48, rising 28
  attachInterrupt(1, Encoder2Rotate, CHANGE);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600);
  grab.attach(9);
  up.attach(10);
  up.write(20);
  grab.write(150);
  delay(500);
}

void Up(){
grab.write(25);
delay(500);
up.write(120);
delay(500);
}
void Down(){
 up.write(20);
delay(1000);
grab.write(150);
delay(500);
}

void Forward(int pwm1 = 250, int pwm2 = 250) {
  digitalWrite(M1_DIR, 1);
  digitalWrite(M2_DIR, 1);
  analogWrite(M1_PWM, pwm1);
  analogWrite(M2_PWM, pwm2);
}
void Backward(int pwm1 = 250, int pwm2 = 250) {
  digitalWrite(M1_DIR, 0);
  digitalWrite(M2_DIR, 0);
  analogWrite(M1_PWM, pwm1);
  analogWrite(M2_PWM, pwm2);
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
void loop() {
  
  while (Position1 <= 48 and Position2 <= 48){
    Forward(200, 200);
  }
  Backward(220,220);
  delay(30);
  Forward(0,0);
  delay(100);
  Up();
  delay(500);
  Position1 = 0;
  Position2 = 0;
  while(Position1 <= 60 and Position2 <= 60){
    Left(120,120);
  }
  Right(220, 220);
  delay(30);
  Forward(0,0);
  delay(1000);
  Position1 = 0;
  Position2 = 0;
}

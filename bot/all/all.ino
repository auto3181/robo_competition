#include <Servo.h>
Servo grab;
Servo up;
#define TRIG 9 
#define ECHO 10
#define ENC_1 3
#define ENC_2 2
#define IC_1 8
#define IC_2 9
#define M1_DIR 4
#define M1_PWM 5
#define M2_DIR 7
#define M2_PWM 6

void Init(){
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  grab.attach(9);
  up.attach(10);
  up.write(20);
  grab.write(150);
  delay(500);
}
int Check_distance(){
  int duration, distance;
  digitalWrite(TRIG, LOW); 
  delayMicroseconds(2); //10
  digitalWrite(TRIG, HIGH);
  // Подождем 10 μs 
  delayMicroseconds(1); 
  digitalWrite(TRIG, LOW); 
  duration = pulseIn(ECHO, HIGH); 
  distance = duration / 58;
  return distance;
}

void setup() {
  Init();
}

void loop() {
  Serial.println(Check_distance());
}

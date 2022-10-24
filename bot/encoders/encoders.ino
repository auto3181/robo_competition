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
  Serial.begin (9600);
}

void loop() {
  if (oldPosition1 != Position1)
  {
    Serial.print("Pos 1: ");
    Serial.println(Position1);
    oldPosition1 = Position1;
  }
  if (oldPosition2 != Position2)
  {
    Serial.print("Pos 2: ");
    Serial.println(Position2);
    oldPosition2 = Position2;
  }
}

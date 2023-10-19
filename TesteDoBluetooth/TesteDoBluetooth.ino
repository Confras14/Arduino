char z;
int buzzer = 8;
int buzzer2 = 7;
void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(buzzer2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  z = Serial.read();

  Serial.println(z);

  tone(buzzer, 500, 300);
  delay(1000);
  tone(buzzer2, 500, 300);

  delay(1000);
}
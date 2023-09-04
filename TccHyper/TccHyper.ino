//Declaração de variaveis
int buzzer = 8;

void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop() {
  tone(buzzer, 500, 75);
  delay(300);
}

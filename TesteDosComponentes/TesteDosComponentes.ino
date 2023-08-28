#define ledR 11
#define ledB 10
#define ledG 9
#define buzzer 7

void ledRGB(int R, int G, int B) {
  analogWrite(ledR, R);
  analogWrite(ledR, R);
  analogWrite(ledB, B);
}

void buzzerAptUn(int t) {
  digitalWrite(buzzer, 0);
  delay(t);
  digitalWrite(buzzer, 1);
}

void buzzerAptMl(int vz) {
  for(int i = 0; i < vz; i++) {
    digitalWrite(buzzer, 0);
    delay(250);
    digitalWrite(buzzer, 1);
    delay(250);
  }
}

void buzzerOn_Off() {
  digitalWrite(buzzer, !(digitalRead(buzzer)));
}

void setup() {
  pinMode(ledR, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(buzzer, 1);

  char z;
  z = Serial.read();

  Serial.println(z);

  // if(z == "V") {ledRGB(50, 255, 50);}
  
  // if(z == "A") {ledRGB(50, 50, 255);}

  delay(1000);
}

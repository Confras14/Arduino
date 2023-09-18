#define led1R 11
#define led1G 10
#define led1B 9

#define led2R 6
#define led2G 5
#define led2B 3

#define buzzerAlto 8
#define buzzerBaixo 7

void setup() {
  pinMode(led1R, OUTPUT);
  pinMode(led1G, OUTPUT);
  pinMode(led1B, OUTPUT);

  pinMode(led2R, OUTPUT);
  pinMode(led2G, OUTPUT);
  pinMode(led2B, OUTPUT);
  
  pinMode(buzzerAlto, OUTPUT);
  pinMode(buzzerBaixo, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  analogWrite(led1R, 255);
  analogWrite(led1G, 255);
  analogWrite(led1B, 255);

  
  analogWrite(led2R, 255);
  analogWrite(led2G, 255);
  analogWrite(led2B, 255);

  tone(buzzerBaixo, 200, 200);

  delay(1000);
}

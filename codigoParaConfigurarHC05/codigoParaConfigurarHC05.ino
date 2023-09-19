#include <SoftwareSerial.h>

SoftwareSerial bt(2, 3);

void setup() {
  Serial.begin(38400);
  Serial.println("Digite os comandos AT: ");
  bt.begin(38400);

  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
}

void loop() {
  if (bt.available()) {
    int inByte = bt.read();
    Serial.write((char)inByte);
  }

  if (Serial.available()) {
    int inByte = Serial.read();
    bt.write((char)inByte);
  }
}

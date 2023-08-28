void setup() {
  Serial.begin(9600);
}

void loop() {
  char z;
  z = Serial.read();

  Serial.println(z);

  delay(500);
}

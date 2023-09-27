char z;

void setup() {
  Serial.begin(9600);
}

void loop() {
  z = Serial.read();

  Serial.println(z);

  delay(500);
}
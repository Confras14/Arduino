#define ledR 11
#define ledB 10
#define ledG 9
#define buzzer 7

char valApp = 0;

void ledRGB(int R, int G, int B) {
  analogWrite(ledR, R);
  analogWrite(ledG, G);
  analogWrite(ledB, B);
}

void buzzerAptMlAtv() {
  digitalWrite(buzzer, 0);
  delay(250);
  digitalWrite(buzzer, 1);
  delay(250);
}

void buzzerAptMlPass() {
  tone(buzzer, 500, 250);
  delay(500);
}

void setup() {
  pinMode(ledR, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
  digitalWrite(buzzer, 1);
}


void loop() {
  /*
    A = branco
    a = desligado
    R = Vermelho
    G = Verde
    B = Azul
    Z = buzzer ON
    z = Buzzer OFF
  */

  valApp = Serial.read();
  Serial.println(valApp);

  if(valApp == 'A') {ledRGB(255, 255, 255);}

  else if(valApp == 'a') {ledRGB(0, 0, 0);}

  else if (valApp == 'R') {ledRGB(255, 0, 0);}

  else if (valApp == 'G') {ledRGB(0, 255, 0);}

  else if (valApp == 'B') {ledRGB(0, 0, 255);}
//
//  else if (valApp == 'Z') {digitalWrite(buzzer, 0);}
//  else if (valApp == 'z') {digitalWrite(buzzer, 1);}

//  else if (valApp == 'X') {
//    int i = 1;
//    while(i != 0) {
//      buzzerAptMlAtv();
//      valApp = Serial.read();
//      Serial.println(valApp);
//      if(valApp == 'x'){ i = 0; }
//    }
//  }


  if (valApp == 'Z') {tone(buzzer, 500, );}
  if (valApp == 'z') {tone(buzzer, 0, 0);}

  else if (valApp == 'X') {
    int i = 1;
    while(i != 0) {
      buzzerAptMlPass();
      valApp = Serial.read();
      Serial.println(valApp);
      if(valApp == 'x'){ i = 0; }
    }
  }
 
  delay(100);
}

#define buzzerPassB 6
#define buzzerPassA 5

int qualBuzzer = 0;
char valApp = 0;

//Função para Ligar o led rgb
//void ledRGB(int R, int G, int B) {
//  analogWrite(ledR, R);
//  analogWrite(ledG, G);
//  analogWrite(ledB, B);
//}

//Função para apitar o buzzer passivo
void buzzerPass(int buzzer) {
  tone(buzzer, 500, 250);
  delay(750);
}

void setup() {
  pinMode(buzzerPassB, OUTPUT);
  pinMode(buzzerPassA, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  /*
    on buzzer = 'O'
    on buzzer = 'o'
    buzzer alto = 'A'
    buzzer baixo = 'a'
  */

  valApp = Serial.read();
  Serial.println(valApp);

  if(valApp == 'A'){qualBuzzer = 1;
    Serial.println(qualBuzzer);}
  if(valApp == 'a'){qualBuzzer = 2;
    Serial.println(qualBuzzer);}

  if(valApp == 'O') {
    if(qualBuzzer == 1){
      //Ligar buzzer baixo
      int lbb = 0;
      while(lbb != 1){
        buzzerPass(buzzerPassB);
        if(valApp == 'o'){lbb = 1;}

        if(digitalRead(buzzerPassA) == 1) {tone(buzzerPassA, 1, 1);}
        
        valApp = Serial.read();
        Serial.println(valApp);
      }
    }else if(qualBuzzer == 2){
      //Ligar buzzer alto
      int lba = 0;
      while(lba != 1){
        buzzerPass(buzzerPassA);
        if(valApp == 'o'){lba = 1;}

        if(digitalRead(buzzerPassB) == 1) {tone(buzzerPassB, 1, 1);}
        
        valApp = Serial.read();
        Serial.println(valApp);
      }
    }
  }
  
  delay(100);
}

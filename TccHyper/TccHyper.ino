#define buzzerPassB 7
#define buzzerPassA 8

#define ledR1 11
#define ledG1 10
#define ledB1 9

#define ledR2 6
#define ledG2 5
#define ledB2 3

int qualBuzzer = 0;
int cntLigF = 0;
int cntLigP = 0;
char valApp = 0;

//Função para Ligar o led rgb 1
void ledRGB(int R, int G, int B) {
  analogWrite(ledR1, R);
  analogWrite(ledG1, G);
  analogWrite(ledB1, B);
}

//Função para Ligar o led rgb 2
void ledRGB(int R, int G, int B) {
  analogWrite(ledR2, R);
  analogWrite(ledG2, G);
  analogWrite(ledB2, B);
}

//Função para apitar o buzzer passivo
void buzzerPass(int buzzer) {
  tone(buzzer, 500, 250);
  delay(750);
}

void setup() {
  pinMode(buzzerPassB, OUTPUT);
  pinMode(buzzerPassA, OUTPUT);
  
  pinMode(ledR1, OUTPUT);
  pinMode(ledG1, OUTPUT);
  pinMode(ledB1, OUTPUT);
  pinMode(ledR2, OUTPUT);
  pinMode(ledG2, OUTPUT);
  pinMode(ledB2, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  /*
    buzzer alto = 'A'
    buzzer baixo = 'a'

    Foco on = 'O'
    Foco off = 'o'

    Pomodoro = 'P'
    Pausa Curta = 'C'
    Pausa Longa = 'L'
  */

  if(cntLigF != 1) {
    valApp = Serial.read();
    Serial.println(valApp);
  }

  if(valApp == 'A'){qualBuzzer = 1;
    Serial.println(qualBuzzer);}
  if(valApp == 'a'){qualBuzzer = 2;
    Serial.println(qualBuzzer);}

  if(valApp == 'O' || cntLigF == 1) {
    if(qualBuzzer == 0 || qualBuzzer != 1 || qualBuzzer != 2) {
      Serial.println("Escolha um buzzer antes!");
    }
    else if(qualBuzzer == 1){
      //Ligar buzzer baixo
      int lbb = 0;
      while(lbb != 1){
        buzzerPass(buzzerPassB);
        
        valApp = Serial.read();
        Serial.println(valApp);

        if(valApp == 'a'){
          qualBuzzer = 2;
          Serial.println(qualBuzzer);
        }

        if(digitalRead(buzzerPassA) == 1) {tone(buzzerPassA, 1, 1);}
        if(valApp == 'o') {lbb = 1;}
        
        if(qualBuzzer == 1) {
          cntLigF = 1;
          lbb = 1;
        }
      }
    }
    else if(qualBuzzer == 2 || cntLigF == 1){
      //Ligar buzzer alto
      int lba = 0;
      while(lba != 1){
        buzzerPass(buzzerPassA);

        valApp = Serial.read();
        Serial.println(valApp);

        if(valApp == 'A'){
          qualBuzzer = 1;
          Serial.println(qualBuzzer);
        }

        if(digitalRead(buzzerPassB) == 1) {tone(buzzerPassB, 1, 1);}
        if(valApp == 'o') {lba = 1;}

        if(qualBuzzer == 1) {
          cntLigF = 1;
          lba = 1;
        }
      }
    }
  }

  else if(cntLigF != 1 && valApp == 'P'){
    //Pomodoro
  }
  else if(cntLigF != 1 && valApp == 'C'){
    //Pausa Curta
  }
  else if(cntLigF != 1 && valApp == 'L'){
    //Pausa Longa
  }
  
  delay(100);
}

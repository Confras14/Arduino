#define buzzerPassB 6
#define buzzerPassA 5

#define ledR 11
#define ledG 10
#define ledB 9

int qualBuzzer = 0;
int cntLigF = 0;
int cntLigP = 0;
char valApp = 0;

//Função para Ligar o led rgb
void ledRGB(int R, int G, int B) {
  analogWrite(ledR, R);
  analogWrite(ledG, G);
  analogWrite(ledB, B);
}

//Função para apitar o buzzer passivo
void buzzerPass(int buzzer) {
  tone(buzzer, 500, 250);
  delay(750);
}

void setup() {
  pinMode(buzzerPassB, OUTPUT);
  pinMode(buzzerPassA, OUTPUT);
  
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);

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

  if(ctnLig != 1) {
    valApp = Serial.read();
    Serial.println(valApp);
  }

  if(valApp == 'A'){qualBuzzer = 1;
    Serial.println(qualBuzzer);}
  if(valApp == 'a'){qualBuzzer = 2;
    Serial.println(qualBuzzer);}

  if(valApp == 'O') {
    if(qualBuzzer == 0 || qualBuzzer != 1 || qualBuzzer != 2) {
      console.log("Escolha um buzzer antes!");
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
    else if(qualBuzzer == 2){
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

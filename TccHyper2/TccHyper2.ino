//declarando os buzzers
#define buzzerB 7
#define buzzerA 8

//declarando o led de modo
#define ledR1 11
#define ledG1 10
#define ledB1 9

//declarando o led de status
#define ledR2 6
#define ledG2 5
#define ledB2 3

//Variavel para saber qual buzzer está sendo usado
char qualBuzzer = "0";
//Variavel para receber infos do bluetooth
char valApp = 0;

//Varaiaveis para ajudar no funcionamento
int cntLig = true;
int OnFoco = false;

//Função para Ligar o led rgb 1
void ledRGB1(int R, int G, int B) {
  analogWrite(ledR1, R);
  analogWrite(ledG1, G);
  analogWrite(ledB1, B);
}

//Função para Ligar o led rgb 2
void ledRGB2(int R, int G, int B) {
  analogWrite(ledR2, R);
  analogWrite(ledG2, G);
  analogWrite(ledB2, B);
}

//Função para apitar o buzzer
void buzzerApito(int buzzer) {
  tone(buzzer, 500, 150);
  delay(600);
}

void setup() {
  //declarando todoas as portas de saida
  pinMode(buzzerB, OUTPUT);
  pinMode(buzzerA, OUTPUT);
  
  pinMode(ledR1, OUTPUT);
  pinMode(ledG1, OUTPUT);
  pinMode(ledB1, OUTPUT);

  pinMode(ledR2, OUTPUT);
  pinMode(ledG2, OUTPUT);
  pinMode(ledB2, OUTPUT);
  
  //Iniciando o monitor serial
  Serial.begin(9600);
}

void loop() {
  //Receber e imprimir o valor vindo do bluetooth
  if(cntLig) {
    valApp = Serial.read();
    Serial.println(valApp);
  }
  
  cntLig = true;
  //Qual Buzzer

  if(valApp == 'A') {
    qualBuzzer = 'A';
    Serial.println("Buzer Alto");
  } else if(valApp == 'a') {
    qualBuzzer = 'a';
    Serial.println("Buzer Baixo");
  }
  
  //Fim Qual Buzzer
  //------------------------------------------------------------------------------------------------------------------
  //Modo Foco

  if(valApp == 'O') {
    OnFoco = true;
    if(qualBuzzer = 'A') {
      while(OnFoco) {
        buzzerApito(buzzerA);

        valApp = Serial.read();
        Serial.println(valApp);
        if(valApp == 'o') {
          OnFoco = false;
        }
      }
    }
    
    else if(qualBuzzer = 'a') {
      while(OnFoco) {
        buzzerApito(buzzerB);

        valApp = Serial.read();
        Serial.println(valApp);
        if(valApp == 'o') {
          OnFoco = false;
        }
      }
    }
  }
  
  //Fim Modo Foco
  //------------------------------------------------------------------------------------------------------------------
  //Modo Pomodoro


  
  //Fim Modo Pomodoro
  delay(500);
}

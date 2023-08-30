//Declarando os componentes de saida
#define ledR 11
#define ledB 10
#define ledG 9
#define buzzerP 8
#define buzzerA 7

//Criando a varivel para receber infos do serial
char valApp = 0;

//Função para Ligar o led rgb
void ledRGB(int R, int G, int B) {
  analogWrite(ledR, R);
  analogWrite(ledG, G);
  analogWrite(ledB, B);
}

//Função para apitar o buzzer ativo
void buzzerAptMlAtv() {
  digitalWrite(buzzerA, 0);
  delay(250);
  digitalWrite(buzzerA, 1);
  delay(250);
}

//Função para ligar e desligar o buzzer passivo
void buzzerOnPass() {
    tone(buzzerP, 500, 35);
    delay(25);
}

//Função para apitar o buzzer passivo
void buzzerAptMlPass() {
  tone(buzzerP, 500, 250);
  delay(500);
}

void setup() {
  //Declarando como saida as portas que usam os componentes
  pinMode(ledR, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(buzzerA, OUTPUT);
  pinMode(buzzerP, OUTPUT);

  //Ativando o serial
  Serial.begin(9600);
  //Desligando o buzzer ativo
  digitalWrite(buzzerA, 1);
}


void loop() {
  /*
    O que cada informação que vem do serial seria
    
    A = branco
    a = desligado
    R = Vermelho
    G = Verde
    B = Azul
    
    Z = buzzer Ativo ON
    z = Buzzer Ativo OFF
    X = buzzer Ativo apito ON
    x = buzzer Ativo apito OFF

    V = buzzer Passivo ON
    v = Buzzer Passivo OFF
    C = buzzer Passivo apito ON
    c = buzzer Passivo apito OFF
  */

  //lendo e imprimindo as informações do serial
  valApp = Serial.read();
  Serial.println(valApp);

  //Controle do led
  if(valApp == 'A') {ledRGB(255, 255, 255);} //Liga o led em branco
  else if(valApp == 'a') {ledRGB(0, 0, 0);} // Desliga o led
  else if (valApp == 'R') {ledRGB(255, 0, 0);} //Liga o led em Vermelho
  else if (valApp == 'G') {ledRGB(0, 255, 0);} //Liga o led em Verde
  else if (valApp == 'B') {ledRGB(0, 0, 255);} //Liga o led em Azul

  //Buzzer Ativo
  //Ligando e desligando ele
  else if (valApp == 'Z') {digitalWrite(buzzerA, 0);}
  else if (valApp == 'z' || valApp == 'x') {digitalWrite(buzzerA, 1);}

  //Fazendo ele apitar
  else if (valApp == 'X') {
    int i = 1;
    while(i != 0) {
      buzzerAptMlAtv();
      valApp = Serial.read();
      Serial.println(valApp);
      if(valApp == 'x' || valApp == 'z'){ i = 0; }
    }
  }

  //Buzzer Passivo
  //Ligando e desligando ele
  else if (valApp == 'V') {
    int y = 1;
    while(y != 0){
      buzzerOnPass();
      valApp = Serial.read();
      Serial.println(valApp);
      if(valApp == 'v' || valApp == 'c'){ y = 0; }
    }
  }

  //Fazendo ele apitar
  else if (valApp == 'C') {
    int i = 1;
    while(i != 0) {
      buzzerAptMlPass();
      valApp = Serial.read();
      Serial.println(valApp);
      if(valApp == 'c' || valApp == 'v'){ i = 0; }
    }
  }
 
  delay(100);
}

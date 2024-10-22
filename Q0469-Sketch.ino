/*
     Q0469
     AUTOR:   BrincandoComIdeias
     LINK:    https://www.youtube.com/brincandocomideias ;
     CURSOS:  https://cursodearduino.net/ ; https://cursoderobotica.net/
     COMPRE:  https://www.arducore.com.br/
     SKETCH:  Sensor de Chama
     DATA:    30/05/2019
*/

// INCLUSÃO DE BIBLIOTECAS


// DEFINIÇÕES DE PINOS
#define pinSensor 12
#define pinBuzzer 2

#define FOGO LOW

// DEFINIÇÕES


#define DEBUG
// INSTANCIANDO OBJETOS


// DECLARAÇÃO DE FUNÇÕES
void controleAlarme(byte funcao, unsigned long tempo = 500);

// DECLARAÇÃO DE VARIÁVEIS


void setup() {
  Serial.begin(9600);

  pinMode(pinSensor, INPUT);
  pinMode(pinBuzzer, OUTPUT);

#ifdef DEBUG
  Serial.println("Setup concluído!");
#endif
}

void loop() {

  if ( digitalRead(pinSensor) == FOGO ) {
    controleAlarme(HIGH);
    
  } else {
    controleAlarme(LOW);
  }

}

// IMPLEMENTO DE FUNÇÕES

// FUNÇÃO PARA EFEITO DE ALARME
void controleAlarme(byte funcao, unsigned long tempo = 500) {
  static unsigned long controleTempo = millis();
  static bool flag = true;
  if (funcao == true) {
    if (flag == true ) {
      if (millis() < (controleTempo + tempo) ) {
        digitalWrite(pinBuzzer, HIGH);
      } else {
        flag = false;
      }
    } else if ( millis() < (controleTempo + tempo + tempo) ) {
      digitalWrite(pinBuzzer, LOW);
    } else if (  millis() > (controleTempo + tempo + tempo) ) {
      flag = true;
      controleTempo = millis();
    }
  } else {
    digitalWrite(pinBuzzer, LOW);
  }
}

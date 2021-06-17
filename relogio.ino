
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2); // número de colunas e linhas
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

String stringAuxiliar; // texto escrito no display
byte hora=0, minuto=0, seg=0, horaAlarme=0, minAlarme=10;

void loop() {
  
  if(hora==horaAlarme && minuto==minAlarme){
   tone(13, 200, 100); 
  }
  
  //Caso um número seja digitado na porta serial, 
  //ele será atribuído a hora
  if (Serial.available()){
   hora = Serial.parseInt(); 
   Serial.println(hora); 
  } 
  
  lcd.setCursor(5, 0);
  stringAuxiliar = String(hora);
  if (hora<10){
  	stringAuxiliar = String("0"+stringAuxiliar);  
  }
  lcd.print(stringAuxiliar);
  
  lcd.print(":");
  stringAuxiliar = String(minuto);
  if (minuto<10){
  	stringAuxiliar = String("0"+stringAuxiliar);  
  }
  lcd.print(stringAuxiliar);
  delay(1000); // aguarda 1 segundos
  
  //Algoritmo para contar o tempo:
  seg++;
  if (seg>59){
  	minuto++;
    seg=0;
  }
  if (minuto>59){
  	hora++;
    minuto=0;
  }
  if(hora>23){
    hora=0;
  }
  
  
}
 
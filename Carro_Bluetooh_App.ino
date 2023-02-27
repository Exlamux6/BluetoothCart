/* Arduino Control Car V1 
 ESP32   L293D(Puente H)        
 34          10
 35          15
 33           2
 32           7
 5V         1,9,16
 GND        4, 5, 12, 13
 
 El motor 1 se conecta a los pines 3 y 6 del Puente H
 El motor 2 se conecta a los pines 11 y 14 del Puente H
 
 La fuente de alimentacion de los Motores se conecta a tierra y
 el positivo al pin 8 del puennte H. 

 */
#include "BluetoothSerial.h"
#if !defined (CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth no esta hablitado
#endif

BluetoothSerial Bt;

int izqA = 26; 
int izqB = 33; 
int derA = 25; 
int derB = 32;
int estado = 'c';         // inicia detenido

void setup()  { 

  pinMode(izqA, OUTPUT);
  pinMode(izqB, OUTPUT);
  pinMode(derA, OUTPUT);
  pinMode(derB, OUTPUT);
  
   Serial.begin(9600);
  Bt.begin("Exlamux66");
  Serial.println("El dispositivo está iniciado, ahora te puedes conectar");
} 

void loop()  { 
      Bt.available();
      char mensaje = Bt.read();
      switch (mensaje){
        case 'A':
          frente();
          break;
        case 'D':
          reversa();
          break;
        case 'B':
          izquierda();
          break;
        case 'C':
          derecha();
          break;
        case 'E':
          parar();
          break;
      }
   delay(20);
}

void parar(){
  digitalWrite(derB, LOW);     
  digitalWrite(izqB, LOW); 
  digitalWrite(derA, LOW);    
  digitalWrite(izqA, LOW); 
}
void reversa(){
  digitalWrite(derA, LOW);    
  digitalWrite(izqA, LOW);
  digitalWrite(derB, HIGH);  
  digitalWrite(izqB, HIGH);    
}
void derecha(){
  digitalWrite(derB, LOW);     
  digitalWrite(izqB, LOW); 
  digitalWrite(derA, LOW);  
  digitalWrite(izqA, HIGH);
}
void izquierda(){
  digitalWrite(derB, LOW);     
  digitalWrite(izqB, LOW);
  digitalWrite(izqA, LOW);
  digitalWrite(derA, HIGH);   
}
void frente(){
  digitalWrite(derB, LOW);     
  digitalWrite(izqB, LOW); 
  digitalWrite(derA, HIGH);  
  digitalWrite(izqA, HIGH);    
}

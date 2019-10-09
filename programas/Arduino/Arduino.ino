#include <SoftwareSerial.h>

SoftwareSerial miBT(10,11);
int Data; //los datos enviados al bluetooth
int ledpin=13; // LED en pin 13
void setup(){
    Serial.begin(9600);
    Serial.println("Listo");
    miBT.begin(38400);
    pinMode(ledpin,OUTPUT);
}

void loop(){
  if (miBT.available())
  {  Data=miBT.read();
  if(Data=='1')
       {   
          digitalWrite(ledpin,1); //Que se encienda el LED
       }
         if (Data=='2')
       {
          digitalWrite(ledpin,0); //Que se apague el LED

       }
    }
  Serial.write(miBT.read()); //lee BT y envia a Arduino

  if(Serial.available())
  miBT.write(Serial.read()); //lee Arduino y envia a BT
}

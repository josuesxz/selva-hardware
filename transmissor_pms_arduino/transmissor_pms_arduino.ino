#include <SoftwareSerial.h>
#include "PMS.h"

SoftwareSerial pmsSerial(2, 3); //rx - 2, tx - 3 // conecta o tx do pms no rx do microcontrolador 
//SoftwareSerial(rxPin, txPin), I used D8 for RX and D7 for TX (esp8266) and connected TX on PMS5003 to D8

PMS pms(pmsSerial);
PMS::DATA data;

void setup(){
  Serial.begin(9600);   
  pmsSerial.begin(9600);  
}

void loop(){
  //Serial.println(pms.read(data));
  //delay(100);
  if (pms.read(data)){
    Serial.print("PM 1.0 (ug/m3): ");
    Serial.println(data.PM_AE_UG_1_0);

    Serial.print("PM 2.5 (ug/m3): ");
    Serial.println(data.PM_AE_UG_2_5);

    Serial.print("PM 10.0 (ug/m3): ");
    Serial.println(data.PM_AE_UG_10_0);

    Serial.println();
  }
}
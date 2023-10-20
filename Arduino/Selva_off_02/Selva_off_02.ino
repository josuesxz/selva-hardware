//**********INCLUSÃO DE BIBLIOTECAS**********
#include "dht.h"
#include <Wire.h>
#include <RTClib.h>
#include <SPI.h>
#include <SD.h>
#include <SoftwareSerial.h>
#include "PMS.h"
//#include "Adafruit_PM25AQI.h"

// **********DEFINE A COMUNICAÇÃO COM O SENSOR DE MATERIAL PARTICULADO**********

SoftwareSerial particulado(16, 17); 

// ********** DECLARAÇÃO DE VARIÁVEIS**********
RTC_DS1307 RTC; // MÓDULO RTC
char diaDaSemana[7][12] = {"Domingo","Segunda","Terça", "Quarta","Quinta", "Sexta","Sabado"};// DIAS DA SEMANA
float pm25;
int temperatura;
String dataComplete;
String today;
String agora;
const int pinoDHT11 = 4; //PINO ANALÓGICO UTILIZADO PELO DHT11
dht DHT; //VARIÁVEL DO TIPO DHT
String fileName;
//#define DHT11PIN 7
//#define SD_CS 6

PMS pms(particulado);
PMS::DATA data;

//dht11 DHT11;


void  setup(){

  Serial.begin(9600);// INICIA A COMUNICAÇÃO DO ARDUINO COM O COMPUTADOR
  Serial1.begin(9600);// INICIA A COMUNICAÇÃO DO ARDUIN COM SENSOR DE MATERIAL PARTICULADO
  RTC.begin();// INICIA A COMUNICAÇÃO COM O MÓDULO RTC
  delay(100);
}

void loop() {

  DHT.read11(pinoDHT11);
  Serial1.println();

  if (pms.read(data))//VERIFICA SE O SENSOR DE MATERIAL PARTICULADO COLETOU DADOS 
  {
   pm25 = (data.PM_AE_UG_2_5); // GUARDA OS DADOS COLETADOS EM UMA VARIÁVEL 
  }

  

  Wire.begin();
    
  if (! RTC.isrunning()) {  //VERIFICA SE O MÓDULO RTC ESTÁ FUNCIONANDO
    Serial.println("RTC is NOT running!");
    //RTC.adjust(DateTime(__DATE__, __TIME__));// AJUSTA DE FORMA AUTOMÁTICA A DATA E HORA 
    
  }

  //RTC.adjust(DateTime(2023, 10, 18, 13, 52, 0));
  DateTime now = RTC.now(); 
  today = String(now.day(), DEC) + "/" + String(now.month(), DEC) + "/" + String(now.year(), DEC);
  agora = String(now.hour(), DEC) + ":" + String(now.minute(), DEC) + ":" + String(now.second(), DEC);
  temperatura = DHT.temperature;
  
  dataComplete = "Última leitura: "+ today + ", " + "Hora: " + agora + ", PM2.5: "+ String(pm25) + "," + " Temperatura atual: "+ String(temperatura);

  Serial.println(dataComplete);


  delay(1000);

}
/***************************************************************************
Leitura de temperatura e pressão no local ok! agora preciso enviar para o banco de dados
Para mostrar na serial podemos pegar do banco de dados e gg
 ***************************************************************************/

//INCLUSÃO DE BIBLIOTECAS
#include <Wire.h> //Comunicação I2C
#include <SPI.h> //Comunicação SPI
#include <Adafruit_BMP280.h> //Temperatura e pressão
#include "RTClib.h" //Clock
#include <SoftwareSerial.h>
#include "Plantower_PMS7003.h"

#define baud 9600

//Definição do Serial Software
char output[256];
Plantower_PMS7003 pms7003 = Plantower_PMS7003();
SoftwareSerial pmsSerial(17, 16); // rx - 19, tx - 18
//SoftwareSerial(rxPin, txPin), I used D8 for RX and D7 for TX (esp8266) and connected TX on PMS5003 to D8

//   -------------DECLARAÇÕES GLOBAIS GLOBAIS-------------------
Adafruit_BMP280 bmp; // use I2C interface
Adafruit_Sensor *bmp_temp = bmp.getTemperatureSensor();
Adafruit_Sensor *bmp_pressure = bmp.getPressureSensor();
sensors_event_t temp_event, pressure_event;

RTC_DS3231 rtc; //OBJETO DO TIPO RTC_DS3231
char daysOfTheWeek[7][12] = {"Domingo", "Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sábado"};

// ------------------- FIM ---------------------------------

void setup() {
  Serial.begin(baud);
  while ( !Serial ) delay(100);   // wait for native usb
  setup_pms(); 
  setup_bmp();
  setup_rtc();
}

//PROCESSO DE ROTINA DO SISTEMA 
void loop(){
  loop_pms();
  loop_bmp();
  RTC();
  delay(3000);
}
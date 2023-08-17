/***************************************************************************
Leitura de temperatura e pressão no local ok! agora preciso enviar para o banco de dados
Para mostrar na serial podemos pegar do banco de dados e gg
 ***************************************************************************/

//INCLUSÃO DE BIBLIOTECAS
#include <Wire.h> //Comunicação I2C
#include <SPI.h> //Comunicação SPI
#include <Adafruit_BMP280.h> //Temperatura e pressão
#include "RTClib.h" //Clock
#include <ESP8266WiFi.h> //Comunicação com wifi
#include <FirebaseESP8266.h> //Comunicação com o firebase
#include <SoftwareSerial.h>
#include "PMS.h"

#define baud 9600
// Configurações da rede Wi-Fi
#define ssid "STEMLABNET"
#define password "1n0v@t3ch.5t3m@#!"

//Definição do Serial Software
SoftwareSerial pmsSerial(13, 15); //tx - D8, rx - D7
//SoftwareSerial(rxPin, txPin), I used D8 for RX and D7 for TX (esp8266) and connected TX on PMS5003 to D8
PMS pms(pmsSerial);
PMS::DATA data;

// Configurações do Firebase
#define host "https://teste-selva-550d6-default-rtdb.firebaseio.com/regiao%201"
#define auth "8gMN7Bj27JTqwIVTccUxk0rqpe7zTcVaXG4nsQwq"

//   -------------DECLARAÇÕES GLOBAIS GLOBAIS-------------------
Adafruit_BMP280 bmp; // use I2C interface
Adafruit_Sensor *bmp_temp = bmp.getTemperatureSensor();
Adafruit_Sensor *bmp_pressure = bmp.getPressureSensor();
sensors_event_t temp_event, pressure_event;

RTC_DS3231 rtc; //OBJETO DO TIPO RTC_DS3231
char daysOfTheWeek[7][12] = {"Domingo", "Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sábado"};


//Instância da biblioteca FirebaseESP8266 e variáveis de caminho
FirebaseData firebaseData;
String temp_est, pms_est, press_est;

// ------------------- FIM ---------------------------------

void setup() {
  Serial.begin(baud);
  while ( !Serial ) delay(100);   // wait for native usb
  setup_bmp();
  stetup_rtc();
  setup_pms();
  setup_banco();
}

//PROCESSO DE ROTINA DO SISTEMA 
void loop(){
  loop_bmp();
  RTC();
  loop_pms();
  banco_dados();
  delay(100);
}
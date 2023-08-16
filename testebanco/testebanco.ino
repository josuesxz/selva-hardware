#include <ESP8266WiFi.h> //Comunicação com wifi
#include <FirebaseESP8266.h> //Comunicação com o firebase

// Configurações da rede Wi-Fi
#define ssid "STEMLABNET"
#define password "1n0v@t3ch.5t3m@#!"
// Configurações do Firebase
#define host "https://teste-selva-550d6-default-rtdb.firebaseio.com/regiao%201"
#define auth "8gMN7Bj27JTqwIVTccUxk0rqpe7zTcVaXG4nsQwq"
// Instância da biblioteca FirebaseESP8266
FirebaseData firebaseData;
String temp_est;

void setup(){
  // Conecta-se à rede Wi-Fi
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.print("Conectando à rede Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.println("Conectado à rede Wi-Fi");

  // Inicializa a biblioteca FirebaseESP8266
  Firebase.begin(host, auth);
}

void loop(){
  // Define o caminho do nó no Firebase
  temp_est = "/Estacao/EST_EST/Temperatura";

  // Envia o valor para o Firebase
  Firebase.setDouble(firebaseData, temp_est, random(0, 10)); 
  delay(2000);
}
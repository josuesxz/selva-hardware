#include <SoftwareSerial.h>

SoftwareSerial recept(13, 15); //rx - tx (desconecta o pino D8, só deixa o D7 (receptor))

void setup() {
  Serial.begin(9600);
  while (!Serial) {;}
  recept.begin(9600);
}

void loop() { // run over and over
  if (recept.available()) { //dados respectivamente 1.0 - 2.5 - 10.0 ug/m3 (cada um com 2 casas)
    Serial.println(recept.read()); //enquanto houver dado na serial ele "printa"
  }
    if (Serial.available()) {
    recept.write(recept.read());
    }
}
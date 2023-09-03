#include <SoftwareSerial.h>

SoftwareSerial recept(13, 15); //rx - tx
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.println("Conectados");
  recept.begin(9600);
  recept.println("Hello, world?");
}

void loop() { // run over and over
  if (recept.available()) {
    Serial.write(recept.read());
  }
  if (Serial.available()) {
    recept.write(recept.read());
  }
}

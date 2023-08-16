/*SoftwareSerial pmsSerial(D1, D2); // RX, TX
PMS pms(Serial1);

void setup_pms() {
  // Inicie a UART1 para depuração
  Serial1.begin(9600);
}

void loop_pms() {
    // Imprima os dados do sensor
    Serial.print("PM 1.0 (CF=1): ");
    Serial.println(data.PM_AE_UG_1_0);
    Serial.print("PM 2.5 (CF=1): ");
    Serial.println(data.PM_AE_UG_2_5);
    Serial.print("PM 10.0 (CF=1): ");
    Serial.println(data.PM_AE_UG_10_0);
} */

void setup_pms() {
  pmsSerial.begin(9600);
}

void loop_pms() {
  Serial.println(pms.read(data));
  /*if (pms.read(data)) {
    Serial.print("PM 1.0: ");
    Serial.print(data.PM_AE_UG_1_0);
    Serial.print(" PM 2.5: ");
    Serial.print(data.PM_AE_UG_2_5);
    Serial.print(" PM 10: ");
    Serial.println(data.PM_AE_UG_10_0);
  }*/
  delay(1000);
}

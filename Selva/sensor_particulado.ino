void setup_pms() {
  // Inicie a UART1 para depuração
  Serial1.begin(9600);
  // Inicie a UART0 para a comunicação com o sensor
  Serial.begin(9600);
}

void loop_pms() {
  // Leia os dados do sensor
  if (pms.read(data)) {
    // Imprima os dados do sensor
    Serial.print("PM 1.0 (CF=1): ");
    Serial.println(data.PM_AE_UG_1_0);
    Serial.print("PM 2.5 (CF=1): ");
    Serial.println(data.PM_AE_UG_2_5);
    Serial.print("PM 10.0 (CF=1): ");
    Serial.println(data.PM_AE_UG_10_0);
  }
}

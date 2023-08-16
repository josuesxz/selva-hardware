void setup_banco(){
  // Conecta-se à rede Wi-Fi
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

void banco_dados(){
  // Define o caminho do nó no Firebase
  temp_est = "/Estacao/EST_EST/Temperatura";
  pms_est = "/Estacao/EST_EST/PM";
  press_est = "/Estacao/EST_EST/Pressao";

  // Envia o valor para o Firebase
  Firebase.setDouble(firebaseData, temp_est, bmp.readTemperature()); 
  Firebase.setDouble(firebaseData, press_est, bmp.readPressure());
  Firebase.setInt(firebaseData, pms_est, pms.read(data));
}
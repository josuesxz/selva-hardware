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
  /*temperature();
  // Define o caminho do nó no Firebase
  temperatura = "/regiao 1/Temperatura";
  pressao = "/regiao 1/Pressao";

  // Envia o valor para o Firebase
  Firebase.setDouble(firebaseData, temperatura, temp_event.temperature); 
  Firebase.setDouble(firebaseData, pressao, pressure_event.pressure); */
}
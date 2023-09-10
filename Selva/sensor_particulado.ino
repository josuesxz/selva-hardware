void setup_pms(){
  while (!Serial) {;}
  recept.begin(baud);
}

void loop_pms(){   
  if (recept.available()) {
    Serial.write(recept.read()); //dados respectivamente 1.0 - 2.5 - 10.0 ug/m3 (cada um com 2 casas)
  }
}
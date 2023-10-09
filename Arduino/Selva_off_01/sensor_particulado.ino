void setup_pms(){
 Serial.begin(baud);

  Serial2.begin(baud);
  pms7003.init(&Serial2);
}

void loop_pms(){
  
   pms7003.updateFrame();
    sprintf(output, "PM1.0 (ug/m3):%2d",
                  pms7003.getPM_1_0());              
    Serial.print(output);
    sprintf(output, "  PM2.5 (ug/m3):%2d",
                  pms7003.getPM_2_5());
    Serial.print(output);
    sprintf(output, "  PM10  (ug/m3):%2d",
                  pms7003.getPM_10_0());              
    Serial.print(output);

    delay(50);
}
#ifndef _BOTAOH_
#define _BOTAOH_


void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t welength){
  String payloadString = (const char *)payload;
  Serial.print ("payloadString = ");
  Serial.println(payloadString);

  if (type == WStype_TEXT){ 
    byte separator = payloadString.indexOf('=');
    String var = payloadString.substring(0,separator);
    Serial.print(type);
    Serial.print("var = ");
    Serial.println(var);
    String valor = payloadString.substring(separator+1);
    Serial.print("valor = ");
    Serial.println(valor);
    Serial.println(" ");
    
    if(var == "LEDonoff"){
      LEDonnff = false;
      if(valor == "ON")LEDonnff = true;      
    }
    if(var == "texto"){
      lcd.clear();
      lcd.setBacklight(HIGH);
      lcd.setCursor(0,0);
      lcd.print("Arduino e ESP32 ");
      lcd.setCursor(0,1);
      lcd.print(valor);
    }
  }
}  
#endif

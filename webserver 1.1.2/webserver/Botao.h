#ifndef _BOTAOH_
#define _BOTAOH_

boolean LEDonnff = false;                             //Criando variavel boeana iniciando com valor falso.
String JSONtxt;                                       // Criando as strings
int CONT;

void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t welength){
  String payloadString = (const char *)payload;
  Serial.print ("payloadString = ");
  Serial.println(payloadString);
  switch(type) {
    case WStype_DISCONNECTED:
      Serial.printf("[%u] Disconnected!\n", num);
      break;
    case WStype_CONNECTED:
      {
        IPAddress ip = webSocket.remoteIP(num);
        Serial.printf("[%u] Connected from %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3], payload);
        //String jsonResponse = "{ \"id\": \""+ deviceId +"\", \"type\": 1, \"value\": " + String(digitalRead(relayPin)) + " }";
        //webSocket.broadcastTXT(jsonResponse); 
      }
      break;
    case WStype_TEXT: {
      byte separator = payloadString.indexOf('=');
      String var = payloadString.substring(0,separator);
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
      break;
    case WStype_BIN:
      Serial.printf("[%u] get binary length: %u\n", num, length);
      hexdump(payload, length);
      break;  
  }
}  
                                          // parte do codigo que faz a contagem do tempo usando a função millis().
void piscar(int porta, int tempo){        //Função piscar sem retorno.  
  static unsigned long ponto = 0;         //criando a variavel insigned long ponto iniciando em 0.
  if((millis() - ponto < tempo)){          
    digitalWrite(LED, HIGH);
    Serial.println("pasou aqui ligado");
  }else{
    digitalWrite(LED, LOW);    
    Serial.println("pasou aqui desligado");
  }
  if((millis() - ponto) >= (tempo * 2)){
    ponto = millis();
  }
}
//calculo para quando o millis() estourar e manter a contagem
unsigned long diferenca(unsigned long atual, unsigned long inicial){
  if (atual > inicial) {
    return (atual - inicial); 
  } else{
    return (((pow(2,8 * sizeof(atual)) -1) - inicial) + atual);
  }
}

void botao(){
  if (LEDonnff == true){
    piscar(LED,5400000); // escrever o codigo de ligar e desligar a tomada
  }else{
    digitalWrite(LED, LOW);
    //lcd.setBacklight(LOW);
  }   
  delay(20);
  Serial.println(millis()/1000);  
  CONT = (millis()/1000)/60;
  Serial.print(CONT);
  Serial.println(" Minutos");
 
  String LEDswitch = "OFF";
  if(LEDonnff == true) LEDswitch = "ON";
  JSONtxt = "{\"LEDonoff\":\""+LEDswitch+"\",\"cont\":\""+CONT+"\"}";
  webSocket.broadcastTXT(JSONtxt);
  delay(20);
}
#endif

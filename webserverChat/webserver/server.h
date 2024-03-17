#ifndef _SERVERH_
#define _SERVERH_

String JSONtxt;                                       // Criando as strings
String payloadString;

void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t welength){
  payloadString = (const char *)payload;
  Serial.print ("payloadString = ");
  Serial.println(payloadString);
  
  JSONtxt = "{\"texto\":\""+payloadString+"\"}";
  webSocket.broadcastTXT(JSONtxt);
  delay(2);
}    
#endif

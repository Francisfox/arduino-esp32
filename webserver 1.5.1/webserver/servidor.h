#ifndef _SERVERH_
#define _SERVERH_
                                                      //incluindo a class WebSocketsServer
#include <WebSocketsServer.h>                         // baixar a Biblioteca no Download ZIP em https://github.com/Links2004/arduinoWebSockets
#include <WebServer.h>                                //inclui a biblioteca webServer para acesso a rede wifi
#include <Update.h>
WebServer server(80);
WebSocketsServer webSocket = WebSocketsServer (88);   // criando o objeto WebSocket para o WebSocketsServer 

const char* ssid = "DESKTOP";                         //coloca o ssid da rede interna para acessar   
const char* password = "12345678";                    //coloca o password da rede interna para acessar 
                                       
#include "LED.h";
#include "LCD.h";

int CONT;

void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t welength){
  String payloadString = (const char *)payload;
//  Serial.print ("payloadString = ");
//  Serial.println(payloadString);
  if (type == WStype_TEXT){ 
    byte separator = payloadString.indexOf('=');
    String var = payloadString.substring(0,separator);
//    Serial.print("var = ");
//    Serial.println(var);
    String valor = payloadString.substring(separator+1);
//    Serial.print("valor = ");
//    Serial.println(valor);
//    Serial.println(" ");
    controle_Led(var,valor); 
    controle_LCD(var,valor);  
  }
}
#endif

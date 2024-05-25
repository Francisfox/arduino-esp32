// ---------------------------------------------------------------------------------------
// Simple code to setup the ESP32 as access point (device used for tests: ESP32-WROOM-32D).
//
// Written by mo thunderz (last update: 05.12.2021)
// ---------------------------------------------------------------------------------------
#include "Config.h"
#include "WifiConfig.h"
#include <WebServer.h>                                //inclui a biblioteca webServer para acesso a rede wifi

// baixar a Biblioteca no Download ZIP em https://github.com/Links2004/arduinoWebSockets
#include <WebSocketsServer.h>                         //incluindo a class WebSocketsServer 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "SAIDAS.h"
//Inicializa o display no endereco 0x27
LiquidCrystal_I2C lcd(0x3F,16,2);      

WebServer server(80);
WebSocketsServer webSocket = WebSocketsServer (88);   // criando o objeto WebSocket para o WebSocketsServer 
SAIDAS LED1(2);
int LED = 2;
#include "Web.h";
#include "Botao.h";

String responseHTML = ""
  "<!DOCTYPE html><html><head><title>CaptivePortal</title></head><body>"
  "<meta http-equiv=\"refresh\" content=\"1;url=http://172.217.28.1:81/stream\"/>"
  "<h1>Please Wait!</h1><p>You will be redirected to the camera stream "
  "shortly.</p></body></html>";
 
void setup() {
  Serial.begin(BAUD_RATE);                               // init serial port for debugging
  pinMode(LED,OUTPUT); 
  #ifdef ENABLE_WIFI
    wifi_config.begin();
  #endif
  Serial.print("Starting Access Point ... ");

  Serial.print("IP address = ");
  Serial.println(WiFi.softAPIP());

  server.on("/",WebSite);
  server.begin(); 
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);
}
void loop() {
  webSocket.loop();
  server.handleClient();
  LED1.toggle(); 
  botao();
  delay(2);//allow the cpu to switch to other tasks

}

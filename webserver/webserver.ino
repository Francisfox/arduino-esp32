
#include <WebServer.h>
#include <WebSocketsServer.h>                         //incluindo a class WebSocketsServer 

const char* ssid = "wifi-ssid";
const char* password = "wifi-password";

WebServer server(80);
WebSocketsServer webSocket = WebSocketsServer (88);   // criando o objeto WebSocket para o WebSocketsServer 

int LED = 2;
#include "Web.h";
#include "Botao.h";

void setup(void) {
  Serial.begin(115200);
  pinMode(LED,OUTPUT);
  WiFi.begin(ssid,password);
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(1000);
  }
  WiFi.mode(WIFI_STA);
  Serial.println("Start ESP ");
  Serial.println(WiFi.localIP());
  server.on("/",WebSite);
  server.begin();
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);
}

void loop() {
  webSocket.loop();
  server.handleClient();
  botao();
  delay(2);//allow the cpu to switch to other tasks
}

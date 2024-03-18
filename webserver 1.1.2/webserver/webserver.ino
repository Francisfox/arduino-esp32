
#include <WebServer.h>                                //inclui a biblioteca webServer para acesso a rede wifi
// baixar a Biblioteca no Download ZIP em https://github.com/Links2004/arduinoWebSockets
#include <WebSocketsServer.h>                         //incluindo a class WebSocketsServer 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//Inicializa o display no endereco 0x27
LiquidCrystal_I2C lcd(0x3F,16,2);                  

const char* ssid = "YOUR SSID";                        //coloca o ssid da rede interna para acessar 
const char* password = "YOUR PASSWORD";                //coloca o password da rede interna para acessar 
                   
WebServer server(80);
WebSocketsServer webSocket = WebSocketsServer (88);   // criando o objeto WebSocket para o WebSocketsServer 

int LED = 2;
#include "Web.h";
#include "Botao.h";

void setup(void) {
  Serial.begin(115200);
  pinMode(LED,OUTPUT);
  WiFi.begin(ssid,password);
  lcd.init();
  lcd.setCursor(0,0);
  while(WiFi.status() != WL_CONNECTED){
    lcd.setBacklight(HIGH);
    lcd.print(".");
    Serial.print(".");
    delay(1000);
  }
  WiFi.mode(WIFI_STA);
  Serial.println("Start ESP ");
  lcd.clear();
  lcd.setBacklight(HIGH);
  lcd.setCursor(0,0);
  lcd.print("Start ESP ");
  lcd.setCursor(0,1);  
  lcd.print(WiFi.localIP());
  Serial.println(WiFi.localIP());
  server.onNotFound([](){
    if(!handleFileRead(server.uri()))
      server.send(404, "text/plain", "FileNotFound");
  });
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

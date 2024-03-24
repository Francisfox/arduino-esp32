//versão: webserver"1.1.1.1"
//autor: "Francismar dos Santos Brito"
// esta versão dispoe da conunicação WebSocketsServer, display LCD, Leitura de distancia e uma saida em LED

#include "servidor.h";
#include "Web.h";
#include "LED.h";
#include "LCD.h";
#include "distancia.h";

void setup(void) {
  pinMode(LED,OUTPUT);
  WiFi.begin(ssid,password);
  lcd.init();
  lcd.setCursor(0,0);
  HCSR04.begin(triggerPin, echoPin);
  while(WiFi.status() != WL_CONNECTED){
    lcd.setBacklight(HIGH);
    lcd.print(".");

    delay(1000);
  }
  WiFi.mode(WIFI_STA);
  lcd.clear();
  lcd.setBacklight(HIGH);
  lcd.setCursor(0,0);
  lcd.print("Start ESP ");
  lcd.setCursor(0,1);  
  lcd.print(WiFi.localIP());
  server.on("/",WebSite);
  server.begin();
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);
}

void loop() {
  curentTime = millis();
  distances = HCSR04.measureDistanceCm();
  webSocket.loop();
  server.handleClient();
  LED1();
}

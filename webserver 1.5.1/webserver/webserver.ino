//versão: webserver"1.1.1.1.1"
//autor: "Francismar dos Santos Brito"
// esta versão dispoe da conunicação WebSocketsServer, display LCD, Leitura de distancia e uma saida em LED

#include "servidor.h";
#include "Web.h";

#include "LED.h";
#include "LCD.h";
#include "distancia.h";

unsigned long Previoustime = 0;
unsigned long curentTime = 0;
const long interval = 250;

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
  //server.on("/", HTTP_GET,WebSite);
  server.on("/", HTTP_GET, []() {
      server.sendHeader("Connection", "close");
      server.send(200, "text/html", loginIndex);
    });
  server.on("/serverIndex", HTTP_GET, []() {
    server.sendHeader("Connection", "close");
    server.send(200, "text/html", webSiteCont);
    });
      server.on("/atualizar", HTTP_GET, []() {
      server.sendHeader("Connection", "close");
      server.send(200, "text/html", serverIndex);
    });   
  server.on("/update", HTTP_POST, []() {
    server.sendHeader("Connection", "close");
    server.send(200, "text/plain",(Update.hasError()) ? "FAIL" : "OK");
      ESP.restart();
    }, []() {
      HTTPUpload& upload = server.upload();
      if (upload.status == UPLOAD_FILE_START) {
        if (!Update.begin(UPDATE_SIZE_UNKNOWN)) { //start with max available size
          Update.printError(Serial);
        }
      } else if (upload.status == UPLOAD_FILE_WRITE) {
        /* flashing firmware to ESP*/
        if (Update.write(upload.buf, upload.currentSize) != upload.currentSize) {
          Update.printError(Serial);
        }
      } else if (upload.status == UPLOAD_FILE_END) {
        if (Update.end(true)) { //true to set the size to the current progress
        } else {
          Update.printError(Serial);
        }
      }
    });  
  server.begin();
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);
}

void loop() {
  curentTime = millis();
  server.handleClient();
  webSocket.loop();

  if(curentTime - Previoustime >= interval){
    Previoustime = curentTime;
    distances = HCSR04.measureDistanceCm();
    LED1();
  }  
}

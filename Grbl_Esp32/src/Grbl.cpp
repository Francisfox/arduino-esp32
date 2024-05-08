#include "Grbl.h"
#include <WiFi.h>
void grbl_init() {
  WiFi.persistent(false);       //Desativa o armazenamento permanente das configurações de WIFI
  WiFi.disconnect(true);        //Desconecta imediatamente o dispositivo de uma rede WIFI
  WiFi.enableSTA(false);        //Desabilita o modo de Station (STA) - não permitindo a opção de acessar redes existentes 
  WiFi.enableAP(false);         //DEsabilita o dispositivo de atuar como ponto de acesso WIFI
  WiFi.mode(WIFI_OFF);          //Desabilita completamente o módulo WIFI, desativando todas as operações relacionadas ao WIFI
  client_init();                // Setup serial baud rate and interrupts
}  
void run_once() {
  
}

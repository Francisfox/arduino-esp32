#include "Grbl.h"
#include <WiFi.h>
void grbl_init() {
  WiFi.persistent(false);       //Desativa o armazenamento permanente das configurações de WIFI
  WiFi.disconnect(true);        //Desconecta imediatamente o dispositivo de uma rede WIFI
  WiFi.enableSTA(false);        //Desabilita o modo de Station (STA) - não permitindo a opção de acessar redes existentes 
}  
void run_once() {
  
}

/*
  WifiConfig.cpp -  wifi functions class
*/
#     include "WifiConfig.h"
#     include "WifiServices.h"
namespace WebUI {
  
  bool   WiFiConfig::_events_registered = false;
  IPAddress local_IP(192,168,4,1);
  IPAddress gateway(192,168,4,1);
  IPAddress subnet(255,255,255,0);
  //IPAddress ip(IP), mask(MK), gateway(GW);

  void WiFiConfig::WiFiEvent(WiFiEvent_t event) {
    switch (event) {
      case SYSTEM_EVENT_STA_GOT_IP:
        break;
      case SYSTEM_EVENT_STA_DISCONNECTED:
        break;
      default:
        break;
    }
  }
  // Configure IP addresses of the local access point
  bool WiFiConfig::StartAP() {
    wifi_services.end(); 
    WiFi.enableSTA(false);
    WiFi.mode(WIFI_AP); 
    
    WiFi.softAP(DEFAULT_AP_SSID, DEFAULT_AP_PWD); 
    WiFi.config(local_IP, gateway, subnet);
    //WiFi.config(ip, gateway, mask); 
    return true;
  }
  /**
  * begin WiFi setup
  */
  void WiFiConfig::begin() {
    wifi_services.end();
    //setup events
    if (!_events_registered) {
      WiFi.onEvent(WiFiConfig::WiFiEvent);
      _events_registered = true;
    }
    WiFi.persistent(false);       //Desativa o armazenamento permanente das configurações de WIFI
    WiFi.disconnect(true);        //Desconecta imediatamente o dispositivo de uma rede WIFI
    WiFi.enableSTA(false);        //Desabilita o modo de Station (STA) - não permitindo a opção de acessar redes existentes 
    WiFi.enableAP(false);         //DEsabilita o dispositivo de atuar como ponto de acesso WIFI
    WiFi.mode(WIFI_OFF);          //Desabilita completamente o módulo WIFI, desativando todas as operações relacionadas ao WIFI          
    int8_t wifiMode = 2;
    if (wifiMode == ESP_WIFI_AP) {
      StartAP();
    }  
  }
}

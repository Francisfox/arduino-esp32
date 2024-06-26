#pragma once

/*
  WifiConfig.h -  wifi functions class

  Copyright (c) 2014 Luc Lebosse. All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

//Preferences entries

#include <WiFi.h>                  // needed to connect to setup an accesspoint
#include "Config.h"
namespace WebUI {

  static const char* DEFAULT_AP_SSID           = "ESP_AP";
  static const char* DEFAULT_AP_PWD            = "12345678";
  static const char* DEFAULT_AP_IP             = "192.168.4.1";
  static const char* DEFAULT_AP_MK             = "255.255.255.0";
  static const char* DEFAULT_AP_GATEWAY        = "192.168.4.1";
  
  class WiFiConfig {
    public:
      static bool        StartAP();
      static void        begin();
    private:
      static void   WiFiEvent(WiFiEvent_t event);
      static bool   _events_registered;  
  };
}
// Declaração da classe para que seja visível em outros arquivos
extern WebUI::WiFiConfig wifi_config;

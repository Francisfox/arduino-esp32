#pragma once

//WifiServices.h -  wifi services functions class

namespace WebUI {
    class WiFiServices {
    public:
      static bool begin();
      static void end();
    };
    extern WiFiServices wifi_services;
}

#pragma once
// Config.h - compile time configuration

// serial monitor, sender, etc uses a different value than 115200
#define BAUD_RATE 115200
#define ENABLE_WIFI  //enable wifi

//Radio Mode
const int ESP_RADIO_OFF = 0;
const int ESP_WIFI_STA  = 1;
const int ESP_WIFI_AP   = 2;
const int ESP_BT        = 3;

// Grbl versioning system
const char* const GRBL_VERSION       = "1.3a";
const char* const GRBL_VERSION_BUILD = "20240507";
//#include <sdkconfig.h>
#include <Arduino.h>
#include <EEPROM.h>
#include <driver/rmt.h>
#include <esp_task_wdt.h>
#include <freertos/task.h>
#include <Preferences.h>

#include <driver/timer.h>

void grbl_init();
void run_once();

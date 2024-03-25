#ifndef _LCDH_
#define _LCDH_
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//Inicializa o display no endereco 0x27
LiquidCrystal_I2C lcd(0x3F,16,2);                  

void controle_LCD(String var, String valor){
  if(var == "texto"){
    lcd.clear();
    lcd.setBacklight(HIGH);
    lcd.setCursor(0,0);
    lcd.print("Arduino e ESP32 ");
    lcd.setCursor(0,1);
    lcd.print(valor);
  }
}
#endif

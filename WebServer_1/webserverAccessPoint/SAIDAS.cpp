#include "Arduino.h"
#include "SAIDAS.h"
SAIDAS::SAIDAS(int pin){
  this->_pin = pin;
  this->_state = false;
  pinMode(_pin, OUTPUT);
}
void SAIDAS::on(){
  digitalWrite(_pin, HIGH);
  _state = true;
}
void SAIDAS::off(){
  digitalWrite(_pin, LOW);
  _state = false;
}
void SAIDAS::toggle(){
  if(_state){
    off();  
  }else{
    on();
  }
}
bool SAIDAS::isOn(){
  return _state;
}

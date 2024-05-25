#ifndef SAIDAS_H
#define SAIDAS_H
class SAIDAS {
  public:
    SAIDA(int pin);
    void on();
    void off();
    void toggle();
    bool isOn();
  private:
    int _pin;
    bool _state;
}
#endif 

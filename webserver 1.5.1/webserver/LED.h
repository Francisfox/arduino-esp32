#ifndef _LEDH_
#define _LEDH_
int LED = 2;
boolean LEDonnff = false;                             //Criando variavel boeana iniciando com valor falso.
double* distances = 0;
String JSONtxt;                       // Criando as strings

void LED1(){
    String LEDswitch = "OFF";
    switch(LEDonnff){
      case true:{
        digitalWrite(LED, HIGH);
        LEDswitch = "ON";
        break;
        }
      case false:{
        digitalWrite(LED, LOW);
        LEDswitch = "OFF";
        break;
        }  
      } 
    JSONtxt = "{\"LEDonoff\":\""+LEDswitch+"\",\"cont\":\""+distances[0]+"\"}";
    webSocket.broadcastTXT(JSONtxt);
}
void controle_Led(String var,String valor){
  if(var == "LEDonoff"){
      LEDonnff = false;
      if(valor == "ON")LEDonnff = true;      
    }
}
#endif

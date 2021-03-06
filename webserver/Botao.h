#ifndef _BOTAOH_
#define _BOTAOH_

boolean LEDonnff = false;                             //Criando variavel boeana iniciando com valor falso.
String JSONtxt;                                       // Criando as strings

void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t welength){
  String payloadString = (const char *)payload;
  Serial.print ("payloadString = ");
  Serial.println(payloadString);
  if (type == WStype_TEXT){ 
    byte separator = payloadString.indexOf('=');
    String var = payloadString.substring(0,separator);
    Serial.print("var = ");
    Serial.println(var);
    String val = payloadString.substring(separator+1);
    Serial.print("var = ");
    Serial.println(var);
    Serial.println(" ");
    if(var = "LEDonnff"){
      LEDonnff = false;
      if(val == "ON")LEDonnff = true;      
    }
  }
}  
                                          // parte do codigo que faz a contagem do tempo usando a função millis().
void piscar(int porta, int tempo){        //Função piscar sem retorno.  
  static unsigned long ponto = 0;         //criando a variavel insigned long ponto iniciando em 0.
  if((millis() - ponto < tempo)){          
    digitalWrite(LED, HIGH);
    Serial.println("pasou aqui ligado");
  }else{
    digitalWrite(LED, LOW);    
    Serial.println("pasou aqui desligado");
  }
  if((millis() - ponto) >= (tempo * 2)){
    ponto = millis();
  }
}
//calculo para quando o millis() estourar e manter a contagem
unsigned long diferenca(unsigned long atual, unsigned long inicial){
  if (atual > inicial) {
    return (atual - inicial); 
  } else{
    return (((pow(2,8 * sizeof(atual)) -1) - inicial) + atual);
  }
}

void botao(){
  if (LEDonnff == true){
    piscar(LED,5400000); // escrever o codigo de ligar e desligar a tomada
  }else{
    digitalWrite(LED, LOW);
  }   
  delay(20);
  Serial.println(millis()/1000);
  Serial.print((millis()/1000)/60);
  Serial.println(" Minutos");
  String LEDswitch = "OFF";
  if(LEDonnff == true) LEDswitch = "ON";
  JSONtxt = "{\"LEDonoff\":\""+LEDswitch+"\"}";
  webSocket.broadcastTXT(JSONtxt);
  delay(20);
}
#endif

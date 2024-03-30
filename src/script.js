InitWebSocket()
  function InitWebSocket(){
    websock = new WebSocket('ws://'+window.location.hostname+':88/');
    websock.onmessage = function(evt){
      JSONobj = JSON.parse(evt.data);
      document.getElementById('btn').innerHTML = JSONobj.LEDonoff ; 
      document.getElementById('CONT').innerHTML = JSONobj.cont; 
      if(JSONobj.LEDonoff == 'ON'){
        document.getElementById('btn').style.background = '#FFA200';
        document.getElementById('btn').style["boxShadow"] = "0px 0px 0px 8px #FFA200";
      }else{
        document.getElementById('btn').style.background = '#111111';
        document.getElementById('btn').style["boxShadow"] = "0px 0px 0px 8px #111111";
      }
    }
  }
  function enviar(){
    var texto = "texto="+document.getElementById('texto').value
    document.getElementById('texto').value = "";
    websock.send(texto);    
  }
  function button(){
    btn = 'LEDonoff=ON';
    if(document.getElementById('btn').innerHTML === 'ON'){
      btn = 'LEDonoff=OFF';
    }
    websock.send(btn);
  }
  function Botao(numero) {
    var request = new XMLHttpRequest();
    request.open("GET", "ajax_botao" + numero, true);
    request.send(null);
    request.onreadystatechange = function()
    {
      if (this.readyState == 4) {
        if (this.status == 200) {
          if (this.responseText != null) {
            var dados = this.responseText.split('|');
            for (i = 1; i <= 40; i++) {
              if (dados[i] == 0) {
                document.getElementById("botao" + i).innerHTML = "<div class='rele_desligada'></div>";
              } else {
                document.getElementById("botao" + i).innerHTML = "<div class='rele_ligada'></div>";
              }
            }

          }
        }
      }
    }
  }

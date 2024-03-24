//=========================================
//HTML + CSS + JavaScript codes for webpage
//=========================================
#ifndef _WEBPAGECODEH_
#define _WEBPAGECODEH_
static const char webSiteCont[] PROGMEM =
  R"=====(
<!DOCTYPE HTML>
<HTML>
<META name = 'viewport' content = 'width = device-width, initial-scale = 1'>
<SCRIPT>
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
</SCRIPT>
<style type="text/css">
  div > h2{
    color: #00979C;
  }
  body{
    font-family: Arial;
    margin: 0px;
    }
    .header{
      width: 100%;
      margin-top: 0px;
      margin-bottom: 3px;
      background-color: #F6F9F9;     
      text-align: right;
      color: gray;
      font-size: 11px;
    }

    #wrapper {
        padding-top: 10px;
        position: relative;
        width: 95%;
        height: 400px;
        margin-right: auto;
        margin-top: 0;
        margin-left: auto;
        font-size: 30px;
        color: gray;
        text-align: center;
        font-family: arial;
        border: 0px solid red;
    }

    div.rele_ligada {
        background-color: green;
        position: absolute; 
        left:0px; 
        top:0px; 
        width: 47px; 
        height: 47px; 
        border-radius:5px;
    }

    div.rele_desligada {
        background-color: gray;
        position: absolute; 
        left:0px; 
        top:0px; 
        width: 47px; 
        height: 47px; 
        border-radius:5px;
    }


    .botao {
        position: absolute; 
        left:55px; 
        top:0px;

        -moz-box-shadow:inset 0px 1px 0px 0px #ffffff;
        -webkit-box-shadow:inset 0px 1px 0px 0px #ffffff;
        box-shadow:inset 0px 1px 0px 0px #ffffff;
        background:-webkit-gradient( linear, left top, left bottom, color-stop(0.05, #ededed), color-stop(1, #dfdfdf) );
        background:-moz-linear-gradient( center top, #ededed 5%, #dfdfdf 100% );
        filter:progid:DXImageTransform.Microsoft.gradient(startColorstr='#ededed', endColorstr='#dfdfdf');
        background-color:#ededed;
        -moz-border-radius:6px;
        -webkit-border-radius:6px;
        border-radius:6px;
        border:1px solid #dcdcdc;
        display:inline-block;
        color:#777777;
        font-family:arial;
        font-size:28px;
        font-weight:bold;
        padding:6px 24px;
        text-decoration:none;
        text-shadow:1px 1px 0px #ffffff;
        width: 150px;
        text-align: center;
    }.botao:hover {
        background:-webkit-gradient( linear, left top, left bottom, color-stop(0.05, #dfdfdf), color-stop(1, #ededed) );
        background:-moz-linear-gradient( center top, #dfdfdf 5%, #ededed 100% );
        filter:progid:DXImageTransform.Microsoft.gradient(startColorstr='#dfdfdf', endColorstr='#ededed');
        background-color:#dfdfdf;
        cursor: pointer;
    }.botao:active {
}
h1 {
  font-size: 40px;
  text-align: center;
}
#btn{
  display: inline-block;
  text-decoration:none;
  background: #8cd460;
  color: rgba(255,255,255,0.80);
  font-weight: bold;
  font: 100px arial,sans-serif;
  width: 320px;
  height: 320px;
  line-height: 320px;
  border-radius: 50%;
  margin-top: 60px;
  text-align: center;
  vertical-align: middle;
  overflow: hidden;
  box-shadow: 0px 0px 0px 8px #8cd460;
  border: solid 2px rgba(255,255,255, 0.47);
  transition: 0.4s;
}
  
    </style>
  </head>
  <BODY>
  <center>
   
        <div class="header"><div style="padding: 5px;">Projeto inicial para ESP8266 Francismar dos Santos</div></div>
        <h1>PORTAS EM FUN&Ccedil;&Atilde;O DIGITAL</h1>
        <h2><a id = "CONT"></a><h2/>
        <input type="text"id="texto" nome"texto">
        <button onclick = 'enviar()'>Enviar</button>
        <div id='wrapper'>
          <a href = "#" id = "btn" ONCLICK = 'button()'></a>
        </div> 
        <br>
    </center>
</BODY>
</HTML>
)=====";
void WebSite(){
  server.send(200,"text/html",webSiteCont);
}
#endif

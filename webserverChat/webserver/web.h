//=========================================
//HTML + CSS + JavaScript codes for webpage
//=========================================
#ifndef _WEBPAGECODEH_
#define _WEBPAGECODEH_

static const char webSiteCont[] PROGMEM =
  R"=====(
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Real-Time Chat Application</title>
  </head>
  <SCRIPT>
    InitWebSocket()
    function InitWebSocket(){
      websock = new WebSocket('ws://'+window.location.hostname+':88/');
      websock.onmessage = function(evt){
      JSONobj = JSON.parse(evt.data);
      let msg = JSONobj.texto;
    const novaMensagem = document.createElement("li"); //<li></li>
    novaMensagem.classList.add("mensagem"); //<li class="mensagem"></li>
    novaMensagem.textContent = msg; //<li class="mensagem">msg</li>
    document.getElementById('mensagens').appendChild(novaMensagem);  
    }     
  }
  
  function enviar(){
    if (document.getElementById('texto').value !== "") {
      let texto = document.getElementById('texto').value
      document.getElementById('texto').value = "";
      websock.send(texto);
    }    
  }
</SCRIPT>  

  <style type="text/css">
  @font-face {
    font-family: 'Trench';
    font-weight: 400;
    src: url('./assets/trench100free.otf');
  }
  
  :root {
    box-sizing: border-box;
  }
  
  * {
    margin: 0;
    padding: 0;
    list-style-type: none;
    font-family: 'montserrat';
  }
  
  body {
    height: 100dvh;
    display: flex;
    flex-direction: column;
    justify-content: space-between;
    align-items: center;
  }
  
  header {
    font-family: 'Trench';
    background-color: #040e29;
    color: #fff;
    width: 100%;
    display: flex;
    justify-content: center;
    align-items: flex-end;
    padding: 1rem 0;
    font-size: 1.4rem;
    & > img {
      max-height: 3rem;
      margin-right: 0.2rem;
    }
  }
  
  main {
    display: flex;
    flex-direction: column;
    min-width: 70%;
    flex-grow: 1;
  }
  
  #mensagens {
    display: flex;
    flex-direction: column;
    justify-content: flex-start;
    align-items: center;
    min-height: 75%;
    background-color: #eaeaea;
    flex-grow: 1;
    width: 100%;
    font-size: 0.9rem;
  }
  
  .mensagem {
    background-color: #040e29;
    color: #fff;
    width: 85%;
    margin: 1rem 0.5rem;
    padding: 0.5rem;
    border-radius: 10px;
  }
  
  #mensagens > .mensagem:last-of-type {
    background-color: #0b266f;
  }
  
  #envio-mensagens {
    padding-top: 0.5rem;
    padding-bottom: 1rem;
    display: flex;
    justify-content: flex-end;
    min-width: 40%;
    max-height: 3rem;
    & > input {
      flex-grow: 1;
      padding: 0.5rem 0.3rem;
    }
    & > button {
      display: flex;
      justify-content: center;
      align-items: center;
      cursor: pointer;
      background-color: #040e29;
      color: #fff;
      padding: 0.8rem;
      border: none;
      border-radius: 12px;
      margin-left: 0.5rem;
      &:hover {
        background-color: #0b266f;
      }
    }
  }
  
  @media (max-width: 500px) {
    main {
      width: 90%;
    }
  }
</style> 
  <body>
    <main>
      <ul id="mensagens"></ul>
      <div id="envio-mensagens">
        <input id="texto" autocomplete="off" autofocus />
        <button id="enviar" onclick = 'enviar()'>
          <svg
            width="16"
            height="16"
            fill="currentColor"
            class="bi bi-send-fill"
            viewBox="0 0 16 16"
          >
            <path
              d="M15.964.686a.5.5 0 0 0-.65-.65L.767 5.855H.766l-.452.18a.5.5 0 0 0-.082.887l.41.26.001.002 4.995 3.178 3.178 4.995.002.002.26.41a.5.5 0 0 0 .886-.083zm-1.833 1.89L6.637 10.07l-.215-.338a.5.5 0 0 0-.154-.154l-.338-.215 7.494-7.494 1.178-.471z"
            />
          </svg>
        </button>
      </div>
    </main>
  </body>
</html>
)=====";
void WebSite(){
  server.send(200,"text/html",webSiteCont);
}
#endif

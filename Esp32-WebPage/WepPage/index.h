const char PAGE_MAIN[] PROGMEM = R"=====(

<!DOCTYPE html>
<html lang="en" class="js-focus-visible">

<title>Web Page Update Demo</title>

  <style>
    table {
      position: relative;
      width:100%;
      border-spacing: 0px;
    }
    tr {
      border: 1px solid white;
      font-family: "Verdana", "Arial", sans-serif;
      font-size: 20px;
    }
    th {
      height: 20px;
      padding: 3px 15px;
      background-color: #343a40;
      color: #FFFFFF !important;
      }
    td {
      height: 20px;
       padding: 3px 15px;
    }
    .tabledata {
      font-size: 24px;
      position: relative;
      text-align: center;
      padding-left: 5px;
      padding-top: 5px;
      height:   25px;
      border-radius: 5px;
      color: #FFFFFF;
      line-height: 20px;
      transition: all 200ms ease-in-out;
    }
   .bodytext {
      font-family: "Verdana", "Arial", sans-serif;
      font-size: 24px;
      text-align: left;
      font-weight: light;
      border-radius: 5px;
      display:inline;
    }
    .navbar {
      width: 100%;
      height: 50px;
      margin: 0;
      padding: 10px 0px;
      background-color: #FFF;
      color: #000000;
      border-bottom: 5px solid #293578;
    }
    .fixed-top {
      position: fixed;
      top: 0;
      right: 0;
      left: 0;
      z-index: 1030;
    }
    .navtitle {
      float: left;
      height: 50px;
      font-family: "Verdana", "Arial", sans-serif;
      font-size: 50px;
      font-weight: bold;
      line-height: 50px;
      padding-left: 20px;
    }
   .navheading {
     position: fixed;
     left: 60%;
     height: 50px;
     font-family: "Verdana", "Arial", sans-serif;
     font-size: 20px;
     font-weight: bold;
     line-height: 20px;
     padding-right: 20px;
   }
   .navdata {
      justify-content: flex-end;
      position: fixed;
      left: 70%;
      height: 50px;
      font-family: "Verdana", "Arial", sans-serif;
      font-size: 20px;
      font-weight: bold;
      line-height: 20px;
      padding-right: 20px;
   }
    .category {
      font-family: "Verdana", "Arial", sans-serif;
      font-weight: bold;
      font-size: 32px;
      line-height: 50px;
      padding: 20px 10px 0px 10px;
      color: #000000;
    }
    .heading {
      font-family: "Verdana", "Arial", sans-serif;
      font-weight: normal;
      font-size: 28px;
      text-align: left;
    }
    
    .btnul{
      background-color: #444444;
      border-radius: 15px;
      color: white;
      padding: 10px 20px;
      text-align: center;
      text-decoration: none;
      display: inline-block;
      font-size: 16px;
      margin: flex;
      cursor: pointer;
    }
    .btn {
      background-color: #444444;
      border-radius: 15px;
      color: white;
      padding: 10px 20px;
      text-align: center;
      text-decoration: none;
      display: inline-block;
      font-size: 16px;
      margin: flex;
      margin-left: 41%;
      cursor: pointer;
    }
    .foot {
      font-family: "Verdana", "Arial", sans-serif;
      font-size: 20px;
      position: relative;
      height:   30px;
      text-align: center;   
      color: #AAAAAA;
      line-height: 20px;
      margin: 40px; 
    }
    .container {
      max-width: 1800px;
      margin: 0 auto;
    }
    table tr:first-child th:first-child {
      border-top-left-radius: 5px;
    }
    table tr:first-child th:last-child {
      border-top-right-radius: 5px;
    }
    table tr:last-child td:first-child {
      border-bottom-left-radius: 5px;
    }
    table tr:last-child td:last-child {
      border-bottom-right-radius: 5px;
    }
    
  </style>

  <body style="background-color: #efefef" onload="process()">
  
    <header>
      <div class="navbar fixed-top">
          <div class="container">
            <div class="navtitle">Clinostato Center</div>
            <div class="navdata" id = "date">mm/dd/yyyy</div>
            <div class="navheading">DATE</div><br>
            <div class="navdata" id = "time">00:00:00</div>
            <div class="navheading">TIME</div>
          </div>
      </div>
    </header>
  
    <main class="container" style="margin-top:70px">
      <div class="category">Sensores</div>
      <div style="border-radius: 10px !important;">
      <table style="width:60%">
      <colgroup>
        <col span="1" style="background-color:rgb(230,230,230); width: 20%; color:#000000 ;">
        <col span="1" style="background-color:rgb(200,200,200); width: 15%; color:#000000 ;">
      </colgroup>
      <col span="2"style="background-color:rgb(0,0,0); color:#FFFFFF">
      <col span="2"style="background-color:rgb(0,0,0); color:#FFFFFF">
      <tr>
        <th colspan="1"><div class="heading">Medida</div></th>
        <th colspan="1"><div class="heading">Valor</div></th>
      </tr>
      <tr>
        <td><div class="bodytext">Temperatura</div></td>
        <td><div class="tabledata" id = "b0"></div></td>
      </tr>
       <tr>
        <td><div class="bodytext">Humidade</div></td>
        <td><div class="tabledata" id = "b1"></div></td>
      </tr>
      <tr>
        <td><div class="bodytext">Aceleracao Total</div></td>
        <td><div class="tabledata" id = "b2"></div></td>
      </tr>
       <tr>
        <td><div class="bodytext">Aceleracao em X</div></td>
        <td><div class="tabledata" id = "b3"></div></td>
      </tr>
       <tr>
        <td><div class="bodytext">Aceleracao em Y</div></td>
        <td><div class="tabledata" id = "b4"></div></td>
      </tr>
       <tr>
        <td><div class="bodytext">Aceleracao em Z</div></td>
        <td><div class="tabledata" id = "b5"></div></td>
      </tr>
      </table>
    </div>

    <div class="category">Controles</div>
    <table style="width:60%">
      <colgroup>
        <col span="1" style="background-color:rgb(230,230,230); width: 20%; color:#000000 ;">
        <col span="1" style="background-color:rgb(200,200,200); width: 15%; color:#000000 ;">
      </colgroup>
      <col span="2"style="background-color:rgb(0,0,0); color:#FFFFFF">
      <col span="2"style="background-color:rgb(0,0,0); color:#FFFFFF">
      <tr>
        <th colspan="1"><div class="heading">Movimentar</div></th>
        <th colspan="1"><div class="heading">Comando</div></th>
      </tr>
      <tr>
        <td><div class="bodytext">Velocidade dos Motores</div></td>
        <td>
        <ul>
            <button type="button" class = "btnul" id = "btn0" onclick="ButtonPress0()">Toggle</button>
            <button type="button" class = "btnul" id = "btn1" onclick="ButtonPress1()">Toggle</button>
            <button type="button" class = "btnul" id = "btn2" onclick="ButtonPress2()">Toggle</button>
            <button type="button" class = "btnul" id = "btn3" onclick="ButtonPress3()">Toggle</button>
        </ul>
        </td>
      </tr>
      <tr>
          <td><div class="bodytext">Todos os Eixos</div></td>
        <td>
        <button type="button" class = "btn" id = "btn4" onclick="ButtonPress4()">Toggle</button>
        </td>
      </tr>
       <tr>
        <td><div class="bodytext">Eixo 1</div></td>
        <td>
            <button type="button" class = "btn" id = "btn5" onclick="ButtonPress5()">Toggle</button>
        </td>
      </tr>
       <tr>
        <td><div class="bodytext">Eixo 2</div></td>
        <td>
        <button type="button" class = "btn" id = "btn6" onclick="ButtonPress6()">Toggle</button>
        </td>
      </tr>
       <tr>
        <td><div class="bodytext">Eixo 3</div></td>
        <td>
        <button type="button" class = "btn" id = "btn7" onclick="ButtonPress7()">Toggle</button>
       </td>
      </tr>
    </table>

    <div class="bodytext">
        <p>
        Enviando dados para a Planilha Google <br>
        Clique <a href="link da planilha">aqui</a> para acessar a planilha.<br>
        Clique <a href="https://github.com/Luidooo/Clinostato_tridimensional">aqui</a> para acessar a documentacao.
        
        </p>
    </div>

    </main>

  <footer div class="foot" id = "temp" >
      Universidade de Brasilia (UnB) <br>
      Desenvolvido pela Faculdade do Gama (FGA) <br>
      Em Parceria com o Instituto de Biologia (IB)
  </footer>
  
  </body>


  <script type = "text/javascript">
  
    // global variable visible to all java functions
    var xmlHttp=createXmlHttpObject();

    // function to create XML object
    function createXmlHttpObject(){
      if(window.XMLHttpRequest){
        xmlHttp=new XMLHttpRequest();
      }
      else{
        xmlHttp=new ActiveXObject("Microsoft.XMLHTTP");
      }
      return xmlHttp;
    }

    function ButtonPress0() {
      var xhttp = new XMLHttpRequest(); 
      var message;
      xhttp.open("PUT", "BUTTON_0", false);
      xhttp.send();
    }

    function ButtonPress1() {
      var xhttp = new XMLHttpRequest(); 
      xhttp.open("PUT", "BUTTON_1", false);
      xhttp.send(); 
    }
      
    function ButtonPress2() {
      var xhttp = new XMLHttpRequest(); 
      xhttp.open("PUT", "BUTTON_2", false);
      xhttp.send(); 
    }

    function ButtonPress3() {
      var xhttp = new XMLHttpRequest(); 
      xhttp.open("PUT", "BUTTON_3", false);
      xhttp.send(); 
    }

    function ButtonPress4() {
      var xhttp = new XMLHttpRequest(); 
      xhttp.open("PUT", "BUTTON_4", false);
      xhttp.send(); 
    }

    function ButtonPress5() {
      var xhttp = new XMLHttpRequest(); 
      xhttp.open("PUT", "BUTTON_5", false);
      xhttp.send(); 
    }

    function ButtonPress6() {
      var xhttp = new XMLHttpRequest(); 
      xhttp.open("PUT", "BUTTON_6", false);
      xhttp.send(); 
    }

    function ButtonPress7() {
      var xhttp = new XMLHttpRequest(); 
      xhttp.open("PUT", "BUTTON_7", false);
      xhttp.send(); 
    }

    function response(){
      var message;
      var barwidth;
      var currentsensor;
      var xmlResponse;
      var xmldoc;
      var dt = new Date();
      var color = "#e8e8e8";
     
      // get the xml stream
      xmlResponse=xmlHttp.responseXML;
  
      // get host date and time
      document.getElementById("time").innerHTML = dt.toLocaleTimeString();
      document.getElementById("date").innerHTML = dt.toLocaleDateString();
  
      // A0
      xmldoc = xmlResponse.getElementsByTagName("B0"); //bits for A0
      message = xmldoc[0].firstChild.nodeValue;
      
      if (message > 2048){
      color = "#aa0000";
      }
      else {
        color = "#0000aa";
      }
      
      barwidth = message / 40.95;
      document.getElementById("b0").innerHTML=message;
      document.getElementById("b0").style.width=(barwidth+"%");
      // if you want to use global color set above in <style> section
      // other wise uncomment and let the value dictate the color
      //document.getElementById("b0").style.backgroundColor=color;
      //document.getElementById("b0").style.borderRadius="5px";
      
      xmldoc = xmlResponse.getElementsByTagName("V0"); //volts for A0
      message = xmldoc[0].firstChild.nodeValue;
      document.getElementById("v0").innerHTML=message;
      document.getElementById("v0").style.width=(barwidth+"%");
      // you can set color dynamically, maybe blue below a value, red above
      document.getElementById("v0").style.backgroundColor=color;
      //document.getElementById("v0").style.borderRadius="5px";
  
      // A1
      xmldoc = xmlResponse.getElementsByTagName("B1");
      message = xmldoc[0].firstChild.nodeValue;
      if (message > 2048){
      color = "#aa0000";
      }
      else {
        color = "#0000aa";
      }
      document.getElementById("b1").innerHTML=message;
      width = message / 40.95;
      document.getElementById("b1").style.width=(width+"%");
      document.getElementById("b1").style.backgroundColor=color;
      //document.getElementById("b1").style.borderRadius="5px";
      
      xmldoc = xmlResponse.getElementsByTagName("V1");
      message = xmldoc[0].firstChild.nodeValue;
      document.getElementById("v1").innerHTML=message;
      document.getElementById("v1").style.width=(width+"%");
      document.getElementById("v1").style.backgroundColor=color;
      //document.getElementById("v1").style.borderRadius="5px";
  
      xmldoc = xmlResponse.getElementsByTagName("LED");
      message = xmldoc[0].firstChild.nodeValue;
  
      if (message == 0){
        document.getElementById("btn0").innerHTML="Turn ON";
      }
      else{
        document.getElementById("btn0").innerHTML="Turn OFF";
      }
         
      xmldoc = xmlResponse.getElementsByTagName("SWITCH");
      message = xmldoc[0].firstChild.nodeValue;
      document.getElementById("switch").style.backgroundColor="rgb(200,200,200)";
      // update the text in the table
      if (message == 0){
        document.getElementById("switch").innerHTML="Switch is OFF";
        document.getElementById("btn1").innerHTML="Turn ON";
        document.getElementById("switch").style.color="#0000AA"; 
      }
      else {
        document.getElementById("switch").innerHTML="Switch is ON";
        document.getElementById("btn1").innerHTML="Turn OFF";
        document.getElementById("switch").style.color="#00AA00";
      }
     }
  
    // general processing code for the web page to ask for an XML steam
    // this is actually why you need to keep sending data to the page to 
    // force this call with stuff like this
    // server.on("/xml", SendXML);
    // otherwise the page will not request XML from the ESP, and updates will not happen
    function process(){
     
     if(xmlHttp.readyState==0 || xmlHttp.readyState==4) {
        xmlHttp.open("PUT","xml",true);
        xmlHttp.onreadystatechange=response;
        xmlHttp.send(null);
      }       
        // you may have to play with this value, big pages need more porcessing time, and hence
        // a longer timeout
        setTimeout("process()",100);
    }
  
  
  </script>

</html>

)=====";

const char js[] PROGMEM = R"=====(
var Socket;
var wiFiMODE = 0;
var autoOff = 0;
document.addEventListener('DOMContentLoaded', init, false);
function init(){

  Socket = new WebSocket('ws://'+window.location.hostname+':81/');
  Socket.onmessage = function(event){
    console.log(event.data);
  }
  var xhr = new XMLHttpRequest();
  xhr.onreadystatechange = function(){
    if(this.readyState == 4 && this.status == 200){
      var jsonResponse = JSON.parse(this.responseText);
      wiFiMODE = jsonResponse.wiFiMODE;
      autoOff = jsonResponse.autoOff;
      doc("wiFiMODE").checked = (wiFiMODE == 0)? false : true;
      doc("autoOff").checked = (autoOff == 0)? false :  true;
    }
  }
  xhr.open("GET", "/hello", true);
  xhr.send();
}

function er(msg){
  console.log(msg);
}
function _send(head, data){
  Socket.send(head+data);
}

function doc(id){
  return document.getElementById(id);
}
//settings
doc("flag_settings").addEventListener('click', function(){
  doc("controller").style.display = (this.checked)? 'none': 'table';
  doc("settings").style.display = (this.checked)? 'table': 'none';
});
//wiFiMODE
doc("wiFiMODE").addEventListener('click', function(){
  _send("Ww",(this.checked)?1:0);
});
//autoOff
doc("autoOff").addEventListener('click', function(){
  _send("Wa", (this.checked)?1:0);
});
//Restart
doc("restart").addEventListener('click', function(){
  _send("Wr", "");
});
//AP Mode password
doc("AP_submit").addEventListener('click', function(e){
  e.preventDefault();
  var _ssid = doc("AP_SSID").value;
  var _pass = doc("AP_PASS").value;
  const regex = /^[A-Za-z0-9]+$/g;
  if(regex.test(_ssid) && _ssid.length >= 8 && _ssid.length <= 20 && _pass.length>=8 && _pass.length<=20){
    _send("Wss", _ssid);
    _send("Wsp", _pass);
    doc("AP_er").innerHTML = "";
  }else{
    doc("AP_er").innerHTML = "Invalid SSID or Password";
  }
  doc("AP_SSID").value = "";
  doc("AP_PASS").value = "";
});
doc('forward').addEventListener('touchstart', buttonPress);
doc('backward').addEventListener('touchstart', buttonPress);
doc('left').addEventListener('touchstart', buttonPress);
doc('right').addEventListener('touchstart', buttonPress);
doc('stop').addEventListener('touchstart', buttonPress);

doc('forward').addEventListener('mousedown', buttonPress);
doc('backward').addEventListener('mousedown', buttonPress);
doc('left').addEventListener('mousedown', buttonPress);
doc('right').addEventListener('mousedown', buttonPress);
doc('stop').addEventListener('mousedown', buttonPress);

function buttonPress(){
  _send(this.id[0], 1);
}

doc('forward').addEventListener('touchend', buttonRelease);
doc('backward').addEventListener('touchend', buttonRelease);
doc('left').addEventListener('touchend', buttonRelease);
doc('right').addEventListener('touchend', buttonRelease);
doc('stop').addEventListener('touchend', buttonRelease);

doc('forward').addEventListener('mouseup', buttonRelease);
doc('backward').addEventListener('mouseup', buttonRelease);
doc('left').addEventListener('mouseup', buttonRelease);
doc('right').addEventListener('mouseup', buttonRelease);
doc('stop').addEventListener('mouseup', buttonRelease);
document.addEventListener('mouseup', function(){
  _send('s', 0);
});

function buttonRelease(){
  _send(this.id[0], 0);
}

doc('range').addEventListener('input', function(){
  doc('rangeVal').innerHTML = this.value;
  _send('v', this.value);
});

)=====";